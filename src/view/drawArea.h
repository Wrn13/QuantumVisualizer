#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsView>
#include <QScopedPointer>
#include <QMouseEvent>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QGraphicsView
{
    Q_OBJECT

public:
    explicit DrawArea(QWidget *parent = nullptr);
    ~DrawArea() override;
    void setPotentialOption(int);
    int selectedPotential();

    bool isModified() const {return modified;}

public slots:
    void clearPotential ();
    void display();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void paintEvent();
private:
    bool modified;
};

#endif // QUANTUMVISUALIZER_H
