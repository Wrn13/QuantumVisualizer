/********************************************************************************
** Form generated from reading UI file 'quantumvisualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUANTUMVISUALIZER_H
#define UI_QUANTUMVISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuantumVisualizer
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *DrawArea;
    QVBoxLayout *PotentialSpecifications;
    QTextEdit *PotentialDefinition;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuantumVisualizer)
    {
        if (QuantumVisualizer->objectName().isEmpty())
            QuantumVisualizer->setObjectName(QString::fromUtf8("QuantumVisualizer"));
        QuantumVisualizer->resize(1920, 1080);
        centralWidget = new QWidget(QuantumVisualizer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        DrawArea = new QWidget(centralWidget);
        DrawArea->setObjectName(QString::fromUtf8("DrawArea"));
        DrawArea->setGeometry(QRect(0, 0, 1000, 1000));

        horizontalLayout->addWidget(DrawArea);

        PotentialSpecifications = new QVBoxLayout();
        PotentialSpecifications->setObjectName(QString::fromUtf8("PotentialSpecifications"));
        PotentialDefinition = new QTextEdit(centralWidget);
        PotentialDefinition->setObjectName(QString::fromUtf8("PotentialDefinition"));
        PotentialDefinition->setGeometry(QRect(0, 0, 100, 100));

        PotentialSpecifications->addWidget(PotentialDefinition);


        horizontalLayout->addLayout(PotentialSpecifications);

        QuantumVisualizer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuantumVisualizer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QuantumVisualizer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuantumVisualizer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QuantumVisualizer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QuantumVisualizer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QuantumVisualizer->setStatusBar(statusBar);

        retranslateUi(QuantumVisualizer);

        QMetaObject::connectSlotsByName(QuantumVisualizer);
    } // setupUi

    void retranslateUi(QMainWindow *QuantumVisualizer)
    {
        QuantumVisualizer->setWindowTitle(QCoreApplication::translate("QuantumVisualizer", "QuantumVisualizer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuantumVisualizer: public Ui_QuantumVisualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTUMVISUALIZER_H
