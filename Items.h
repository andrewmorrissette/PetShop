/* 
 * File:   Items.h
 * Author: morri597
 *
 * Created on March 9, 2018, 3:26 PM
 */

#ifndef ITEMS_H
#define	ITEMS_H
class Items{
public:
   string m_name;
   float m_price;
   virtual void print() const = 0;
protected:
   Items(string name,float p){
        m_name = name;
        m_price = p;
    }
};


#endif	/* ITEMS_H */

