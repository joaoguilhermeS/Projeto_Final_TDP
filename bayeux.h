#ifndef BAYEUX_H
#define BAYEUX_H

#include <QDialog>

namespace Ui {
class Bayeux;
}

class Bayeux : public QDialog
{
    Q_OBJECT

public:
    explicit Bayeux(QWidget *parent = nullptr);
    ~Bayeux();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bayeux *ui;
};

#endif // BAYEUX_H
