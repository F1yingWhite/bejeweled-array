#include "menu.h"
#include "ui_menu.h"
#include <QFontDatabase>
#include <QMessageBox>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    int font_Id = QFontDatabase::addApplicationFont(":/new/prefix1/media/media/fuenteMenu.ttf");
    QStringList font_list = QFontDatabase::applicationFontFamilies(font_Id);
//    qDebug()<<font_Id;
//    qDebug()<<font_list;
    if(!font_list.isEmpty())
    {
        QFont f;
        f.setFamily(font_list[0]);
//        ui->label->setStyleSheet("color: rgb(238, 255, 252);");
        ui->pushButton->setFont(f);
        ui->pushButton1 ->setFont(f);
        ui->pushButton_3->setFont(f);
    }
}

menu::~menu()
{
    delete ui;
}




void menu::on_pushButton_3_clicked()
{
    QMessageBox message;
//    message.setIcon(QMessageBox::Icon(QIcon(":/new/prefix1/ICON/-40badbd1560d9c06.jpg")));
    message.setWindowTitle("help");
    message.setIconPixmap(QPixmap(":/new/prefix1/media/media/help.png"));
    message.exec();
}

