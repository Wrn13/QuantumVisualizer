#include "view/quantumvisualizer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QuantumVisualizer w;
    w.show();

    return app.exec();
}
