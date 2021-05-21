#include "PetDatabase.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
#include "Builder.h"
#include "Fish.h"
#include "Pet.h"
#include "PetBuilder.h"
#include "PetParser.h"
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

void PetDatabase::loadDatabase(){
    cout<<"TESTING"<<endl;
    //Declarations
    vector<Pet*>pets;
    PetParser parser;
    PetBuilder builder;
    parser.setBuilder(&builder);

    parser.parse("Pets.csv"); //Go through the Database && Make the Pet Objs and Classes
    pets = parser.getDB(); //And Place them in Database Vector
    cout<<pets.size()<<endl;
    this->setDB(pets);
    this->setRowCount(pets.size()); //Go through each row in Table and insert Row based on animal type
    for(int x=0;x<pets.size();x++){
        this->insertRow(pets[x],x);
    }
    emit iChanged(pets);
}

void PetDatabase::insertRow(Pet* pet, int Row){
    //Determine what pet it is && Call function.

    if(pet->getBird()){this->insertRowBird(pet,Row);}
    else if(pet->getCat()){this->insertRowCat(pet,Row);}
    else if(pet->getBreed()!=""){this->insertRowDog(pet,Row);}
    else if(pet->getEnvironment()!=""){this->insertRowFish(pet,Row);}
}
void PetDatabase::insertRowDog(Pet* pet,int row){
    string Name = pet->getName();
    QString QName = QString::fromStdString(Name);
    this->setItem(row,0,new QTableWidgetItem(QName));
    this->setItem(row,1,new QTableWidgetItem("Dog"));
    QString price = QString::number(pet->getPrice());
    this->setItem(row,2,new QTableWidgetItem(price));
    string specialAttribute = pet->getBreed() + " " + pet->getType();
    QString QspecialAttribute = QString::fromStdString(specialAttribute);
    this->setItem(row,3,new QTableWidgetItem(QspecialAttribute));
}

void PetDatabase::insertRowFish(Pet* pet,int row){
    //Name,Class,Price,Special Attribute
    string Name = pet->getName();
    QString QName = QString::fromStdString(Name);
    this->setItem(row,0,new QTableWidgetItem(QName));
    this->setItem(row,1,new QTableWidgetItem("Fish"));
    QString price = QString::number(pet->getPrice());
    this->setItem(row,2,new QTableWidgetItem(price));
    string specialAttribute = pet->getEnvironment() + " " + pet->getType();
    QString QspecialAttribute = QString::fromStdString(specialAttribute);
    this->setItem(row,3,new QTableWidgetItem(QspecialAttribute));
}

void PetDatabase::insertRowCat(Pet* pet,int row){
    //Name,Class,Price,Special Attribute
    string Name = pet->getName();
    QString QName = QString::fromStdString(Name);
    this->setItem(row,0,new QTableWidgetItem(QName));
    this->setItem(row,1,new QTableWidgetItem("Cat"));
    QString price = QString::number(pet->getPrice());
    this->setItem(row,2,new QTableWidgetItem(price));

    string specialAttribute ="";
    if(pet->getFluffy()==true){
        specialAttribute = "Fluffy " + pet->getType();
    }
    else{
        specialAttribute = pet->getType();
    }
    QString QspecialAttribute = QString::fromStdString(specialAttribute);
    this->setItem(row,3,new QTableWidgetItem(QspecialAttribute));
}

void PetDatabase::insertRowBird(Pet* pet,int row){
    string Name = pet->getName();
    QString QName = QString::fromStdString(Name);
    this->setItem(row,0,new QTableWidgetItem(QName));
    this->setItem(row,1,new QTableWidgetItem("Bird"));
    QString price = QString::number(pet->getPrice());
    this->setItem(row,2,new QTableWidgetItem(price));

    string specialAttribute ="";
    if(pet->getNocturnality()==true){
        specialAttribute = "Nocturnal " + pet->getType();
    }
    else{
        specialAttribute = pet->getType();
    }
    QString QspecialAttribute = QString::fromStdString(specialAttribute);
    this->setItem(row,3,new QTableWidgetItem(QspecialAttribute));
}

int PetDatabase::getCellRow(int row,int col){
    this->setCurrentRow(row);
}


