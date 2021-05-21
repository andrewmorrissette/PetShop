/* 
 * File:   SearchableVector.h
 * Author: morri597
 * Bednarz4
 *
 * Created on February 24, 2018, 12:41 PM
 */

#ifndef SEARCHABLEVECTOR_H
#define	SEARCHABLEVECTOR_H

class SearchableVector{
public:
//Functions that are needed for bubble sort
    
    virtual unsigned int getSize() const = 0;
    virtual unsigned int CompareAt(int index) = 0;
    
};


#endif	/* SEARCHABLEVECTOR_H */

