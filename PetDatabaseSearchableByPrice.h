/* 
 * File:   SearchableNameVector.h
 * Author: morri597
 * Bednarz4
 *
 * Created on February 24, 2018, 1:56 PM
 */

#include "PetDatabaseSortableByPrice.h"
#include "SearchableVector.h"

#ifndef SEARCHABLEPRICEVECTOR_H
#define	SEARCHABLEPRICEVECTOR_H

class PetDatabaseSearchableByPrice: public PetDatabaseSortableByPrice, public SearchableVector{
protected:
    float m_Query;
public:
    PetDatabaseSearchableByPrice(PetDatabaseSortableByPrice* p_ptr){
        m_priceVector = p_ptr->getVector();
    }

    void setQuery(double Query){
        m_Query = Query;
    }

    virtual unsigned int getSize() const {
        return m_priceVector.size();
    }

    virtual unsigned int CompareAt(int i){
        if(m_priceVector[i]->getPrice()<m_Query){
            return 0;
        }
        else if (m_priceVector[i]->getPrice()==m_Query){
            return 1;
        }
        else if (m_priceVector[i]->getPrice()>m_Query){
            return 2;
        }
    }
    

    
    virtual Pet* getPet(unsigned int index){return m_priceVector[index];}

};

#endif	/* SEARCHABLENAMEVECTOR_H */

