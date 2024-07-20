#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QErrorMessage>
#include <QSqlError>
#include "dialog.h"
#include <QSqlQuery>
#include <QIcon>
#include <signal.h>
#include "port.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(":/new/prefix1/ICON/13685036159ECD9B4E8879728574F63D90F8AC216E.jpg"));
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("player");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_zhuce_clicked()
{
    Dialog *d = new Dialog;
    d->show();
}


void MainWindow::on_login_clicked()
{
    int flag = 0;
    QSqlQuery query;
    int id = ui->zhanghao->text().toInt();
    QString password = ui->mima->text();
    if(id==0){
        flag = 1;
    }
    else{
        query.exec("select id,password from player_if");
        while (query.next())
        {
            int id1 = query.value(0).toInt();
            QString password1 = query.value(1).toString();
            ui->textEdit->append(QString::number(id1));
            ui->textEdit->append(password1);
            if(id1 == id && password== password1){
                flag = 1;
            }
        }
    }
    if(flag==1){
        ui->textEdit->append("成功登录");
       //这里要实现登录功
        emit JumptoWork();
        this->close();
        port pot;
        pot.show();
    }
    else{
        ui->textEdit->append("账户或者密码错误");
    }

}
