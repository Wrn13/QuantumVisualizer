#ifndef QUANTUMVISUALIZER_H
#define QUANTUMVISUALIZER_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QWidget>
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QStatusBar>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <unordered_map>
#include "../controller/Box.h"
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
    void save();
    void update();
    void addNewPotential();

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
    QWidget *centralWidget;
    QGraphicsScene * scene;
    QGraphicsView * drawView;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QPushButton *btnSubmit;
    QVBoxLayout *potentialGroup;
    QHBoxLayout *potentialSpecifications;

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

    std::vector<QGraphicsRectItem*> potentialBoxes;
    std::vector<Box> potentialList;
    std::vector<double> potentialPeaks;
};

#endif // QUANTUMVISUALIZER_H
