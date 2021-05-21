#ifndef PETDATABASE_H
#define PETDATABASE_H
#include <QTableWidget>
#include "Cat.h"
#include "Dog.h"
#include "Builder.h"
#include "Bird.h"
#include "Fish.h"
#include "Pet.h"
#include <vector>
/*
 * Special Class for the Pet Table Widget
 *
*/

class PetDatabase: public QTableWidget{
    Q_OBJECT
    vector<Pet*> PetDB;
    int currentRow=-1;


public:
    PetDatabase(QWidget* qw):QTableWidget(qw){}
    void setDB(vector<Pet*> Pets){                  //Set the Database from the Builder object
        PetDB = Pets;
    }
    void setCurrentRow(int row){
        currentRow = row;
    }
    vector<Pet*> getDB(){return PetDB;}             //Get the Database from itself.
    int getCurrentRow(){return currentRow;}

    void insertRow(Pet*,int);
    void insertRowDog(Pet*,int);
    void insertRowCat(Pet*, int);
    void insertRowBird(Pet*, int);
    void insertRowFish(Pet*,int);



signals:
    void iChanged(vector<Pet*>);

public slots:
    void loadDatabase();                            //Once button is clicked act on it.
    int getCellRow(int row,int col);
};

#endif // PETDATABASE_H
