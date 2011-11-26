#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QtNetwork>
//#include <QList>

#include <vector>

#include <json_spirit.h>
#include "../Server/mserver.hpp"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() {}

private slots:
    void requestServers();
    void readServers();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    std::vector< MServer > *servers;

    Ui::MainWindow *ui;
    QTcpSocket *socket;

    //Table:
    QStandardItemModel *model;
    QList<QStandardItem*> *lista;
    QTableView *table;

    qint16 blocksize;

//    void init_network();
    void updateScreen(QString jsonString);

    void translateServers(QString jsonString);
    MServer readServer(const json_spirit::mObject& obj);
    const json_spirit::mValue& find_value( const json_spirit::mObject& obj, const std::string& name  );

};

#endif // MAINWINDOW_H
