#include "quantumvisualizer.h"
#include "../model/Potential.h"
#include "ui_quantumvisualizer.h"
#include "../model/Hamiltonian.h"
/**
 *  Initialize all objects
 */
QuantumVisualizer::QuantumVisualizer(QWidget *parent):
    QMainWindow(parent), m_ui(new Ui::QuantumVisualizer)
{
    m_ui->setupUi(this);
    centralWidget = m_ui->centralWidget;
    scene = new QGraphicsScene(this);
    potentialSpecifications = m_ui -> PotentialSpecifications;
    potentialGroup = m_ui -> PotentialGroup;
    btnSubmit = m_ui -> BtnSubmit;
    drawView = m_ui -> DrawView;
    mainToolBar = m_ui -> mainToolBar;
    menuBar = m_ui ->menuBar;
    statusBar = m_ui -> statusBar;
    
    drawView ->setScene(scene);
    outlinePen = new QPen("black");
    outlinePen->setWidth(2);
    
    selectedPotential = 0;
    addPotentialBox();
}

void QuantumVisualizer:: addPotentialBox(){
    //Set brush color and pen
    QBrush colorBrush (INT_TO_COLOR[selectedPotential]);

    QGraphicsRectItem * rectangle1;
    rectangle1 = scene->addRect(0,0,100,100, *outlinePen, colorBrush);

    rectangle1->setFlag(QGraphicsItem::ItemIsMovable);
    potentialBoxes.push_back(rectangle1);

}

QuantumVisualizer::~QuantumVisualizer(){

}
void QuantumVisualizer:: save(){


}
void QuantumVisualizer:: update(){
    /*
    Potential p;

    for(int i = 0; i<potentialList.size(); ++i){
        p.addPeak(potentialList[i], potentialPeaks[i]);
    }

    Hamiltonian h (p,10,.1);
    */
    std::cout <<" GOT TO UPDATE SLOT!!!!\n";
    
}

void QuantumVisualizer:: addNewPotential(){


}
#include "moc_quantumvisualizer.cpp"
