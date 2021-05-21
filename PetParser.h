/* 
 * File:   ExpParser.h
 * Author: morri597
 * Source: Code Created by Professor Alex Liu
 *
 * Created on March 22, 2018, 3:30 AM
 */

#ifndef PETPARSER_H
#define	PETPARSER_H
#include "Builder.h"
#include <iostream>
#include <fstream>
#include "Pet.h"
#include <vector>

//Parser Function takes in CSV File and reads line by line
//Per line it Creates a specific Pet* and then sticks in in a vector
//This Vector will act as our physical Database.

class PetParser{
protected:
    Builder* m_petBuilder;
    vector<Pet*>pets;
public:
    void setBuilder(PetBuilder* builder){
        m_petBuilder=builder;
    }
    
    void parse(string fileName="Pets.csv"){
        cout<<"FILE IS CLOSED"<<endl;
        ifstream file("Pets.csv",std::ifstream::in); //Go through each line, tokenize and act.
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
                     newToken=""; //Once tokenized add to builder to make DB.
                     m_petBuilder->addClass(tokens[0]);
                     m_petBuilder->addName(tokens[1]);
                     m_petBuilder->addType(tokens[2]);
                     m_petBuilder->addWeight(tokens[3]);
                     m_petBuilder->addPrice(tokens[4]);
                     Pet* newPet = (m_petBuilder->addSpecial(tokens[5]));
                     pets.push_back(newPet);
                     tokens.clear();
                 }
           file.close();
            }
        }
    vector<Pet*> getDB(){ //how to get DB.
        return pets;
    }
 };
//Possibly will use other Concrete Builder using this builder class for Bundle.
#endif	/* PETPARSER_H */

