#ifndef CONNECTIONHELPER_H
#define CONNECTIONHELPER_H

#include "Qt"
#include "QtCore"
#include "QXmppClient.h"
#include "visitorupdater.h"

class ConnectionHelper : public QObject
{
    Q_OBJECT

public:
    static ConnectionHelper* Instance(){
        static ConnectionHelper instance;
        return &instance;
    }

    QXmppClient* client;

    void SetLoginData(QString login, QString password);

    void Connect();
    void Disconnect();

    bool isConnected();

public slots:
    void error(QXmppClient::Error error);
    void connected();
    void disconnected();
    void iqReceived(const QXmppIq &iq);
    void messageReceived(const QXmppMessage &message);
    void presenceReceived(const QXmppPresence &presence);

signals:
    void Connected();
    void Connecting();
    void Disconnected();
    void ReceivedIq(const QXmppIq &iq);
    void ReceivedMessage(const QXmppMessage &message);
    void ReceivedPresence(const QXmppPresence &presence);
    void StartWorkers();
    void NewVisitors(QVector<Visitor>* visitors);

private:
    ConnectionHelper();
    ConnectionHelper(const ConnectionHelper& root);
    ConnectionHelper& operator=(const ConnectionHelper&);

    bool _isConnected;
    bool _isConnecting;

    QThread visitorUpdaterThread;
    VisitorUpdater* visitorUpdater;
};

#endif // CONNECTIONHELPER_H
