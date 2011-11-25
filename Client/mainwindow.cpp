#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include <QList>
#include <QtNetwork>
#include <json_spirit.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QTableView *table = ui->tableView;

    QStandardItemModel *model = new QStandardItemModel();

    lista = new QList<QStandardItem*>();


    socket = new QTcpSocket(this);


    connect(fetchButton, SIGNAL(clicked()), this, SLOT(requestServers()));

    connect(socket, SIGNAL(readyRead()), this, SLOT(readServers()));

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

    lista->append(new QStandardItem("Yksi"));
    lista->append(new QStandardItem("kaksi"));

    model->appendRow(*lista);
    model->appendRow(new QStandardItem("kaksi"));
    model->appendRow(*lista);

    table->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: init_network() {
    socket = new QTcpSocket();
}
