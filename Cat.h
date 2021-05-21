/* 
 * File:   Cat.h
 * Authors:
 * bednarz4
 * morri597
 *
 * Created on February 20, 2018, 12:10 AM
 */

#include "Pet.h"
#ifndef CAT_H
#define	CAT_H
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
/*
 * CODE USED FROM PROJECT 1 DO NOT TOUCH
*/

class Cat: public Pet{
    public:
        Cat(const string& name, const string& type, const float& price,const unsigned int& weight,bool f):
        Pet(name,type,price,weight),fluffy(f){}
        
        void setFluffyCat(bool f){fluffy = f;}
        bool getFluffyCat(){return fluffy;}
        
        Cat(const Cat& c){
            if(this!=&c){
                name = c.name;
                type = c.type;
                price = c.price;
                weight = c.weight;
                fluffy = c.fluffy;
                cout<<"In Cat Copy Constructor"<<endl;
            }
            else{
                cout<<"In Cat Copy Constructor: Self-copying"<<endl;
            }
        }
        
        Cat& operator=(const Cat& c){
            if (this!=&c){
                name = c.name;
                type = c.type;
                price = c.price;
                weight = c.weight;
                fluffy = c.fluffy;
                cout<<"In Cat Assignment"<<endl;
            }
            else cout<<"In Cat Assignment: Self-copying"<<endl;
        }
        
    protected:
        virtual void print()const{
            cout<<"name: "<<name<<" type: "<<type<<" weight: "<<weight<<" price: "<<price<<" ";
            if(fluffy == true){
                cout<<"Fluffy: True"<<endl;
            }
            else{
                cout<<"Fluffy: False"<<endl;
            }
        }
        bool fluffy;
};


#endif	/* CAT_H */

