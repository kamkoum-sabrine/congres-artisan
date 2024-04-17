#ifndef SCULPTURE_H_INCLUDED
#define SCULPTURE_H_INCLUDED
#include "Creation.h"
#include<vector>
#include<list>
#include<string>
#include<iostream>
using namespace std;
class Sculpture :public Creation
{
  protected :
    list<string*> materiaux;
  public :
    Sculpture() ;
    Sculpture(int id, string nom, string description);
    Sculpture(const Sculpture &);
    virtual ~Sculpture(){};
    Sculpture & operator=(const Sculpture &);
    list<string*> getMateriaux();
    void setMateriaux(list<string*>);

    void ajouterMateriaux(string*);
    void saisirSculpture();
    virtual void afficher();
    void modifier();
    friend std::ostream& operator<<(std::ostream&, const Sculpture& );
    friend istream& operator>>(istream&, Sculpture& );
};


#endif // SCULPTURE_H_INCLUDED
