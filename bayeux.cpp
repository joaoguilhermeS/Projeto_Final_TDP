#include "bayeux.h"
#include "ui_bayeux.h"

Bayeux::Bayeux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bayeux)
{
    ui->setupUi(this);
}

Bayeux::~Bayeux()
{
    delete ui;
}

void Bayeux::on_pushButton_clicked()
{
    this->close();
}
