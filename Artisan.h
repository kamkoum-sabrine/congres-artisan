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
    void editer();
    virtual void afficher();
    void saisirArtisan();
    friend std::ostream& operator<<(std::ostream& os, const Artisan& a);
    friend istream& operator>>(istream&,Artisan&);
    ///void ouvrirFichier(ofstream &es);
    ///void ecrireArtisansDansFichier(fstream &, Artisan &);
    void ecrireFichierTexte( std::string&,  std::string&);
     void enregistrer();
     void recuperer_fichier(const string&);
};
#endif // ARTISAN_H_INCLUDED
