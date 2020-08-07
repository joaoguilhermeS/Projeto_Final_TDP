#include "bycovid.h"
#include "ui_bycovid.h"

bycovid::bycovid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bycovid)
{
    ui->setupUi(this);
}

bycovid::~bycovid()
{
    delete ui;
}

void bycovid::on_pushButton_clicked()
{
    this->close();
}
