#ifndef VISITORLISTVIEW_H
#define VISITORLISTVIEW_H

#include <QWidget>
#include "QXmppClient.h"
#include "QtCore"
#include "visitor.h"
#include "QStandardItemModel"

namespace Ui {
class VisitorListView;
}

class VisitorListView : public QWidget
{
    Q_OBJECT

public:
    explicit VisitorListView(QWidget *parent = 0);
    ~VisitorListView();

public slots:
    void Connected();
    void ErrorMessage(QXmppClient::Error error);
    void NewVisitors(QVector<Visitor>* visitors);

private slots:
    void doubleClicked(QModelIndex index);

signals:
    void OpenChat(QString visitorId);

private:
    Ui::VisitorListView *ui;
    QVector<Visitor>* items;
    QSet<QString>* visitorsIds;
    QStandardItemModel* model;
};

#endif // VISITORLISTVIEW_H
