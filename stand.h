#ifndef STAND_H_INCLUDED
#define STAND_H_INCLUDED
#include"Artisan.h"
#include<iostream>
#include<string>
#include <map>
using namespace std;
class stand
{
    int id_stand;
    string emplacement;
    map<string, pair<string, string> > horaires;
    Artisan artisan;
    vector<string> jours;

  public :
     stand();
     stand(int,string,Artisan,map<string, pair<string, string> >);
     void setId(int);
     int getId();
     map<string, pair<string, string> > getHoraires(){return horaires;}
     void setHoraires(map<string, pair<string, string> > horaires){ this->horaires = horaires;}
     void  setEmplacement(string emplacement){
        this->emplacement = emplacement;
     }
    string get_emplacement(){
        return emplacement;
    }
    void  setArtisan(Artisan& artisan){
        this->artisan = artisan;
    }
    Artisan get_artisan(){
        return artisan;
    }

     void editerStand();
     void afficherStand();
     string getEmplacement();
     void saisir_stand();
     friend ostream& operator<<(ostream& , stand&);
     friend istream& operator>>(istream&, stand&);
     ~stand();
    bool estOuvert(const string& heure_actuelle, const string& jour);
};
#endif // STAND_H_INCLUDED
