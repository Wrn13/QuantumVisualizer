#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QScopedPointer>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QWidget
{
    Q_OBJECT

public:
    explicit DrawArea(QWidget *parent = nullptr);
    ~DrawArea() override;

private:

};

#endif // QUANTUMVISUALIZER_H
