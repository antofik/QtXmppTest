#include "visitorlistview.h"
#include "ui_visitorlistview.h"
#include <QtCore>
#include <QtGlobal>
#include <QStandardItemModel>
#include <QStandardItem>
#include "core.h"
#include "QXmppClient.h"
#include "QXmppLogger.h"

VisitorListView::VisitorListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitorListView)
{
    ui->setupUi(this);

    model = new QStandardItemModel();
    visitorsIds = new QSet<QString>();
    model->setHorizontalHeaderLabels(QString("Id;Name").split(";"));

    ui->table->setModel(model);
    ui->table->setColumnWidth(0, 100);
    ui->table->setColumnWidth(1, 300);

    connect(ui->table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicked(QModelIndex)));
    connect(Core::Connection(), SIGNAL(NewVisitors(QVector<Visitor>*)), this, SLOT(NewVisitors(QVector<Visitor>*)));
}

void VisitorListView::Connected(){
    qDebug() << "Connected!!!!!!!";
}

void VisitorListView::NewVisitors(QVector<Visitor> *visitors){
    QStandardItem* item;
    int count = model->rowCount();
    for(int i=0;i<visitors->count();i++){
        Visitor v = visitors->at(i);
        if (visitorsIds->contains(v.Id)) continue;

        Core::Visitors()->Items()->append(v);
        visitorsIds->insert(v.Id);
        item = new QStandardItem(v.Id);
        item->setData(v.Id);
        item->setEditable(false);
        model->setItem(count, 0, item);
        item = new QStandardItem(v.Name);
        item->setData(v.Id);
        item->setEditable(false);
        model->setItem(count, 1, item);

        count++;
    }
}

void VisitorListView::doubleClicked(QModelIndex index){
    int row = index.row();
    QStandardItem* item = model->itemFromIndex(index);
    QString visitorId = item->data().value<QString>();
    emit OpenChat(visitorId);
}

void VisitorListView::ErrorMessage(QXmppClient::Error error){
    qDebug() << "Xmpp error:" << error;
}

VisitorListView::~VisitorListView()
{
    delete ui;
}
