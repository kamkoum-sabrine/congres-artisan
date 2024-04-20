#ifndef RESPENSABLE_H_INCLUDED
#define RESPENSABLE_H_INCLUDED
#include<iostream>
#include"personne.h"
#include"evaluation.h"
#include<set>
#include<list>
#include<string>
#include<iostream>
using namespace std;
class respensable :public personne
{
  public :
    string role;
    set<string> tasks;
    list<int*> sessions;
  public :
    /** Constructeurs et destructeurs **/
    respensable(){} //Constructeur sans parametres
    respensable(string ,int ,string ,string  ,int  ,string ,string ,int ); //Constructeur avec parametres
    respensable(const respensable &); //Constructeur par recopie
    respensable & operator=(const respensable &); //Surcharge operateur =
    ~respensable(); //destructeur

    /** Getters **/

    list<int*> getsessions() { return sessions; }
    string getrole() { return role; }
    set<string> gettasks() { return tasks; }

    /** Setters **/

    void setrole(string role) { this->role = role; }
    void settasks(set<string> tasks) { this->tasks = tasks; }
    void setSessions(list<int*> sessions) { this->sessions = sessions; }

    /** Gerer les sessions **/
    void ajouter_session(int*);
    void supprimer_session();


    void afficherPersonne();
    void modifier();

    void saisir_respensable();

    /** Surcharge des operateurs **/
    friend ostream& operator<<(ostream&, const respensable&); //Surcharge operateur <<
    friend istream& operator>>(istream&,respensable&); //Surcharge operateur >>

    /**Calculer le nombre d'ans de travail d'un responsable à partir de l'attribut sessions **/
    int calculerExperience();

    /** Methode qui annonce le resultat du congrès **/
    void afficherArtisanGagnant( vector<evaluation>& ) ;

    /**Enregister responsable dans un fichier texte**/
    void ecrireResponsableDansFichier();
};

#endif // RESPENSABLE_H_INCLUDED
