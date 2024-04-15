#ifndef BRODERIE_H_INCLUDED
#define BRODERIE_H_INCLUDED
#include "Creation.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Broderie :public Creation
{
  protected :
    vector<string*> tissusUtilises;
  public :
    Broderie() ;
    Broderie(int id, string nom, string description);
    Broderie(const Broderie &);
    Broderie & operator=(const Broderie &);
    virtual ~Broderie(){
        for (unsigned i = 0; i <tissusUtilises.size(); ++i) {
        delete tissusUtilises[i];
        }
    };

    vector<string*> getTissusUtilises();
    void setTissusUtilises(vector<string*>);
    void ajouterTissus(string*);
    void saisirBroderie();
    virtual void afficher();
    void modifier();
    friend std::ostream& operator<<(std::ostream&, const Broderie& );
    friend istream& operator>>(istream&, Broderie& );
};


#endif // BRODERIE_H_INCLUDED
