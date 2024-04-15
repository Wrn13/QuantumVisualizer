#ifndef QUANTUMVISUALIZER_H
#define QUANTUMVISUALIZER_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <qt/QtCore/qglobal.h>
#include <qt/QtCore/qobjectdefs.h>
#include <qt/QtWidgets/qmainwindow.h>

namespace Ui {
    class QuantumVisualizer;
    class DrawArea;
    class PotentialSpecifications;
    class PotentialName;
    class PotentialValue;
    class CentralWidget;
    class PotentialGroup;
    class BtnSubmit;
}

class QuantumVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuantumVisualizer(QWidget *parent = nullptr);
    ~QuantumVisualizer();

private slots:
    void save();
    void update();
    void addNewPotential();

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
    QWidget *centralWidget;
    DrawArea drawArea;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
};

#endif // QUANTUMVISUALIZER_H
