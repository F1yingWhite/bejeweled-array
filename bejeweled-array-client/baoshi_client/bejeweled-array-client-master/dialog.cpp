#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QIcon>
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->setWindowTitle("注册");
    this->setWindowIcon(QIcon(":/new/prefix1/ICON/-40badbd1560d9c06.jpg"));
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QString mima = ui->mima->text();
    int id = ui->zhanghao->text().toInt();
    QString name = ui->name->text();
    QString str = QString("insert into player_if(id, name, password,score) values('%1', '%2', '%3','%4')").arg(id).arg(name).arg(mima).arg(0);
    QSqlQuery query;
    query.exec(str);
}
