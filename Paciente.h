#ifndef PACIENTE_H
#define PACIENTE_H
#include <QDialog>

class Paciente_t
{
protected:
    QString nome,sexo,cidade,bairro;
    int idade;
public:
    Paciente_t(QString n, QString s, QString c,QString b, int i)
    {
        nome = n;
        sexo = s;
        cidade = c;
        idade = i;
        bairro = b;
    }
    QString getname(){return nome;};
    QString getsex(){return sexo;};
    QString getcity(){return cidade;};
    QString getbairro(){return bairro;};
    int getidade(){return idade;};
    void set_name(QString n){nome = n;};
    void set_sex(QString s){sexo = s;};
    void set_city(QString c){cidade = c;};
    void set_idad(int i){idade = i;};
    void set_bair(QString b){bairro = b;};
    virtual int Syntoms(bool *c)=0;
    virtual int Questoes(bool *p)=0;
    virtual void locale()=0;
};

#endif // PACIENTE_H
