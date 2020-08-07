#include "srcovid.h"
#include "ui_srcovid.h"

srcovid::srcovid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::srcovid)
{
    ui->setupUi(this);
}

srcovid::~srcovid()
{
    delete ui;
}

void srcovid::on_pushButton_clicked()
{
    this->close();
}
