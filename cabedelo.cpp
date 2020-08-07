#include "cabedelo.h"
#include "ui_cabedelo.h"

Cabedelo::Cabedelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cabedelo)
{
    ui->setupUi(this);
}

Cabedelo::~Cabedelo()
{
    delete ui;
}

void Cabedelo::on_pushButton_clicked()
{
    this->close();
}
