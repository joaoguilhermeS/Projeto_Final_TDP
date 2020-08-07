#include "joaopessoa.h"
#include "ui_joaopessoa.h"

JoaoPessoa::JoaoPessoa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoaoPessoa)
{
    ui->setupUi(this);
}

JoaoPessoa::~JoaoPessoa()
{
    delete ui;
}

void JoaoPessoa::on_pushButton_clicked()
{
    this->close();
}
