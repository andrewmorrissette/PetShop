/* 
 * File:   laptop.h
 * Author: morri597
 *
 * Created on March 9, 2018, 3:33 PM
 */

#ifndef LAPTOP_H
#define	LAPTOP_H

class Laptop: public Items{
    protected:
        string m_memory;
    public:
        
        Laptop(string name, double price,string memory): Items(name,price){m_memory=memory;}
        virtual ~Laptop(){}
        virtual void print() const{
            cout<<"(Laptop name="<<m_name<<",Laptop price="<<m_price<<");";
        }
    
};



#endif	/* LAPTOP_H */

