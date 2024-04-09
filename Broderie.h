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
    ~Broderie();

    vector<string*> getTissusUtilises();
    void setTissusUtilises(vector<string*>);

    void ajouterTissus(string*);
    void afficher();
    void modifier();
};


#endif // BRODERIE_H_INCLUDED
