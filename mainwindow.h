#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void CreateNewTab();
    void Connected();
    void Disconnected();

private slots:
    void OpenChat(QString visitorId);
    void tabCloseRequested(int tabIndex);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
