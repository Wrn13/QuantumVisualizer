#include "drawArea.h"
#include <QGraphicsView>
#include "ui_quantumvisualizer.h"

DrawArea::DrawArea(QWidget *parent): QGraphicsView(parent){
}

DrawArea::~DrawArea() = default;

#include "moc_quantumvisualizer.cpp"
