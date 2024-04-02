
#ifndef POTENTIALSPECIFICATIONS_H
#define POTENTIALSPECIFICATIONS_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
    class PotentialSpecifications;
}

class PotentialSpecifications : public QVBoxLayout
{
    Q_OBJECT

public:
    explicit PotentialSpecifications(QWidget *parent = nullptr);
    ~PotentialSpecifications() override;

private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
};

#endif // QUANTUMVISUALIZER_H
