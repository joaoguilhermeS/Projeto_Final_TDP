#ifndef SAUDE_MENTAL_H
#define SAUDE_MENTAL_H

#include "Paciente.h"
#include "locais.h"
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
class Saude_Mental:public Paciente_t
{
    QString local=("E:/Felipe/Tec-Pro/");
    QString name=("Usuarios_Sau_Ment.txt");
    QString verificacao;
public:
    Saude_Mental(QString n, QString s, QString c,QString b,int i):Paciente_t(n,s,c,b,i)
    {
        set_name(n);
        set_sex(s);
        set_city(c);
        set_idad(i);
        set_bair(b);
        QFile arquivo(local+name);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {

        }
        QTextStream saida(&arquivo);
        saida <<nome<<"  "<<sexo<<"  "<<cidade<<"  "<<bairro<<"  "<<idade<<" Anos ";
        arquivo.close();

    }
    void set_ver(QString resp){
        verificacao = resp;
        QFile arquivo(local+name);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {

        }
        QTextStream saida(&arquivo);
        saida <<verificacao<<"\n" ;
        arquivo.close();};

    int Syntoms(bool *c);

    int Questoes(bool *p);

    void locale();

};

#endif // SAUDE_MENTAL_H
