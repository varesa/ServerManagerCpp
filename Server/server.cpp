/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtNetwork>

#include <iostream>
#include <string>

#include <stdlib.h>
#include <iostream>

#define JSON_SPIRIT_VALUE_ENABLED
#define JSON_SPIRIT_MVALUE_ENABLED

#include <json_spirit.h>
//#include "json_spirit_writer.h"

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "servermanager"
#define PASSWORD "servermanager"
#define DATABASE "servers"

#include "server.h"


#ifndef JSON_SPIRIT_MVALUE_ENABLED
#error Please define JSON_SPIRIT_MVALUE_ENABLED for the mValue type to be enabled
#endif

using namespace std;
using namespace json_spirit;

//using json_spirit::Object;
//using json_spirit::Array;;
//using json_spirit::Pair;

struct thing {
    string name;
    int number;
};


Server::Server(QWidget *parent)
    :   QDialog(parent), tcpServer(0), networkSession(0)
{
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Sulje"));
    quitButton->setAutoDefault(false);

    sessionOpened();

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendFortune()));


    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Palvelin"));
}

void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any,5656)) {
        QMessageBox::critical(this, tr("Palvelin"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    statusLabel->setText(tr("Port: %1").arg(tcpServer->serverPort()));
}

void Server::sendFortune()
{

    statusLabel->setText("Connected");

    thing field;
    field.name="abc";
    field.number=321;
    thing field2;
    field2.name="aasdbc";
    field2.number=32541;

    Array arr;

    Object fld;
    fld.push_back( Pair( "nme",field.name ) );
    fld.push_back( Pair( "nmuber",field.number ) );

    Object fld2;
    fld2.push_back( Pair( "nme",field2.name ) );
    fld2.push_back( Pair( "nmuber",field2.number ) );

    arr.push_back(fld);
    arr.push_back(fld2);

    string str;
    str = write_formatted(arr);

    QString *qstr = new QString(str.c_str());

//    statusLabel->setText(*qstr);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << (quint16)0;
//    out << fortunes.at(qrand() % fortunes.size());
    out << *qstr;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    statusLabel->setText("Ready to send");

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
    statusLabel->setText(*qstr);
}
