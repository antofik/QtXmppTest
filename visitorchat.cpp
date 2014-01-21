#include "visitorchat.h"
#include "ui_visitorchat.h"
#include "core.h"
#include "visitor.h"
#include "QtCore"

VisitorChat::VisitorChat(QString visitorId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitorChat)
{
    ui->setupUi(this);
    //QWebSettings::enablePersistentStorage("%appdata%\\redhelper");



    QVector<Visitor> *items = Core::Visitors()->Items();
    for (int i=0;i<items->count();i++){
        if (items->at(i).Id == visitorId){
            visitor = items->at(i);
            break;
        }
    }

    connect(ui->cmdSend, SIGNAL(clicked()), this, SLOT(send()));
    connect(Core::Connection(), SIGNAL(ReceivedMessage(QXmppMessage)), this, SLOT(messageReceived(QXmppMessage)));
}

void VisitorChat::send(){
    QString text = ui->txtMessage->toPlainText();
    ui->txtChat->append("<div style='font-weight: bold; color:black;'>Operator</div>");
    ui->txtChat->append("<div style='color:black;'>" + text + "</div>");
    ui->txtChat->append(" ");

    Core::Connection()->client->sendMessage(visitor.Jid, text);
}

void VisitorChat::messageReceived(QXmppMessage message){
    qDebug() << "Message received: " << message.body();
    if (message.from() != visitor.Jid) return;

    ui->txtChat->append("<div style='font-weight: bold; color:darkblue;'>Visitor</div>");
    ui->txtChat->append("<div style='color:black;'>" + message.body() + "</div>");
    ui->txtChat->append(" ");
}

VisitorChat::~VisitorChat()
{
    delete ui;
}
