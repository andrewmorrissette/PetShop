/* 
 * File:   Fish.h
 * Authors:
 * bednarz4
 * morri597
 *
 * Created on February 20, 2018, 12:10 AM
 */

#include "Pet.h"
#ifndef FISH_H
#define	FISH_H
/*
 * CODE USED FROM PROJECT 1 DO NOT TOUCH
*/
class Fish: public Pet{
    public:
        Fish(const string& name, const string& type,const float& price,const unsigned int& weight,string e):
        Pet(name,type,price,weight),environment(e){}
        
        void setEnvironmentFish(string e){environment = e;}
        string getEnvironmentFish(){return environment;}
        
        Fish(const Fish& f){
            if(this!=&f){
                name = f.name;
                type = f.type;
                weight = f.weight;
                price = f.price;
                environment = f.environment;
                cout<<"In Fish Copy Constructor"<<endl;
            }
            else{
                cout<<"In Fish Copy Constructor: Self-copying"<<endl;
            }
        }
        
        Fish& operator=(const Fish& f){
            if (this!=&f){
                name = f.name;
                type = f.type;
                weight = f.weight;
                price = f.price;
                environment = f.environment;
                cout<<"In Fish Assignment"<<endl;
            }
            else cout<<"In Fish Assignment: Self-copying"<<endl;
        }
        
    protected:
        virtual void print()const{
            cout<<"name: "<<name<<" type: "<<type<<" weight: "<<weight<<" price: "<<price<<" ";
            cout<<"Environment: "<<environment<<endl;
        }
        string environment;
};


#endif	/* FISH_H */

