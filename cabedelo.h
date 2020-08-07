#ifndef CABEDELO_H
#define CABEDELO_H

#include <QDialog>

namespace Ui {
class Cabedelo;
}

class Cabedelo : public QDialog
{
    Q_OBJECT

public:
    explicit Cabedelo(QWidget *parent = nullptr);
    ~Cabedelo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cabedelo *ui;
};

#endif // CABEDELO_H
