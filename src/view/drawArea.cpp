#include "drawArea.h"
#include <QGraphicsView>
#include "ui_quantumvisualizer.h"

DrawArea::DrawArea(QWidget *parent): QGraphicsView(parent), m_ui(new Ui::DrawArea){
    m_ui->setOutput(this);
}

DrawArea::~DrawArea() = default;

#include "moc_quantumvisualizer.cpp"
