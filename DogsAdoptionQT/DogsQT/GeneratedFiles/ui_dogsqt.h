/********************************************************************************
** Form generated from reading UI file 'dogsqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOGSQT_H
#define UI_DOGSQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DogsQTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DogsQTClass)
    {
        if (DogsQTClass->objectName().isEmpty())
            DogsQTClass->setObjectName(QStringLiteral("DogsQTClass"));
        DogsQTClass->resize(600, 400);
        menuBar = new QMenuBar(DogsQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DogsQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DogsQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DogsQTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DogsQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DogsQTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DogsQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DogsQTClass->setStatusBar(statusBar);

        retranslateUi(DogsQTClass);

        QMetaObject::connectSlotsByName(DogsQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *DogsQTClass)
    {
        DogsQTClass->setWindowTitle(QApplication::translate("DogsQTClass", "DogsQT", 0));
    } // retranslateUi

};

namespace Ui {
    class DogsQTClass: public Ui_DogsQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOGSQT_H
