#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtNetwork>
//#include <QList>

#include <vector>

#include <json_spirit.h>
#include "../Server/mserver.hpp"

using namespace std;
using namespace json_spirit;

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

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStandardItemModel *model;
    QList<QStandardItem*> *lista;

    qint16 blocksize;

//    void init_network();
    void updateScreen(QString jsonString);

    vector< MServer > translateServers(QString jsonString);
    MServer readServer(const Object& obj);
    const mValue& find_value( const mObject& obj, const string& name  );

};

#endif // MAINWINDOW_H
