#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QIcon>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *) override;

private slots:
    void systrayTriggered(QSystemTrayIcon::ActivationReason);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QIcon icon;
};

#endif // MAINWINDOW_H
