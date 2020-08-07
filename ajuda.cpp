#include "ajuda.h"
#include "ui_ajuda.h"
#include <QVBoxLayout>
#include "saude_mental.h"
#include <QMessageBox>
#include <Covid-19.h>
#include <QPixmap>

Ajuda::Ajuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajuda)
{

    ui->setupUi(this);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(ui->SintomaA); lay->addWidget(ui->SintomaB);
    lay->addWidget(ui->SintomaC); lay->addWidget(ui->SintomaD);
    lay->addWidget(ui->SintomaE); lay->addWidget(ui->SintomaF);
    lay->addWidget(ui->SintomaG); lay->addWidget(ui->SintomaH);
    ui->Sintomas->setLayout(lay);

}
Ajuda::~Ajuda()
{
    delete ui;
}

void Ajuda::on_pushButton_clicked()//Escolheu Saude Mental
{
   ui->label_6->setText(ui->lineEdit->text()+" quais desses sintomas voce possui?");
   ui->SintomaA->setText("Insonia");  ui->SintomaB->setText("Medo constante de pegar o vírus");
   ui->SintomaC->setText("Pensamentos constantes sobre se contaminar");  ui->SintomaD->setText("Coração aceleraddo (Taquicardia)");
   ui->SintomaE->setText("Respiração Ofegante ou Acelerada");  ui->SintomaF->setText("Crise de Ansiedade");
   ui->SintomaG->setText("Pensamentos constantes sobre morrer pelo vírus");  ui->SintomaH->setText("Receio de sair de casa nas necessidades");

   ui->label_7->setText(ui->lineEdit->text() + " responda com Sim ou Nao:");
   ui->P1->setText("Seu sono ficou alterado após o início da Pandemia?");   ui->P2->setText("Seus pensamentos são, na maioria, sobre o corona vírus?");
   ui->P3->setText("Voce evita sair em necessidades, como ir a farmacia ou supermercado?");   ui->P4->setText("Voce tem ficado mais tempo deitado que o normal?"); 
   ui->P5->setText("O medo do coronavíuus atrapalha o seu dia?");   ui->P6->setText("Ao pensar no coronavírus voce fica com o a respiraçao ofegante ou coraçao acelerado?");
   ui->P7->setText("Voce passa a maior parte do seu tempo pensando no coronavírus?");

   QPixmap IMG(":/Imagens/E:/Felipe/Tec-Pro/Projeto/ProjetoTec/Logo-removebg-preview.png");
   ui->label_9->setPixmap(IMG);
   help=("Saude Mental");
}

void Ajuda::on_pushButton_2_clicked()//Escolheu Covid-19
{
    ui->label_6->setText(ui->lineEdit->text()+" quais desses sintomas voce possui?");
    ui->SintomaA->setText("Febre");  ui->SintomaB->setText("Perda do Paladar ou Olfato");
    ui->SintomaC->setText("Dor de Gargante");  ui->SintomaD->setText("Diarreia");
    ui->SintomaE->setText("Falta de ar");  ui->SintomaF->setText("Cansaço");
    ui->SintomaG->setText("Aperto no peito");  ui->SintomaH->setText("Dor de Cabeça");

    ui->label_7->setText(ui->lineEdit->text() + " responda com Sim ou Nao:");
    ui->P1->setText("Voce possui os sintomas a mais de 4 dias?");    ui->P2->setText("Voce é diabético?");
    ui->P3->setText("Voce é asmático?");    ui->P4->setText("Voce é cardíaco?");
    ui->P5->setText("Voce tem pressao alta?");    ui->P6->setText("Voce fuma?");
    ui->P7->setText("Voce conhece ou teve contato com alguem que ja foi contaminado?");
    QPixmap IMG(":/Imagens/E:/Felipe/Tec-Pro/Projeto/ProjetoTec/dois-removebg-preview.png");
    ui->label_9->setPixmap(IMG);
    help=("Covid-19");
}

void Ajuda::on_pushButton_3_clicked()//Verificar Resultado
{
    QString sexo = ui->comboBox->currentText(); QString nome = ui->lineEdit->text();
    QString bairro = ui->Bairros->currentText(); int i = ui->spinBox->value(); bool c[8],p[7];

     c[0]=ui->SintomaA->isChecked();     c[1]=ui->SintomaB->isChecked();
     c[2]=ui->SintomaC->isChecked();     c[3]=ui->SintomaD->isChecked();
     c[4]=ui->SintomaE->isChecked();     c[6]=ui->SintomaF->isChecked();
     c[5]=ui->SintomaG->isChecked();     c[7]=ui->SintomaG->isChecked();

     p[0]=ui->radioButton->isChecked();     p[1]=ui->radioButton_3->isChecked();
     p[2]=ui->radioButton_5->isChecked();   p[3]=ui->radioButton_7->isChecked();
     p[4]=ui->radioButton_9->isChecked();   p[5]=ui->radioButton_15->isChecked();
     p[6]=ui->radioButton_13->isChecked();
     Paciente_t *Pecas[1];
    if(help=="Saude Mental")
    {

        Saude_Mental usuario(nome,sexo,cidade,bairro,i);
        Pecas[0] = &usuario;
        int sint = Analise(Pecas,c);
        int perg = Analise2(Pecas,p);

        if(sint >2 || perg >2)
        {
            usuario.set_ver("Sim ");
            QMessageBox::warning(this,"URGENTE",nome + " RECOMENDAMOS QUE VOCE PROCURE AJUDA MEDICA!");
           Indicar(Pecas);this->close();}
        else {usuario.set_ver("Nao ");
            QMessageBox::about(this,"AVISO",nome + " VOCE TEM UMA BOA SAUDE MENTAL");this->close();}
    }
    else
    {
        Covid_19 usuario(nome,sexo,cidade,bairro,i);
        Pecas[0] = &usuario;
        int sit = Analise(Pecas,c);
        Analise2(Pecas,p);
        if(sit>3)
        {
            if(sit>=5){QMessageBox::warning(this,"URGENTE","VOCE NECESSITA IR A UM POSTO MEDICO");
            Indicar(Pecas);this->close();}
            else{ QMessageBox::warning(this,"AVISO","PODE SER QUE VOCE TENHA COVID-19, FIQUE EM ISOLAMENTO");this->close();}
        }
        else{QMessageBox::warning(this,"AVISO","CASO IMPROVAVEL!");this->close();}
    }

}

void Ajuda::on_pushButton_7_clicked()//Mora em João Pessoa
{
    cidade = "João Pessoa";
    QList<QString> Bairros;
    Bairros<<"Altiplano"<<"Aeroclube"<<"Água Fria"<<"Alto do Céu"<<"Alto do Mateus"<<"Anatólia"<<"Bairro das Indústrias"
    <<"Bairro dos Estados"<<"Bairro dos Ipês"<<"Bairro dos Novais"<<"Bancários"<<"Barra de Gramame"<<"Bessa"
    <<"Jardim Brisamar"<<"Cabo Branco"<<"Castelo Branco"<<"Centro"<<"Cidade dos Colibris"<<"Costa do Sol"<<"Costa e Silva"
    <<"Cristo Redentor"<<"Cruz das Armas"<<"Cuiá"<<"Distrito Industrial"<<"Ernesto Geisel"<<"Enâni Sátiro"<<"Expedicionarios"
    <<"Funcionários I"<<"Funcionários II"<<"Funcionários III"<<"Gramame"<<"Grotão"<<"Ilha do Bispo"<<"Jaguaribe"<<"Jardim 13 de Maio"
    << "Jardim Cidade Universitária"<<"Jardim Esther"<<"Jardim Luna"<<"Jardim Mangueira"<<"Jardim Oceania"<<"Jardim Planalto"<<"Jardim São Paulo"
    <<"Jardim Veneza"<<"José Américo"<<"João Agripino"<<"João Paulo II"<<"Manaíra"<<"Mandacaru"<<"Mangabeira"<<"Mata do Buraquinho"
    <<"Miramar"<<"Mumbaba"<<"Mussuré"<<"Muçumagro"<<"Oitizeiro"<<"Padre Zé"<<"Paratibe"<<"Pedro Gondim"<<"Penha"<<"Planalto da Boa Esperança"
    <<"Ponta dos Seixas"<<"Portal do Sol"<<"Quadramares"<<"Rangel"<<"Roger"<<"São José"<<"Tambaú"<<"Tambauzinho"<<"Tambiá"<<"Torre"<<"Trincheiras"
    <<"Valentina Figueiredo"<<"Varadouro"<<"Varjão";
    ui->Bairros->clear();
    ui->Bairros->addItems(Bairros);

}

void Ajuda::on_pushButton_8_clicked()//Mora em Bayeux
{
    cidade = "Bayeux";
    QList<QString> Bairros;
    Bairros<<"Alto da Boa Vista"<<"Baralho"<<"Brasília"<<"Centro"<<"Comercial Norte"<<"Imaculada"<<"Jardim Aeroporto"
      <<"Jardim São Severino"<<"Jardim São Vincente"<<"Mário Andreazza"<<"Rio do Meio "<<"São Bento"<<"Sesi"<<"Tambay";
    ui->Bairros->clear();
    ui->Bairros->addItems(Bairros);
}

void Ajuda::on_pushButton_5_clicked()//Mora em Cabedelo
{
    cidade = "Cabedelo";
    QList<QString> Bairros;
    Bairros<<"Amazônia Park"<<"Areia Dourada"<<"Camalaú"<<"Camboinha"<<"Centro"<<"Formosa"<<"Intermares"
      <<"Jacaré"<<"Jardim América"<<"Jardim Brasília"<<"Jardim Camboinha"<<"Monte Castro"<<"Parque Verde"<<"Poço"
     <<"Ponta de Campina"<<"Ponta de Matos"<<"Portal do Poço"<<"Recanto do Poço"<<"Santa Catarina"<<"Morada Nova"
    <<"Parque Esperança"<<"Renascer"<<"Salinas";
    ui->Bairros->clear();
    ui->Bairros->addItems(Bairros);
}

void Ajuda::on_pushButton_6_clicked()//Mora em Santa Rita
{
    cidade = "Santa Rita";
    QList<QString> Bairros;
    Bairros<<"Aguiarlândia"<<"Alto das Populares"<<"Alto dos Eucaliptos"<<"Augustolândia"<<"Açude"<<"Bairro dos Municípios"
          <<"Bairro do Onze"<<"Bebelândia"<<"Boa Vista"<<"Castanheiro"<<"Centro"<<"Cicerolândia"
         <<"Distrito Industrial"<<"Flaviano Ribeiro"<<"Forte Velho"<<"Heitel Santiago"<<"Jardim Carolina"
          <<"Jardim Europa I"<<"Jardim Europa II"<<"Jardim Europa III"<<"Jardim Miritânia"<<"Lerolândia"<<"Liberdade"<<"Livramento"
         <<"Loteamento Nice"<<"Loteamento Plano de Vida"<<"Marcos Moura"<<"Mutirão"<<"Nova Esperança"
        <<"Odilândia"<<"Paulo VI"<<"Paraíso Tropical"<<"Santa Cruz"<<"Sol Nascente"<<"Teixeirão"<<"Tibiri I"
       <<"Tibiri II"<<"Tibiri III"<<"Tibiri Fábrica"<<"Várzea Nova"<<"Vila Tibiri";
    ui->Bairros->clear();
    ui->Bairros->addItems(Bairros);
}

void Ajuda::on_pushButton_4_clicked()//Sair da análise
{
    this->close();
}
