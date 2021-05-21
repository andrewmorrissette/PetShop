#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Pet.h"
#include <QMainWindow>
#include <vector>
using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<Pet*> PetCart;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setCart(vector<Pet*> Pets){
        PetCart = Pets;
    }

    vector<Pet*> getCart(){
        return PetCart;
    }

signals:
    void changeTable(vector<Pet*>);

private slots:
    void on_showCart_clicked();

    void on_addToCart_clicked();

public slots:
    void popCart(int row);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
