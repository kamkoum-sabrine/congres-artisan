#ifndef ARTISAN_H_INCLUDED
#define ARTISAN_H_INCLUDED
#include<vector>
#include<string>
#include<iostream>
#include <fstream>
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
    Artisan(int, string, string, int, string, string, string,int);
    Artisan(const Artisan &);
    Artisan & operator=(const Artisan &);
    virtual ~Artisan();
    string getSpecialite();
    void setSpecialite(string);
    vector<Creation*> getCreations();
    void ajouterCreation(Creation*);
    void modifier();
    virtual void afficher();
    void saisirArtisan();
    friend std::ostream& operator<<(std::ostream& os, const Artisan& a);
    friend istream& operator>>(istream&,Artisan&);
     void enregistrer();
     int nombreDeCreations() const;
};
#endif // ARTISAN_H_INCLUDED
