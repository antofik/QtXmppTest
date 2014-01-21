#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include "visitorlistview.h"
#include "stdio.h"
#include <QtGui>
#include <QtCore>
#include "core.h"
#include "visitorchat.h"
#include "QWebSettings"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainMenu* m = new MainMenu();
    ui->containerMainMenu->layout()->addWidget(m);

    connect(m, SIGNAL(CreateNewTab()), this, SLOT(CreateNewTab()));

    VisitorListView *visitorListView = new VisitorListView();
    connect(visitorListView, SIGNAL(OpenChat(QString)), this, SLOT(OpenChat(QString)));
    ui->tabVisitorList->layout()->addWidget(visitorListView);
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->tabBar()->tabButton(0, QTabBar::RightSide)->hide();
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequested(int)));

    connect(Core::Connection(), SIGNAL(Connected()), SLOT(Connected()));
    connect(Core::Connection(), SIGNAL(Disconnected()), SLOT(Disconnected()));

    if (Core::Connection()->isConnected()){
        ui->txtStatus->setText("Already connected");
    }

    Core::Connection()->Connect();

    QWebSettings::enablePersistentStorage("x:\\");
    //QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}

void MainWindow::CreateNewTab(){
    this->ui->tabWidget->addTab(new QWidget(), QUuid::createUuid().toString());
}

void MainWindow::tabCloseRequested(int tabIndex){
    this->ui->tabWidget->removeTab(tabIndex);
}

void MainWindow::Connected(){
    ui->txtStatus->setText("Connected");
}

void MainWindow::Disconnected(){
    ui->txtStatus->setText("Disconnected");
}

void MainWindow::OpenChat(QString visitorId){
    int index = -1;
    for(int i=0;i<ui->tabWidget->count();i++){
        if (ui->tabWidget->tabText(i) == visitorId){
            index = i;
            break;
        }
    }
    if (index == -1){
        VisitorChat* chat = new VisitorChat(visitorId);
        index = this->ui->tabWidget->addTab(chat, visitorId);
    }
    this->ui->tabWidget->setCurrentIndex(index);
}

MainWindow::~MainWindow()
{
    delete ui;
}






















