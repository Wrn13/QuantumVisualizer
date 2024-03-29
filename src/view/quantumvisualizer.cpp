#include "quantumvisualizer.h"
#include "ui_quantumvisualizer.h"

QuantumVisualizer::QuantumVisualizer(QWidget *parent):
    QMainWindow(parent), m_ui(new Ui::QuantumVisualizer)
{
    m_ui->setupUi(this);
}

QuantumVisualizer::~QuantumVisualizer() = default;

#include "moc_quantumvisualizer.cpp"
