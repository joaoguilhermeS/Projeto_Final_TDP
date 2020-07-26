mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

--------------------------------------------------------------------------------------------

main.cpp

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

--------------------------------------------------------------------------------------
mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>//Responsavel por enviar o texto para o arquivo

QString local("C:/Felipe/Tec-Pro/Projeto/");
QString nome ("Usuarios_Psic.txt");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile arquivo(local+nome);
    if(!arquivo.open(QFile::Append|QFile::Text))//Verificar se ele esta aberto
    {
        QMessageBox::warning(this,"ERRO","ERRO AO ABRIR ARQUIVO");\\Caixa de Mensagem para Erro;
    }
    QTextStream saida(&arquivo);
    QString nome = ui->Nome/*Nome do objeto no .ui*/->text();//Pegar valor da EditLine
    QString gene = ui->Genero->currentText();//Pegar valor da comboBox
    QString id = ui->lineEdit_3->text();
    QString city = ui->Cidade->currentText();
    saida<<nome<<"  "<<gene<<"  "<<id<<"anos  "<<city<<"\n";
    arquivo.flush();
    arquivo.close();
}
