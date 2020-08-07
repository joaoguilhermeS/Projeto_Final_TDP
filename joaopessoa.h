#ifndef JOAOPESSOA_H
#define JOAOPESSOA_H

#include <QDialog>

namespace Ui {
class JoaoPessoa;
}

class JoaoPessoa : public QDialog
{
    Q_OBJECT

public:
    explicit JoaoPessoa(QWidget *parent = nullptr);
    ~JoaoPessoa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::JoaoPessoa *ui;
};

#endif // JOAOPESSOA_H
