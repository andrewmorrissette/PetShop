/* 
 * File:   Dog.h
 * Authors:
 * bednarz4
 * morri597
 *
 * Created on February 19, 2018, 11:53 PM
 */
#include "Pet.h"
#ifndef DOG_H
#define	DOG_H
/*
 * CODE USED FROM PROJECT 1 DO NOT TOUCH
*/

class Dog: public Pet{
    public:
        Dog(const string& name, const string& type, const float& price,const unsigned int& weight,string b):
        Pet(name,type,price,weight),breed(b){}
        
        void setBreedDog(string b){breed = b;}
        string getBreedDog(){return breed;}
        
        Dog(const Dog& d){
            if(this!=&d){
                name = d.name;
                type = d.type;
                weight = d.weight;
                price = d.price;
                breed = d.breed;
                cout<<"In Dog Copy Constructor"<<endl;
            }
            else{
                cout<<"In Dog Copy Constructor: Self-copying"<<endl;
            }
        }
        
        Dog& operator=(const Dog& d){
            if (this!=&d){
                name = d.name;
                type = d.type;
                weight = d.weight;
                price = d.price;
                breed = d.breed;
                cout<<"In Dog Assignment"<<endl;
            }
            else cout<<"In Dog Assignment: Self-copying"<<endl;
        }
        
    protected:
        virtual void print()const{
            cout<<"name: "<<name<<" type: "<<type<<" weight: "<<weight<<" price: "<<price<<" ";
            cout<<"Breed: "<<breed<<endl;
        }
        string breed;
};



#endif	/* DOG_H */

