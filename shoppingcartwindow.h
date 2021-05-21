#ifndef SHOPPINGCARTWINDOW_H
#define SHOPPINGCARTWINDOW_H

#include "Pet.h"
#include <QDialog>
#include <vector>
using namespace std;

namespace Ui {
class ShoppingCartWindow;
}

class ShoppingCartWindow : public QDialog
{
    Q_OBJECT
    int currentRow;

public:
    explicit ShoppingCartWindow(QWidget *parent = 0);
    ~ShoppingCartWindow();

    Ui::ShoppingCartWindow* getUI() const {return ui;}

    int getCurrentRow(){
        return currentRow;
    }

    void setCurrentRow(int row){
        currentRow = row;
    }

private:
    Ui::ShoppingCartWindow *ui;

signals:
    void deleteRow(int row);

public slots:
    void updateTable(vector<Pet*> pets);
    void getCartCellRow(int row,int col);

private slots:
    void on_pushButton_clicked();
    void on_deleteButton_clicked();
    void on_checkoutButton_clicked();
};

#endif // SHOPPINGCARTWINDOW_H
