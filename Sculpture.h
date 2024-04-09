#ifndef SCULPTURE_H_INCLUDED
#define SCULPTURE_H_INCLUDED
#include "Creation.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Sculpture :public Creation
{
  protected :
    ///int nbMateriaux;
    vector<string*> materiaux;
  public :
    Sculpture() ;
    Sculpture(int id, string nom, string description);
    Sculpture(const Sculpture &);
    ~Sculpture();

    vector<string*> getMateriaux();
    void setMateriaux(vector<string*>);

    void ajouterMateriaux(string*);
    void afficher();
    void modifier();
};


#endif // SCULPTURE_H_INCLUDED
