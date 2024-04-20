#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class personne
{
    protected :
      int Cin;
      string nom;
      string prenom;
      int tel;
      string email;
      string adresse;
      vector<string> langues;
      int nblangues;
    public :
        /** Constructeurs et destructeurs **/
        personne(){}//constructeur sans parametres
        personne(int,string,string,int,string,string,int);//constructeur avec parametres
        personne(const personne &);//constructeur par recopie
        virtual ~personne(){};//destructeur

        /** Getters **/
        int getcin(){ return Cin; }
        string getnom(){ return nom; }
        string getprenom(){ return prenom; }
        int gettel(){ return tel; }
        string getemail(){ return email; }
        string getadresse(){ return adresse; }
        vector<string> getlangues(){ return langues; }

        /** Setters **/
        void setcin(int Cin){ this->Cin = Cin; }
        void setnom(string nom){ this->nom = nom; }
        void setprenom(string prenom){ this->prenom = prenom; }
        void settel(int tel){ this->tel = tel; }
        void setemail(string email){ this->email = email; }
        void setadresse(string adresse) { this->adresse = adresse; }
        void setnblangues(int nblangues) { this->nblangues = nblangues; }
        /** Methode virtuelle **/
        virtual void afficherPersonne();

        /** Methode virtuelle pure **/
        virtual void modifier()=0;

        /**Ajouter langues **/
        void saisirlangues();

        /**Supprimer langue **/
        void supprimer_langue( );


        void saisir_personne();

        /**Surcharge des operateurs**/
        friend ostream& operator<<(ostream&,const personne &);
        friend istream& operator>>(istream& ,personne&);


};



#endif // PERSONNE_H_INCLUDED
