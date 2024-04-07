#ifndef QUANTUMVISUALIZER_H
#define QUANTUMVISUALIZER_H

#include <QMainWindow>
#include <QScopedPointer>
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
    ~QuantumVisualizer() ;

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
};

#endif // QUANTUMVISUALIZER_H
