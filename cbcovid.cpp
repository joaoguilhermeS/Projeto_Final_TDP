include "cbcovid.h"
#include "ui_cbcovid.h"

cbcovid::cbcovid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cbcovid)
{
    ui->setupUi(this);
}

cbcovid::~cbcovid()
{
    delete ui;
}

void cbcovid::on_pushButton_clicked()
{
    this->close();
}
