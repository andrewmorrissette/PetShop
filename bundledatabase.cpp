#include "PetDatabase.h"
#include "bundledatabase.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
#include "Builder.h"
#include "Fish.h"
#include "Pet.h"
#include "bundle.h"
#include "PetBuilder.h"
#include "BundleParser.h"
#include "shoppingcartwindow.h"
#include <vector>
#include <typeinfo>
#include <iostream>

//This .cpp CREATES the Database.
//When the load button is clicked it calls loadDatabase
//loadDatabase first parses through the file and creates the Database (see parser & Builder for more details)
//this database pets will be used as our Global Database(To access just use getDB function).
//After the database is retrieved it then goes through each pet object and determines what pet it is.
//Once determined it calls a corresponding insertRow function and inserts the row depending on its characteristics.

void BundleDatabase::loadDatabase(vector<Pet*>pet){

    vector<Pet*>pets = pet;
    cout<<"TESTING"<<endl;
    //Declarations
    vector<Bundle*>bundles;
    BundleParser parser;
    parser.setPetDB(pets);
    parser.parse("Bundles.csv"); //Go through the Database && Make the Pet Objs and Classes
    bundles = parser.getDB(); //And Place them in Database Vector
    cout<<bundles.size()<<endl;
    this->setDB(bundles);
    this->setRowCount(bundles.size()); //Go through each row in Table and insert Row based on animal type
    for( unsigned int x=0;x<bundles.size();x++){
        cout<<"For Loop"<<endl;
        this->insertBundle(bundles[x],x);
    }
}

void BundleDatabase::insertBundle(Bundle* bundle, int row){
    cout<<"Inserting Row"<<endl;
    cout<<row<<endl;
    //Determine what pet it is && Call function.
    string Name = bundle->getBundleName();
    QString QName = QString::fromStdString(Name);
    this->setItem(row,0,new QTableWidgetItem(QName));
    QString price = QString::number(bundle->getDiscountedPrice());
    this->setItem(row,1,new QTableWidgetItem(price));
    QString savings = QString::number(bundle->getSavings());
    this->setItem(row,2,new QTableWidgetItem(savings));
}
int BundleDatabase::getCellRow(int row,int col){
    cout<<"ROW: "<<row<<endl;
    this->setCurrentRow(row);
}


