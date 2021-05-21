/* 
 * File:   Pet.h
 * Author: morri597 & Bednarz4
 *
 * Created on February 19, 2018, 11:45 PM
 */

#ifndef PET_H
#define	PET_H

#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using std::cout;
/*
 * CODE USED FROM PROJECT 1 DO NOT TOUCH
*/

class Pet{
public:
    string getName()const{return name;}
    string getType()const{return type;}
    unsigned int getWeight()const{return weight;}
    float getPrice()const{return price;}
    string getBreed()const{return breed;}
    bool getFluffy()const{return isFluffy;}
    string getEnvironment()const{return enviro;}
    bool getNocturnality()const{return isNocturnal;}
    bool getCat()const{return isCat;}
    bool getBird()const{return isBird;}
    
    void setName(string n){name=n;}
    void setType(string t){type=t;}
    void setWeight(unsigned int w){weight=w;}
    void setPrice(float p){price=p;}
    void setNocturnality(bool b){isNocturnal=b;}
    void setFluffy(bool b){isFluffy=b;}
    void setBreed(string b){breed=b;}
    void setEnvironment(string b){enviro=b;}
    void setBird(bool b){isBird=b;}
    void setCat(bool b){isCat=b;}
    
    virtual void print()const=0;

    ~Pet(){
    }
    
protected:
    Pet(string n, string t, float p, unsigned int w){
        name = n;
        type = t;
        weight = w;
        price = p;
    }
    Pet(){
        name = "";
        type = "";
        weight = 0;
        price = 0.0;

        enviro="";
        breed="";
        isFluffy=false;
        isNocturnal=false;
        isCat=false;
        isBird=false;

    }
    
    string name;
    string type;
    unsigned int weight;
    float price;

    //Extra Variables that had to get added.
    string enviro;
    string breed;
    bool isFluffy;
    bool isNocturnal;
    bool isCat; //Used to determine if it's a cat
    bool isBird; //used to determine if it's a bird (because Cat & Bird both use bools for special attribute)

};



#endif	/* PET_H */

