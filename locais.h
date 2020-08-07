#ifndef LOCAIS_H
#define LOCAIS_H

#include <QDialog>

namespace Ui {
class Locais;
}

class Locais : public QDialog
{
    QString d;
    Q_OBJECT

public:
    explicit Locais(QWidget *parent = nullptr);
    ~Locais();
    void pegarcidade(QString n){d=n;};
private slots:

private:
    Ui::Locais *ui;
};

#endif // LOCAIS_H
