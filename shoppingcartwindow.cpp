#include "shoppingcartwindow.h"
#include "ui_shoppingcartwindow.h"
#include "petdatabase.h"
#include <iostream>
using std::cout;

ShoppingCartWindow::ShoppingCartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCartWindow)
{
    ui->setupUi(this);

    //Get the row of the cell currently selected and set it to a variable in shoppingcartwindow.h
    connect(ui->cartTable,SIGNAL(cellClicked(int,int)),this,SLOT(getCartCellRow(int,int)));
}

void ShoppingCartWindow::updateTable(vector<Pet*>pets){
    //Call your insert rows
    //pets is the table you want to get your info from
    for (int i=0; i<pets.size(); i++){
        ui->cartTable->insertRow(ui->cartTable->rowCount());
        QString name = QString::fromStdString(pets[i]->getName());
        QString price = QString::number(pets[i]->getPrice());
        ui->cartTable->setItem(i,0,new QTableWidgetItem (name));
        ui->cartTable->setItem(i,1,new QTableWidgetItem (price));
    }
}

void ShoppingCartWindow::getCartCellRow(int row,int col){
    this->setCurrentRow(row);
}

ShoppingCartWindow::~ShoppingCartWindow()
{
    delete ui;
}

void ShoppingCartWindow::on_deleteButton_clicked()
{
    ui->cartTable->removeRow(currentRow);
    emit deleteRow(currentRow);
}

void ShoppingCartWindow::on_checkoutButton_clicked()
{

}

void ShoppingCartWindow::on_pushButton_clicked()
{

}
