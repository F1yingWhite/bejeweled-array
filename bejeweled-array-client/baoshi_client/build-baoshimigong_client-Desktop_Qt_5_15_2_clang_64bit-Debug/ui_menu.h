/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_9;
    QPushButton *pushButton1;
    QPushButton *pushButton_3;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(660, 580);
        menu->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 330, 261, 51));
        QFont font;
        font.setPointSize(18);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"border-style:solid;\n"
"color:rgb(231, 255, 231);\n"
"border-color:rgba(205,205,205,0.8);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"background-color:rgba(198,198,220,06);/*\350\203\214\346\231\257\350\211\262*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"border-image: url(:/new/prefix1/media/media/stateMainMenu/menuHighlight.png);\n"
"}\n"
"\n"
"\n"
""));
        layoutWidget = new QWidget(menu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 230, 461, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/1.png);"));

        horizontalLayout->addWidget(label_2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/2.png);"));

        horizontalLayout->addWidget(label_7);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/3.png);"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/4.png);"));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/5.png);"));

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/6.png);"));

        horizontalLayout->addWidget(label_6);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/7.png);"));

        horizontalLayout->addWidget(label_8);

        label = new QLabel(menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, -10, 601, 311));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/stateMainMenu/mainMenuLogo.png);\n"
""));
        label_9 = new QLabel(menu);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(-90, -10, 821, 581));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/stateMainMenu/mainMenuBackground.png);"));
        pushButton1 = new QPushButton(menu);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(120, 400, 421, 51));
        pushButton1->setFont(font);
        pushButton1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton1->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"border-style:solid;\n"
"color:rgb(231, 255, 231);\n"
"border-color:rgba(205,205,205,0.8);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"background-color:rgba(198,198,220,06);/*\350\203\214\346\231\257\350\211\262*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"border-image: url(:/new/prefix1/media/media/stateMainMenu/menuHighlight.png);\n"
"}\n"
"\n"
"\n"
""));
        pushButton_3 = new QPushButton(menu);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 480, 281, 51));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"border-style:solid;\n"
"color:rgb(231, 255, 231);\n"
"border-color:rgba(205,205,205,0.8);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"background-color:rgba(198,198,220,06);/*\350\203\214\346\231\257\350\211\262*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"color:rgb(231, 255, 231);\n"
"border-image: url(:/new/prefix1/media/media/stateMainMenu/menuHighlight.png);\n"
"}\n"
"\n"
"\n"
""));
        label_9->raise();
        pushButton->raise();
        layoutWidget->raise();
        label->raise();
        pushButton1->raise();
        pushButton_3->raise();

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("menu", "s t a r t", nullptr));
        label_2->setText(QString());
        label_7->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        label->setText(QString());
        label_9->setText(QString());
        pushButton1->setText(QCoreApplication::translate("menu", "T w o  p l a y e r   V.S", nullptr));
        pushButton_3->setText(QCoreApplication::translate("menu", "H e l p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
