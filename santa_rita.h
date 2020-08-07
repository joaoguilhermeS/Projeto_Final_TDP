#ifndef SANTA_RITA_H
#define SANTA_RITA_H

#include <QDialog>

namespace Ui {
class Santa_Rita;
}

class Santa_Rita : public QDialog
{
    Q_OBJECT

public:
    explicit Santa_Rita(QWidget *parent = nullptr);
    ~Santa_Rita();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Santa_Rita *ui;
};

#endif // SANTA_RITA_H
