#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

public slots:
    void Connect();

signals:
    void CreateNewTab();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
