#ifndef STAND_H_INCLUDED
#define STAND_H_INCLUDED
#include"Artisan.h"
#include<iostream>
#include<string>
using namespace std;
class stand
{
    int id_stand;
    string emplacement;
    string heure_ouverture;
    string heure_fermeture;
    Artisan artisan;

  public :
     stand();
     stand(int,string,string,string,Artisan);
     void setId(int);
     int getId();
     void set_heure_ouverture(string heure_ouverture){
        this->heure_ouverture = heure_ouverture;
     }
     string get_heure_ouverture(){
        return heure_ouverture;
     }
     void set_heure_fermeture(string heure_fermeture){
        this->heure_fermeture = heure_fermeture;
     }
     string get_heure_fermeture(){
        return heure_fermeture;
     }
     void  setEmplacement(string emplacement){
        this->emplacement = emplacement;
     }
    string get_emplacement(){
        return emplacement;
    }
    void  setArtisan(Artisan artisan){
        this->artisan = artisan;
    }
    Artisan get_artisan(){
        return artisan;
    }

     void editerStand();
     //void supprimerStand();
     void afficherStand();
     string getEmplacement();
     void saisir_stand();
     friend ostream& operator<<(ostream& ,const stand&);
     friend istream& operator>>(istream&, stand&);
     ~stand();
      bool estOuvert(string heure_actuelle) const;
};




#endif // STAND_H_INCLUDED
