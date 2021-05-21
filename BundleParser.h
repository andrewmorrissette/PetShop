/* 
 * File:   ExpParser.h
 * Author: morri597
 * Source: Code Created by Professor Alex Liu
 *
 * Created on March 22, 2018, 3:30 AM
 */

#ifndef BUNDLEPARSER_H
#define	BUNDLEPARSER_H
#include <iostream>
#include <fstream>
#include "Pet.h"
#include "bundle.h"
#include <vector>

//Parser Function takes in CSV File and reads line by line
//Per line it Creates a specific Pet* and then sticks in in a vector
//This Vector will act as our physical Database.

class BundleParser{
protected:
    vector<Bundle*>bundles;
    vector<Pet*>Pets;
    std::string::size_type sz;
public:

    void parse(string fileName="Bundles.csv"){

        cout<<"FILE IS CLOSED"<<endl;
        ifstream file("Bundles.csv",std::ifstream::in); //Go through each line, tokenize and act.
            if (file.is_open()) {
                 cout<<"FILE IS OPEN"<<endl;
                 char token = ',';
                 string newToken ="";
                 vector<string>tokens;
                 string line;
                 while (getline(file, line))   {
                     int lineSize = line.size();
                     for(int i=0;i<lineSize;i++){
                         if(line[i]!=token){
                             newToken = newToken + line[i];
                         }
                         else if(line[i]==token){
                             tokens.push_back(newToken);
                             newToken = "";
                         }
                     }
                     tokens.push_back(newToken);
                     newToken="";
                     string name = tokens[0];
                     float discount = stof(tokens[1],0);
                     Bundle* newBundle = new Bundle(name,discount);
                     for(int i =2;i<tokens.size();i++){
                         for(int j=0;j<Pets.size();j++){
                             if(tokens[i]==Pets[j]->getName()){
                                 newBundle->addItem(Pets[j]);
                             }
                         }
                     }

                     bundles.push_back(newBundle);
                     tokens.clear();
                 }
           file.close();
            }
        }
    vector<Bundle*> getDB(){ //how to get DB.
        return bundles;
    }
    void setPetDB(vector<Pet*>pets){
        Pets = pets;
    }
 };
//Possibly will use other Concrete Builder using this builder class for Bundle.
#endif	/* BUNDLEPARSER_H */

