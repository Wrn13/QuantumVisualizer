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
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
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
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, 900);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

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
        label->setText(QCoreApplication::translate("QuantumVisualizer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
class QuantumVisualizer: public Ui_QuantumVisualizer {private slots:
    void on_textEdit_textChanged();
    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTUMVISUALIZER_H
