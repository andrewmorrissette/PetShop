#ifndef BUNDLEDATABASE_H
#define BUNDLEDATABASE_H
#include <QTableWidget>
#include "Cat.h"
#include "Dog.h"
#include "Builder.h"
#include "Bird.h"
#include "Fish.h"
#include "bundle.h"
#include "Pet.h"
#include "PetDatabase.h"
#include <vector>
/*
 * Special Class for the Pet Table Widget
 *
*/

class BundleDatabase: public QTableWidget{
    Q_OBJECT
    vector<Bundle*> BundleDB;
    int currentRow =-1;


public:
    BundleDatabase(QWidget* qw):QTableWidget(qw){}
    void setDB(vector<Bundle*> Pets){                  //Set the Database from the Builder object
        BundleDB = Pets;
    }
    void setCurrentRow(int row){
        currentRow = row;
    }
    vector<Bundle*> getDB(){return BundleDB;}             //Get the Database from itself.
    int getCurrentRow(){return currentRow;}

    void insertBundle(Bundle*,int);



signals:

public slots:
    void loadDatabase(vector<Pet*>);                            //Once button is clicked act on it.
    int getCellRow(int row,int col);
};

#endif // BUNDLEDATABASE_H
