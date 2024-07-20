#ifndef menu_H
#define menu_H

#include <QWidget>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
signals:
    void start();
    void TwoPlay();

private slots:
    void on_pushButton_clicked(){
        emit start();
        this->close();
    }

    void OpenToWork(){
        this->show();
    }

    void on_pushButton1_clicked(){
        emit TwoPlay();
        this->close();
    }

    void on_pushButton_3_clicked();

private:
    Ui::menu *ui;
};

#endif
