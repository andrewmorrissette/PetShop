/* 
 * File:   Builder.h
 * Author: morri597
 * Source: Based code off of Professor Alex Liu's and modified it to fit assignment
 *
 * Created on March 22, 2018, 3:30 AM
 */

#ifndef BUILDER_H
#define	BUILDER_H
using namespace std;
#include <string>
#include <vector>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"

/*
 * Main Builder Class.
 * Pure Virtual Functions
 * Builder Class will Build each Pet & Place in a Pets Vector (Which acts as a system DB).
 **/

class Builder{
public:
    virtual void addClass(string Class)=0;
    virtual void addName(string Name)=0;
    virtual void addType(string Type)=0;
    virtual void addWeight(string Weight)=0;
    virtual void addPrice(string Price)=0;
    virtual Pet* addSpecial(string Special)=0;
};



#endif	/* BUILDER_H */

