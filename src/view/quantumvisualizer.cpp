#include "quantumvisualizer.h"
#include "../model/Potential.h"
#include "ui_quantumvisualizer.h"
#include "../model/Hamiltonian.h"
#include "../controller/GnuplotPipe.h"
#include <iomanip>
#include <unistd.h>
/**
 *  Initialize all objects
 */
QuantumVisualizer::QuantumVisualizer(QWidget *parent):
    QMainWindow(parent), m_ui(new Ui::QuantumVisualizer)
{
    //Generate UI Classes
    m_ui->setupUi(this);

    //Initialize various parts of the UI
    this->setMouseTracking(true);
    centralWidget = m_ui->centralWidget;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,SCENE_DIMENSION,SCENE_DIMENSION);
    potentialSpecifications = m_ui -> PotentialSpecifications;
    btnSubmit = m_ui -> BtnSubmit;
    drawView = m_ui -> DrawView;
    mainToolBar = m_ui -> mainToolBar;
    menuBar = m_ui ->menuBar;
    statusBar = m_ui -> statusBar;
    
    //Set the Graphics Scene/View and Pen
    drawView ->setScene(scene);
    outlinePen = new QPen("black");
    outlinePen->setWidth(2);
    
    //Initialize potential selected
    selectedPotential = -1;
}

void QuantumVisualizer:: addPotentialBox(){
    //Set brush color and pen
    QBrush colorBrush (INT_TO_COLOR[selectedPotential]);

    
    /*  #TODO: If extra time, enable variable size rectangles
    vector<double> pointList;
    generatePointList(pointList);
    QGraphicsPolygonItem polygon1 = scene->addPolygon ;
    */

    //Construct rectangle and label
    QGraphicsRectItem * rectangle1;
    QGraphicsSimpleTextItem * rect1Text;
    rectangle1 = scene->addRect(0,0,100,100, *outlinePen, colorBrush);
    rect1Text = scene->addSimpleText(QString::number(selectedPotential));
    
   /*
    QList<QGraphicsItem *> group;
    group.append(rectangle1);
    group.append(rect1Text);
    */
    //Group them together and set flags
    rect1Text->setParentItem(rectangle1);
    rectangle1->setFlag(QGraphicsItem::ItemIsMovable);
    potentialBox.push_back(rectangle1);
    /*
    QGraphicsItemGroup * rectangleGroup = scene -> createItemGroup(group);
    rectangleGroup->setFlag(QGraphicsItem::ItemIsMovable);
    rectangleGroup->setFlag(QGraphicsItem::ItemIsFocusable);
    rectangleGroup ->setFlag(QGraphicsItem::ItemIsSelectable);
    */

    //Create potential textbox for value
    QTextEdit * PotentialValue2 = new QTextEdit();
    
    //Create label
    char potentialLabel [15];
    sprintf(potentialLabel, "&Potential %d", selectedPotential);
    
    //Add potential to the form layout
    potentialSpecifications->addRow(tr(potentialLabel), PotentialValue2);

    //Select last potential
    selectedPotential = potentialBox.size()-1;
    potentialCount++;
}

QuantumVisualizer::~QuantumVisualizer(){
    delete scene;
}

/**
 *  Add another potential box to the potential.
 */
void QuantumVisualizer:: update(){
    selectedPotential = potentialBox.size();
    addPotentialBox();
}


/**
 *  Quick helper function to bound the scene rectangles.
 */
void bound(double &x, int max){
    if (x<0){
        x=0;
    }else if(x>=max){
        x=max;
    }
}

/**
 *  Slot that generates the wavefunction.
 */
void QuantumVisualizer :: hide(){
    //Get the potential values from the form layout one by one.
    //TODO: Add sanitization on inputs.
    while(potentialSpecifications->rowCount()){
        auto result = potentialSpecifications->takeRow(0).fieldItem->widget();
        std::cout<<"Entered: " <<((QTextEdit*)result) -> toPlainText().toDouble()<<"\n";
        potentialPeaks.push_back(((QTextEdit*)result) -> toPlainText().toDouble());
    }

    /*
     * TODO: Allow variable sized potentials.
     */

    //Create the potential matrix. For now, take scene coordinates and divide by 10.
    Potential p(90);
    double x1,x2,y1,y2;
    for(int i = 0; i<potentialCount; ++i){

        //TODO: Allow different shapes with Polygons
        //Grab position of the potential box, calculate the endpoints using width.
        auto point = potentialBox[i]->pos();
        x1 = point.x();
        y1= point.y();
        x2 = x1+100;
        y2= y1+100;
        
        //Bound each coordinate to avoid IndexOutOfBoundsExceptions. Truncate all data outside boundary
        bound(x1, SCENE_DIMENSION);
        bound(x2, SCENE_DIMENSION);
        bound(y1, SCENE_DIMENSION);
        bound(y1, SCENE_DIMENSION);

        //std::cout<<std::setprecision(3)<<"Coords: x1: " << x1 <<" x2: " << x2 <<" y1: " << y1 <<" y2: " << y2 <<"\n";
        
        //Add peak to potential matrix
        p.addPeak(floor(x1/10),floor(x2/10),floor(y1/10),floor(y2/10), potentialPeaks[i]);
    }
    std::cout<<"Added all potentials.\n";
    //p.printPotential();
    
    //Create Hamiltonian, let delta be .1
    Hamiltonian h (p,90,1);
    //std::cout<<"Hamiltonian:\n";
    //h.printHamiltonian();

    //Diagonalize Hamiltonian
    h.diagonalize();
    std::cout<<"Diagonalized Hamiltonian\n";

    //Generate output file, printing the ground state
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Data File"), "", tr("Data Files (*.dat)"));
    h.output(0, fileName.toStdString());

    //Pipe output into Gnuplot
    auto gnuplotTerm = GnuplotPipe();
    gnuplotTerm.set_title("Ground State Wavefunction");
    gnuplotTerm.set_xlabel("x");
    gnuplotTerm.set_ylabel("y");
    gnuplotTerm.set_title("psi(x,y)");
    gnuplotTerm.set_filename(fileName.toStdString().c_str());

    //Open plot and wait before closing the application.
    gnuplotTerm.init();
    sleep(30);
    
    this->close();

}
#include "moc_quantumvisualizer.cpp"
