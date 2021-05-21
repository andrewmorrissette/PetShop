/* 
 * File:   BinarySearch.h
 * Author: morri597 & bednarz4
 *
 *
 * Created on February 8, 2018, 4:50 PM
 */

#ifndef SORTABLEVECTOR_H
#define	SORTABLEVECTOR_H


class SortableVector{
public:
    virtual unsigned int getSize() const = 0;
    virtual bool smaller(int i, int j) const = 0;
    virtual void swap(int i, int j) = 0;
};




#endif	/* SORTABLEVECTOR_H */

