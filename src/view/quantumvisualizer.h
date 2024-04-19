#ifndef QUANTUMVISUALIZER_H
#define QUANTUMVISUALIZER_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
#include <QRectF>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QFileDialog>
#include <QPolygonF>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <sstream>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <qt/QtCore/qglobal.h>
#include <qt/QtCore/qobjectdefs.h>
#include <qt/QtWidgets/qmainwindow.h>

/**
 *  Namespace holding ui stuff from compiled codes.
 */
namespace Ui {
    class QuantumVisualizer;
}

/**
 * Main application class
 */
class QuantumVisualizer : public QMainWindow
{
    //Macro for Qt Stuff
    Q_OBJECT

public:
    /**
     * Creates an application with no parent.
     */
    explicit QuantumVisualizer(QWidget *parent = nullptr);
    //Destructor
    ~QuantumVisualizer();
    /**
     * Adds another potential peak to the potential.
     */
    void addPotentialBox();

    /**
     * Constant for the size of the Graphics Scene in Scene Coordinates.
     */
    const double SCENE_DIMENSION = 900;

    /**
     *  Event handlers overriden for use. Signals connected via UI file
     */
private slots:
    void hide();
    void update();


private:
    //Fields for each of the UI elements
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
    QWidget *centralWidget;
    QGraphicsScene * scene;
    QGraphicsView * drawView;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QPushButton *btnSubmit;
    QFormLayout *potentialSpecifications;

    //Number of potentials
    int potentialCount = 0;
    //Selected potential
    int selectedPotential;
    /**
     * Map to take in the selected potential index and output its color.
     */
    std::unordered_map<int, const char *>INT_TO_COLOR = {
        {0,"grey"}, {1,"red"}, {2,"orange"}, {3,"yellow"}, {4,"green"},
        {5,"blue"}, {6,"purple"}, {7,"brown"}, {8,"lightsteelblue"}, {9,"pink"}
    };

    /**
     *  Pen to outline the rectanglular peaks.
     */
    QPen *outlinePen;

    /**
     * Stores a pointer to each potential peak on the graphics scene.
     */
    std::vector<QGraphicsRectItem*> potentialBox;
    /**
     *  Stores the values of each peak.
     */
    std::vector<double> potentialPeaks;
};

#endif // QUANTUMVISUALIZER_H
