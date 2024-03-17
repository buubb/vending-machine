#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnable(); //init
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeEnable();
};
void Widget::changeEnable(){
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=200);
    ui->pbReset->setEnabled(money>0);
};
void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int coin10, coin50, coin100, coin500;
    coin500 = money/500;
    money %= 500;
    coin100 = money/100;
    money %= 100;
    coin50 = money/50;
    money %= 50;
    coin10 = money/10;
    money %= 10;

    QString msg,msg1,msg2,msg3;
    msg = "500:"+QString::number(coin500)+"\n";
    msg1 = "100:"+QString::number(coin100)+"\n";
    msg2 = "50:"+QString::number(coin50)+"\n";
    msg3 = "10:"+QString::number(coin10)+"\n";

    QMessageBox mb;
    mb.information(nullptr, " ",msg+msg1+msg2+msg3);

    ui->lcdNumber->display(money);
    changeEnable();
}

