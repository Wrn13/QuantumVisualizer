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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QGraphicsView *DrawArea;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *PotentialGroup;
    QHBoxLayout *PotentialSpecifications;
    QLabel *PotentialName;
    QTextEdit *PotentialValue;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnSubmit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuantumVisualizer)
    {
        if (QuantumVisualizer->objectName().isEmpty())
            QuantumVisualizer->setObjectName(QString::fromUtf8("QuantumVisualizer"));
        QuantumVisualizer->resize(1920, 1078);
        centralWidget = new QWidget(QuantumVisualizer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        DrawArea = new QGraphicsView(centralWidget);
        DrawArea->setObjectName(QString::fromUtf8("DrawArea"));

        horizontalLayout->addWidget(DrawArea);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        PotentialGroup = new QVBoxLayout();
        PotentialGroup->setObjectName(QString::fromUtf8("PotentialGroup"));
        PotentialGroup->setContentsMargins(0, -1, -1, -1);
        PotentialSpecifications = new QHBoxLayout();
        PotentialSpecifications->setObjectName(QString::fromUtf8("PotentialSpecifications"));
        PotentialSpecifications->setContentsMargins(0, -1, -1, 900);
        PotentialName = new QLabel(centralWidget);
        PotentialName->setObjectName(QString::fromUtf8("PotentialName"));

        PotentialSpecifications->addWidget(PotentialName);

        PotentialValue = new QTextEdit(centralWidget);
        PotentialValue->setObjectName(QString::fromUtf8("PotentialValue"));

        PotentialSpecifications->addWidget(PotentialValue);


        PotentialGroup->addLayout(PotentialSpecifications);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PotentialGroup->addItem(horizontalSpacer);

        BtnSubmit = new QPushButton(centralWidget);
        BtnSubmit->setObjectName(QString::fromUtf8("BtnSubmit"));

        PotentialGroup->addWidget(BtnSubmit);


        horizontalLayout->addLayout(PotentialGroup);

        QuantumVisualizer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuantumVisualizer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 22));
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
        PotentialName->setText(QCoreApplication::translate("QuantumVisualizer", "TextLabel", nullptr));
        BtnSubmit->setText(QCoreApplication::translate("QuantumVisualizer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuantumVisualizer: public Ui_QuantumVisualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTUMVISUALIZER_H
