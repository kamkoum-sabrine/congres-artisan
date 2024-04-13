#ifndef ARTISAN_H_INCLUDED
#define ARTISAN_H_INCLUDED
#include<vector>
#include<string>
#include<iostream>
#include"personne.h"
#include"Creation.h"
using namespace std;
class Artisan :public personne
{
  protected :
    string specialite;
    vector<Creation*> creations;
  public :
     Artisan() ;
     Artisan(int, string, string, int, string, string, string);
    Artisan(const Artisan &);
    Artisan & operator=(const Artisan &);
    virtual ~Artisan();
    string getSpecialite();
    void setSpecialite(string);
    vector<Creation*> getCreations();
    void ajouterCreation(Creation*);
    void editer();
    virtual void afficher();
};
#endif // ARTISAN_H_INCLUDED
