
#ifndef POTENTIALSPECIFICATIONS_H
#define POTENTIALSPECIFICATIONS_H

#include <QVBoxLayout>
#include <QScopedPointer>
#include "quantumvisualizer.h"

class PotentialSpecifications : public QVBoxLayout
{
    Q_OBJECT

public:
    explicit PotentialSpecifications(QWidget *parent = nullptr);
    ~PotentialSpecifications() override;
private:
    QScopedPointer<Ui::QuantumVisualizer> m_ui;
};

#endif 
