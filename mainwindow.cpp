#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    icon = QIcon(":/images/sti.png");
    setWindowIcon(icon);
    trayIcon = new QSystemTrayIcon(icon, this);
    qDebug() << (trayIcon->isSystemTrayAvailable()? "System Tray Available.": "No system Tray Available.");
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(systrayTriggered(QSystemTrayIcon::ActivationReason)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::systrayTriggered(QSystemTrayIcon::ActivationReason reason)
 {

    qDebug() << "Reason: " << reason;
    switch (reason)
    {
       case QSystemTrayIcon::Context:
           qDebug() << "Right clicked.";
           break;
       case QSystemTrayIcon::DoubleClick:
           qDebug() << "Double clicked.";
           break;
       case QSystemTrayIcon::Trigger:
           qDebug() << "Clicked";
           trayIcon->hide();
           show();
           break;
       case QSystemTrayIcon::MiddleClick:
           qDebug() << "Middle clicked.";
           QApplication::quit();
           break;
       default:
           qDebug() << "Triggered..";
     }

 }

void MainWindow::closeEvent(QCloseEvent *event)
 {
     if (!trayIcon->isVisible())
     {
         QMessageBox::information(this, tr("Systray"),
                                  tr("Click the system tray icon with the "
                                     "<b>MIDDLE</b> button of the mouse in order "
                                     "to quit the application."));
         hide();
         trayIcon->show();
         trayIcon->setToolTip("Wrong values demo for systray activation");
         event->ignore();
     }
 }
