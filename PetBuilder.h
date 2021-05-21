/* 
 * File:   ExpBuilder.h
 * Author: morri597
 * Source: Based code off of Professor Alex Liu's and modified it to fit assignment
 *
 * Created on March 22, 2018, 3:30 AM
 */

#ifndef PETBUILDER_H
#define PETBUILDER_H
using namespace std;
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include "Builder.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"
/*
 * Pet Builder takes in each part of a pet & Determines which
 * Pet it is, and creates that Class Object using paramaters given.
 * The Special Class RETURNS the new Pet.
 * */

class PetBuilder: public Builder{
    protected:
        string::size_type sz;     // alias of size_t
        string ClassName ="";
        string Name ="";
        string Type = "";
        float Price= 0.0;
        unsigned int Weight =0;

    public:
        virtual void addClass(string Class){
            ClassName=Class;
        }
        virtual void addName(string name){
            Name = name;
        }
        virtual void addType(string type){
            Type = type ;
        }
        virtual void addPrice(string price){

            Price = std::stof(price,&sz);
        }
        virtual void addWeight(string weight){
            cout<<"WEIGHT: "<<weight<<endl;
            Weight = std::stoul(weight,&sz);
            cout<<"WEIGHT ADDED"<<endl;
        }
        virtual Pet* addSpecial(string Special){
            if(ClassName =="Dog")
            {
                Dog* tempDog = new Dog(Name, Type, Price, Weight,Special);
                tempDog->setBreed(Special);
                tempDog->setBird(false);
                tempDog->setCat(false);
                return tempDog;
            }

            else if(ClassName=="Fish"){
                Fish* tempFish = new Fish ( Name, Type, Price, Weight,Special);
                tempFish->setEnvironment(Special);
                tempFish->setBird(false);
                tempFish->setCat(false);
                return tempFish;
            }
            else if(ClassName == "Bird"){
                if(Special =="true"){
                    Bird* tempBird=new Bird(Name, Type, Price, Weight,true);
                    tempBird->setBird(true);
                    tempBird->setCat(false);
                    tempBird->setNocturnality(true);
                    return tempBird;
                }
                else{
                    Bird* tempBird =new Bird(Name, Type, Price, Weight,false);
                    tempBird->setBird(true);
                    tempBird->setCat(false);
                    tempBird->setNocturnality(false);
                    return tempBird;
                }
            }
            else if(ClassName=="Cat"){
                if(Special =="true"){
                    Cat* tempCat = new Cat(Name, Type, Price, Weight,true);
                    tempCat->setCat(true);
                    tempCat->setBird(false);
                    tempCat->setFluffy(true);
                    return tempCat;
                }
                else{
                    Cat* tempCat=new Cat(Name, Type, Price, Weight,false);
                    tempCat->setCat(true);
                    tempCat->setBird(false);
                    tempCat->setFluffy(true);
                    return tempCat;
                }
            }
        }

};

#endif	/* PETBUILDER_H */

