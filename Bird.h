/* 
 * File:   Bird.h
 * Authors:
 * bednarz4
 * morri597
 *
 * Created on February 20, 2018, 12:10 AM
 */

#include <iomanip>
#include "Pet.h"
#ifndef BIRD_H
#define	BIRD_H
/*
 * CODE USED FROM PROJECT 1 DO NOT TOUCH
*/
class Bird: public Pet{
    public:
        Bird(const string& name, const string& type, const float& price, const unsigned int& weight, bool n):
        Pet(name,type,price,weight),nocturnality(n){}
        
        void setNocturnalityBird(bool n){nocturnality = n;}
        bool getNocturnalityBird(){return nocturnality;}
        
        Bird(const Bird& b){
            if(this!=&b){
                name = b.name;
                type = b.type;
                weight = b.weight;
                price = b.price;
                nocturnality = b.nocturnality;
                cout<<"In Bird Copy Constructor"<<endl;
            }
            else{
                cout<<"In Bird Copy Constructor: Self-copying"<<endl;
            }
        }
        
        Bird& operator=(const Bird& b){
            if (this!=&b){
                name = b.name;
                type = b.type;
                weight = b.weight;
                price = b.price;
                nocturnality = b.nocturnality;
                cout<<"In Bird Assignment"<<endl;
            }
            else cout<<"In Bird Assignment: Self-copying"<<endl;
        }
        
    protected:
        virtual void print() const{
            cout<<std::fixed<<std::setprecision(2)<<"name: "<<name<<" type: "<<type<<" weight: "<<weight<<" price: "<<price<<" ";
            if(nocturnality == true){
                cout<<"Nocturnality: True"<<endl;
            }
            else{
                cout<<"Nocturnality: False"<<endl;
            }
            
        }
        bool nocturnality;
};


#endif	/* BIRD_H */

