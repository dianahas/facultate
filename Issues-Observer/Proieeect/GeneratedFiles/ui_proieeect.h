/********************************************************************************
** Form generated from reading UI file 'proieeect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIEEECT_H
#define UI_PROIEEECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProieeectClass
{
public:
    QWidget *centralWidget;
    QListWidget *issuesList;
    QLabel *label;
    QLabel *label_2;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *resolveButton;
    QLineEdit *nameEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProieeectClass)
    {
        if (ProieeectClass->objectName().isEmpty())
            ProieeectClass->setObjectName(QStringLiteral("ProieeectClass"));
        ProieeectClass->resize(600, 426);
        centralWidget = new QWidget(ProieeectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        issuesList = new QListWidget(centralWidget);
        issuesList->setObjectName(QStringLiteral("issuesList"));
        issuesList->setGeometry(QRect(90, 20, 411, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 0, 55, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 250, 71, 16));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(70, 300, 93, 28));
        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(220, 300, 93, 28));
        resolveButton = new QPushButton(centralWidget);
        resolveButton->setObjectName(QStringLiteral("resolveButton"));
        resolveButton->setGeometry(QRect(370, 300, 93, 28));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(150, 250, 221, 22));
        ProieeectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProieeectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        ProieeectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProieeectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProieeectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProieeectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProieeectClass->setStatusBar(statusBar);

        retranslateUi(ProieeectClass);

        QMetaObject::connectSlotsByName(ProieeectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProieeectClass)
    {
        ProieeectClass->setWindowTitle(QApplication::translate("ProieeectClass", "Proieeect", 0));
        label->setText(QApplication::translate("ProieeectClass", "Issues", 0));
        label_2->setText(QApplication::translate("ProieeectClass", "Description", 0));
        addButton->setText(QApplication::translate("ProieeectClass", "Report", 0));
        removeButton->setText(QApplication::translate("ProieeectClass", "Remove", 0));
        resolveButton->setText(QApplication::translate("ProieeectClass", "Resolve", 0));
    } // retranslateUi

};

namespace Ui {
    class ProieeectClass: public Ui_ProieeectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIEEECT_H
