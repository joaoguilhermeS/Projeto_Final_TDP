#include "jpcovid.h"
#include "ui_jpcovid.h"

JPCovid::JPCovid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JPCovid)
{
    ui->setupUi(this);
}

JPCovid::~JPCovid()
{
    delete ui;
}

void JPCovid::on_pushButton_clicked()
{
    this->close();
}
