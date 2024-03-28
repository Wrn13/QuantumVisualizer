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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuantumVisualizer
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuantumVisualizer)
    {
        if (QuantumVisualizer->objectName().isEmpty())
            QuantumVisualizer->setObjectName(QString::fromUtf8("QuantumVisualizer"));
        QuantumVisualizer->resize(400, 300);
        centralWidget = new QWidget(QuantumVisualizer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
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
