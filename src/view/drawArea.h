#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsView>
#include <QScopedPointer>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QGraphicsView
{
    Q_OBJECT

public:
    explicit DrawArea(QWidget *parent = nullptr);
    ~DrawArea() override;

private:

};

#endif // QUANTUMVISUALIZER_H
