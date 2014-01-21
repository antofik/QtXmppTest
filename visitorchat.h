#ifndef VISITORCHAT_H
#define VISITORCHAT_H

#include <QWidget>
#include "visitor.h"
#include "QXmppMessage.h"

namespace Ui {
class VisitorChat;
}

class VisitorChat : public QWidget
{
    Q_OBJECT

public:
    explicit VisitorChat(QString visitorId, QWidget *parent = 0);
    ~VisitorChat();

private slots:
    void send();
    void messageReceived(QXmppMessage message);

private:
    Ui::VisitorChat *ui;
    Visitor visitor;
};

#endif // VISITORCHAT_H
