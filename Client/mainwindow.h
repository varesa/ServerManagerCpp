#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtNetwork>
//#include <QList>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void requestServers();
	void readServers();
    void updateScreen();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStandardItemModel *model;
    QList<QStandardItem*> *lista;

    void init_network();

};

#endif // MAINWINDOW_H
