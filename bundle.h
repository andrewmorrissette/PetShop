/* 
 * File:   bundle.h
 * Author: morri597
 *
 * Created on March 9, 2018, 3:45 PM
 */

#ifndef BUNDLE_H
#define	BUNDLE_H
#include "Pet.h"
class Bundle: public Pet{
    protected:
        vector<Pet*> BundledPets;
        float m_discountedPrice;
        string m_bundleName;
        int m_savings;

    public:
        Bundle(string name, float discount){m_bundleName = name; m_discountedPrice=discount;}
        virtual ~Bundle(){
            for(unsigned int i=0; i<BundledPets.size(); i++) delete BundledPets[i];
        }
        void addItem(Pet* pet){
            BundledPets.push_back(pet);
            cout<<endl;
            cout<<"Bundle Name:"<<m_bundleName;
            double wholesalePrice=0;
            for(unsigned int i=0;i<BundledPets.size();i++){
                string Name = BundledPets[i]->getName();
                cout<<"Pet Name: "<<Name<<endl;
                float p = BundledPets[i]->getPrice();
                cout<<p<<endl;
                wholesalePrice += BundledPets[i]->getPrice();
            }
            float differencePrice = wholesalePrice - m_discountedPrice;
            cout<<"Wholesale Price: "<<wholesalePrice<<endl;
            cout<<"Discounted Price: "<<m_discountedPrice<<endl;
            cout<<"Difference: "<<differencePrice<<endl;
            float percentage = (differencePrice/wholesalePrice)*100;
            m_savings = percentage;
            cout<<"Savings: "<<m_savings<<endl;
        }
        virtual void print()const{}
        string getBundleName(){return m_bundleName;}
        float getDiscountedPrice(){return m_discountedPrice;}
        int getSavings(){return m_savings;}
            
};

#endif	/* BUNDLE_H */

