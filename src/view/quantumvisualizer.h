#ifndef QUANTUMVISUALIZER_H
#define QUANTUMVISUALIZER_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class QuantumVisualizer;
}

class QuantumVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuantumVisualizer(QWidget *parent = nullptr);
    ~QuantumVisualizer() override;

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
};

#endif // QUANTUMVISUALIZER_H
