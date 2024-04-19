#ifndef EMPLOYE_H_INCLUDED
#define EMPLOYE_H_INCLUDED
#include"personne.h"
#include"Participant.h"
#include"Artisan.h"
#include"evaluation.h"
///#include"evaluation.cpp"
using namespace std;
class Employe :public personne
{
  protected :
    int numGuichet;
    vector<Artisan *> artisans;
    vector<Participant *> participants;
    vector<evaluation> evaluations;
  public :
    Employe() ;
    Employe(int numGuichet,int c,string n,string p ,int t ,string e,string a, int nbL);
    Employe(const Employe &);
    int getNumGuichet();
    vector<Artisan*> getArtisans();
    vector<Participant*> getParticipants();
    vector<evaluation> getEvaluation(){return evaluations;}
    void setNumGuichet(int);
    void setArtisans(vector<Artisan*>);
    void setParticipants(vector<Participant*>);
    void setEvaluation(vector<evaluation> evaluations){this->evaluations = evaluations;}
    /// void saisir_sessions(vector<int*>);
    void ajouter_artisan(Artisan *);
    void ajouter_evaluation();
    ///void supprimer_artisan();
    void ajouter_participant(Participant *);
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
