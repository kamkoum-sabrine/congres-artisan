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
    vector<string*> materiaux;
  public :
    Sculpture() ;
    Sculpture(int id, string nom, string description);
    Sculpture(const Sculpture &);
    virtual ~Sculpture(){};
    Sculpture & operator=(const Sculpture &);
    vector<string*> getMateriaux();
    void setMateriaux(vector<string*>);

    void ajouterMateriaux(string*);
    virtual void afficher();
    void modifier();
    friend std::ostream& operator<<(std::ostream&, const Sculpture& );
};


#endif // SCULPTURE_H_INCLUDED
