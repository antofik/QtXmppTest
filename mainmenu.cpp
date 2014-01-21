#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "QXmppIq.h"
#include "core.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->cmdConnect, SIGNAL(clicked()),  this, SLOT(Connect()));
}

void MainMenu::Connect()
{
    if (Core::Connection()->isConnected()){
        Core::Connection()->Disconnect();
        ui->cmdConnect->setText("Connect");
    }else{
        Core::Connection()->Connect();
        ui->cmdConnect->setText("Disconnect");
    }
}

MainMenu::~MainMenu()
{
    delete ui;
}
