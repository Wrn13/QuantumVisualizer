#include "PotentialSpecifications.h"
#include "ui_quantumvisualizer.h"

PotentialSpecifications::PotentialSpecifications(QWidget *parent):
    QVBoxLayout(parent), m_ui(new Ui::QuantumVisualizer)
{
}

PotentialSpecifications::~PotentialSpecifications() = default;

#include "moc_quantumvisualizer.cpp"
