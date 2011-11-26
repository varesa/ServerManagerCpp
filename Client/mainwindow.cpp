#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItem>
#include <QStandardItemModel>
#include <QList>

#include <QtNetwork>

#include <QMessageBox>

#include <vector>
#include <string>

#define JSON_SPIRIT_MVALUE_ENABLED

#include <json_spirit.h>

#include "../Server/mserver.hpp"

using namespace std;
using namespace json_spirit;
using json_spirit::read;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    table = ui->tableView;
    model = new QStandardItemModel();
    lista = new QList<QStandardItem*>();

    socket = new QTcpSocket();

    connect(ui->fetchButton, SIGNAL(clicked()), this, SLOT(requestServers()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readServers()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

//    lista->append(new QStandardItem("Yksi"));
//    lista->append(new QStandardItem("kaksi"));

//    model->appendRow(*lista);
//    model->appendRow(new QStandardItem("kaksi"));
//    model->appendRow(*lista);

    table->setModel(model);
}

void MainWindow::requestServers() {

    socket->abort();
    socket->connectToHost(ui->hostEdit->text(), ui->portEdit->text().toInt());
    blocksize = 0;

}

void MainWindow::readServers() {

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blocksize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blocksize;
    }

    if (socket->bytesAvailable() < blocksize)
        return;


    QString json_string;
    in >> json_string;
    updateScreen(json_string);

}

void MainWindow::updateScreen(QString jsonString) {

    translateServers(jsonString);
    if(servers->size() > 0) {

    }

    MServer server = servers->at(0);

    model->appendRow(new QStandardItem("yksi"));
    QString qs = server.name.c_str();
    model->appendRow(new QStandardItem(qs));//    model->appendRow(*lista);

    table->setModel(model);
    model->appendRow(new QStandardItem("kolme"));

}

void MainWindow::translateServers( QString json_string )
{
    //ifstream is( file_name );

    mValue value;
    const string str = json_string.toStdString();
    json_spirit::read(str, value);

    const mArray& server_array = value.get_array();



    for( unsigned int i = 0; i < server_array.size(); ++i )
    {
        servers->push_back( readServer( server_array[i].get_obj() ) );
    }

    //return servers;
}

//int id;
//std::string name;
//std::string desc;
//std::string path;
//int port;
//bool running;
//bool locked;

MServer MainWindow::readServer(const mObject &obj) {
    MServer server;

//    server.id      = find_value( obj, "id"      ).get_int();
//    server.name    = find_value( obj, "name"    ).get_str();
//    server.desc    = find_value( obj, "desc"    ).get_str();
//    server.path    = find_value( obj, "path"    ).get_str();
//    server.port    = find_value( obj, "port"    ).get_int();
//    server.running = find_value( obj, "running" ).get_bool();
//    server.locked  = find_value( obj, "locked"  ).get_bool();

    return server;
}

const mValue& MainWindow::find_value( const mObject& obj, const string& name  )
{
    mObject::const_iterator i = obj.find( name );

    assert( i != obj.end() );
    assert( i->first == name );

    return i->second;
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            ui->statusBox->setText(tr("The host was not found. Please check the "
                                        "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            ui->statusBox->setText(tr("The connection was refused by the peer. "
                                        "Make sure the fortune server is running, "
                                        "and check that the host name and port "
                                        "settings are correct."));
            break;
        default:
            ui->statusBox->setText(tr("The following error occurred: %1.")
                                     .arg(socket->errorString()));
    }

}



