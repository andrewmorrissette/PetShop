/* 
 * File:   SortableBreedVector.h
 * Author: morri597
 * Bednarz4
 *
 * Created on February 24, 2018, 1:47 PM
 */

#ifndef SORTABLEPRICEVECTOR_H
#define	SORTABLEPRICEVECTOR_H
#include "SortableVector.h"

class PetDatabaseSortableByPrice: public SortableVector {
protected:
    vector <Pet*> m_priceVector;
public:   
    PetDatabaseSortableByPrice(){}
    PetDatabaseSortableByPrice(PetDatabaseSortableByPrice* p_ptr){} 
    PetDatabaseSortableByPrice(const vector<Pet*>& pets){
        for(int i =0;i<pets.size();i++){
            m_priceVector.push_back(pets[i]);
        }
    }
    vector <Pet*> getVector(){return m_priceVector;}
    virtual unsigned int getSize() const {
        return m_priceVector.size();
    }
    
    virtual bool smaller(int i, int j) const {
        if(getPrice(i) < getPrice(j))
            return true;
        else
            return false;
    }
    
    virtual void swap(int i, int j){
        Pet* temp = m_priceVector[i];
        m_priceVector[i]=m_priceVector[j];
        m_priceVector[j]=temp;
    }
    
    virtual void DisplayRecords() const {
        for(int i=0; i<getSize(); i++){
            m_priceVector[i]->print();
            cout<<endl;
        }
    }
    
    //This function will change each type of Pet
    double getPrice(int i) const{
        return m_priceVector[i]->getPrice();
    }
    
    /*int insertInteger(int element) {
        m_priceVector.push_back(element);
    }*/
    
};


#endif	/* SORTABLEBREEDVECTOR_H */

