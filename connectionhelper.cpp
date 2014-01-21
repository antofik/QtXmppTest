#include "connectionhelper.h"
#include "QXmppClient.h"
#include "QtCore"
#include "visitorupdater.h"
#include "QMessageBox"
#include "visitor.h"

ConnectionHelper::ConnectionHelper()
{
    client = new QXmppClient();
    client->logger()->setLoggingType(QXmppLogger::StdoutLogging);

    connect(client, SIGNAL(connected()), this, SLOT(connected()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(client, SIGNAL(messageReceived(QXmppMessage)), this, SLOT(messageReceived(QXmppMessage)));
    connect(client, SIGNAL(iqReceived(QXmppIq)), this, SLOT(iqReceived(QXmppIq)));
    connect(client, SIGNAL(presenceReceived(QXmppPresence)), this, SLOT(presenceReceived(QXmppPresence)));
    connect(client, SIGNAL(error(QXmppClient::Error)), this, SLOT(error(QXmppClient::Error)));

    visitorUpdater = new VisitorUpdater();
    visitorUpdater->moveToThread(&visitorUpdaterThread);
    connect(this, SIGNAL(StartWorkers()), visitorUpdater, SLOT(doWork()));
    visitorUpdaterThread.start();
    emit StartWorkers();
}

void ConnectionHelper::Connect(){
    qDebug() << "Connecting...";

    client->connectToServer("antofik@xmpp.redhelper.ru", "@test");
}

void ConnectionHelper::Disconnect(){
    qDebug() << "Disconnecting...";

    client->disconnectFromServer();
}

bool ConnectionHelper::isConnected(){
    return client->isConnected();
}

void ConnectionHelper::error(QXmppClient::Error error){

}

void ConnectionHelper::messageReceived(const QXmppMessage &message){
    emit ReceivedMessage(message);
}

void ConnectionHelper::iqReceived(const QXmppIq &iq){
    if (iq.extensions().count()>0){
         QXmppElement element = iq.extensions().at(0);
         if (element.attribute("xmlns") == "consultant:visitorlist"){
            QVector<Visitor>* visitors = new QVector<Visitor>();
            QXmppElement visitorElement = element.firstChildElement("visitor");
            while(1==1){
                if (visitorElement.isNull()) break;
                qDebug() << "Visitor found!";
                Visitor visitor;
                visitor.Id = visitorElement.firstChildElement("vid").value();
                visitor.Jid = visitorElement.firstChildElement("jid").value();
                visitor.Name = visitorElement.firstChildElement("currentUrl").value();
                visitors->append(visitor);
                visitorElement = visitorElement.nextSiblingElement("visitor");
            }

            emit NewVisitors(visitors);
         }
    }

    emit ReceivedIq(iq);
}

void ConnectionHelper::presenceReceived(const QXmppPresence &presence){
    emit ReceivedPresence(presence);
}

void ConnectionHelper::connected(){
     emit Connected();
}

void ConnectionHelper::disconnected(){
    emit Disconnected();
}
































