#ifndef EMPLOYE_H_INCLUDED
#define EMPLOYE_H_INCLUDED
#include"personne.h"
#include"Participant.h"
#include"Artisan.h"
#include"evaluation.h"
using namespace std;
class Employe :public personne
{
  protected :
    int numGuichet;
    vector<Artisan *> artisans;
    vector<Participant *> participants;
    vector<evaluation> evaluations;
  public :
    /** Constructeurs et destructeurs **/
    Employe(){ numGuichet=-1; } //Constructeur sans parametres
    Employe(int numGuichet,int Cin,string nom,string prenom ,int tel ,string email,string adresse, int nblangues); //Constructeur avec parametres
    Employe(const Employe &);//Constructeur par recopie
    Employe & operator=(const Employe &); //Surcharge operateur =
    ~Employe(); //Desctructeur 
   
    /** Getters **/
    int getNumGuichet(){return numGuichet;}
    vector<Artisan*> getArtisans(){return artisans;}
    vector<Participant*> getParticipants(){return participants;}
    vector<evaluation> getEvaluation(){return evaluations;}

    /** Setters **/
    void setNumGuichet(int numGuichet){ this->numGuichet = numGuichet; }
    void setArtisans(vector<Artisan*> artisans){ this->artisans = artisans; }
    void setParticipants(vector<Participant*> participants) {this->participants = participants; }
    void setEvaluation(vector<evaluation> evaluations){this->evaluations = evaluations;}

    void ajouter_artisan(Artisan *);
    void ajouter_evaluation();
    void ajouter_participant(Participant *);

    void afficherPersonne();
    void modifier();
    
    void saisir_employe();
    /*** Surcharge des operateurs **/
    friend ostream& operator<<(ostream&,Employe&);
    friend istream& operator>>(istream&,Employe&);
};



#endif // EMPLOYE_H_INCLUDED
