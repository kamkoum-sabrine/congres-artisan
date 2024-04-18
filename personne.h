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
      int nblangues; // A vérifier
    public :
        personne();
        personne(int,string,string,int,string,string,int);//a verifier concernant l'initialisation de l'attribut langues
        personne(const personne &);
        virtual ~personne(){};
        int getcin(); // methode qui retourne le num de cin de la personne
        string getnom(); //methode qui retourne le nom de la personne
        string getprenom(); // methode qui retourne le prenom de la personne
        int gettel(); //methode qui retourne le numero de telephone de la personne
        string getemail(); //methode qui retourne l email de la personne
        string getadresse(); //methode qui retourne l adresse de residence de la personne
        void getlangues(); //methode qui affiche les langues maitrisées par la personne
        void setcin(int); //methode qui permet le saisie de num de cin de la personne
        void setnom(string);//methode qui permet le saisie du nom de la personne
        void setprenom(string);//méthode qui permet le saisie du prénom de la personne
        void settel(int);//
        void setemail(string);
        void setadresse(string);
        virtual void afficherPersonne();
        ///virtual void modifier();
         virtual void modifier()=0;
          void setnblangues(int);
         void saisirlangues();
         void ajouterLangue();
         void supprimer_langue( );
         void saisir_personne();
         friend ostream& operator<<(ostream&,const personne &);
         friend istream& operator>>(istream& ,personne&);


};



#endif // PERSONNE_H_INCLUDED
