/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Nov 26 23:38:23 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAsetukset;
    QAction *actionLopeta;
    QWidget *centralWidget;
    QLineEdit *portEdit;
    QLineEdit *hostEdit;
    QPushButton *fetchButton;
    QTextEdit *statusBox;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(431, 427);
        actionAsetukset = new QAction(MainWindow);
        actionAsetukset->setObjectName(QString::fromUtf8("actionAsetukset"));
        actionLopeta = new QAction(MainWindow);
        actionLopeta->setObjectName(QString::fromUtf8("actionLopeta"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        portEdit = new QLineEdit(centralWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setGeometry(QRect(10, 40, 113, 20));
        hostEdit = new QLineEdit(centralWidget);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));
        hostEdit->setGeometry(QRect(10, 10, 113, 20));
        fetchButton = new QPushButton(centralWidget);
        fetchButton->setObjectName(QString::fromUtf8("fetchButton"));
        fetchButton->setGeometry(QRect(130, 10, 71, 51));
        statusBox = new QTextEdit(centralWidget);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));
        statusBox->setGeometry(QRect(220, 10, 201, 51));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 70, 411, 291));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 431, 23));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAsetukset);
        menuMenu->addAction(actionLopeta);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAsetukset->setText(QApplication::translate("MainWindow", "Asetukset", 0, QApplication::UnicodeUTF8));
        actionLopeta->setText(QApplication::translate("MainWindow", "Lopeta", 0, QApplication::UnicodeUTF8));
        portEdit->setText(QApplication::translate("MainWindow", "5656", 0, QApplication::UnicodeUTF8));
        hostEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        fetchButton->setText(QApplication::translate("MainWindow", "Yhdist\303\244", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
