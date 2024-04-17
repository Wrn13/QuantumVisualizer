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

namespace Ui {
    class QuantumVisualizer;
}

class QuantumVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuantumVisualizer(QWidget *parent = nullptr);
    ~QuantumVisualizer();
    void addPotentialBox();

private slots:
    void close();
    void update();

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
    QWidget *centralWidget;
    QGraphicsScene * scene;
    QGraphicsView * drawView;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QPushButton *btnSubmit;
    QFormLayout *potentialSpecifications;

    int potentialCount = 0;
    int selectedPotential;
    /**
     * Map to take in the selected potential index and output its color.
     */
    std::unordered_map<int, const char *>INT_TO_COLOR = {
        {0,"grey"}, {1,"red"}, {2,"orange"}, {3,"yellow"}, {4,"green"},
        {5,"blue"}, {6,"purple"}, {7,"brown"}, {8,"lightstellblue"}
    };

    QPen *outlinePen;

    std::vector<QGraphicsItemGroup*> potentialBoxes;
    std::vector<double> potentialPeaks;
};

#endif // QUANTUMVISUALIZER_H
