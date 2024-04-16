#ifndef EMPLOYE_H_INCLUDED
#define EMPLOYE_H_INCLUDED
#include"personne.h"
#include"Artisan.h"

using namespace std;
class Employe :public personne
{
  protected :
    int numGuichet;
    vector<Artisan *> artisans;
    vector<personne *> participants;
  public :
    Employe() ;
    Employe(int numGuichet,int c,string n,string p ,int t ,string e,string a, int nbL);
    Employe(const Employe &);
    int getNumGuichet();
   vector<Artisan*> getArtisans();
   vector<personne*> getParticipants();
    void setNumGuichet(int);
    void setArtisans(vector<Artisan*>);
    void setParticipants(vector<personne*>);
   /// void saisir_sessions(vector<int*>);
    void ajouter_artisan(Artisan *);
    ///void supprimer_artisan();
    void ajouter_participant(personne *);
   /// void supprimer_participant();
    void afficherPersonne();
    void modifier();
    ~Employe();
    Employe & operator=(const Employe &);
    void saisir_employe();
    friend ostream& operator<<(ostream&,Employe&);
    friend istream& operator>>(istream&,Employe&);
};



#endif // EMPLOYE_H_INCLUDED
