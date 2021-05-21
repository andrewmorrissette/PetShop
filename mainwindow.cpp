#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
#include "Builder.h"
#include "Fish.h"
#include "Pet.h"
#include "PetBuilder.h"
#include "PetDatabase.h"
#include "PetParser.h"
#include "shoppingcartwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Load Database
    connect(ui->loadButton,SIGNAL(clicked(bool)),ui->petTable,SLOT(loadDatabase()));
    connect(ui->petTable,SIGNAL(iChanged(vector<Pet*>)),ui->bundleTable,SLOT(loadDatabase(vector<Pet*>)));


    //
    connect(ui->petTable,SIGNAL(cellClicked(int,int)),ui->petTable,SLOT(getCellRow(int,int)));
    connect(ui->bundleTable,SIGNAL(cellClicked(int,int)),ui->bundleTable,SLOT(getCellRow(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::popCart(int row){
    vector<Pet*>petCart;
    petCart = this->getCart();
    if(petCart.size()!=0){
        petCart.erase(petCart.begin()+row);
        this->setCart(petCart);
    }
    else{
        cout<<"Error: Nothing selected"<<endl;
    }
}

void MainWindow::on_showCart_clicked()
{
    ShoppingCartWindow* cartWindow = new ShoppingCartWindow(this);
    cartWindow->show();
    connect(this, SIGNAL(changeTable(vector<Pet*>)), cartWindow,SLOT(updateTable(vector<Pet*>)));
    connect(cartWindow,SIGNAL(deleteRow(int)),this,SLOT(popCart(int)));
    emit changeTable(PetCart);
}

void MainWindow::on_addToCart_clicked()
{

    int petcurrentRow = ui->petTable->getCurrentRow();
    int bundlecurrentRow = ui->bundleTable->getCurrentRow();

    if(petcurrentRow != -1){
        vector<Pet*>petDB;
        petDB = ui->petTable->getDB();

        vector<Pet*>petCart;
        petCart = this->getCart();
        petCart.push_back(petDB[petcurrentRow]);
        this->setCart(petCart);
        ui->petTable->setCurrentRow(-1);
        emit changeTable(petCart);
    }
    else if(bundlecurrentRow!=-1){
        cout<<"Row clicked: "<<bundlecurrentRow<<endl;
        vector<Bundle*>bundleDB;
        bundleDB = ui->bundleTable->getDB();
        vector<Pet*>petCart;
        petCart=this->getCart();
        string name= bundleDB[bundlecurrentRow]->getBundleName();
        cout<<name<<endl;
        bundleDB[bundlecurrentRow]->setName(name);
        bundleDB[bundlecurrentRow]->setPrice(bundleDB[bundlecurrentRow]->getDiscountedPrice());
        petCart.push_back((bundleDB[bundlecurrentRow]));
        this->setCart(petCart);
        ui->bundleTable->setCurrentRow(-1);
        emit changeTable(petCart);

    }


}
