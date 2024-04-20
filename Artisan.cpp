#include"Creation.h"
#include"Sculpture.h"
#include"Bijouterie.h"
#include"Broderie.h"
#include"personne.h"
#include"Artisan.h"
#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include <fstream>
#include <cstdlib>
using namespace std;
Artisan::Artisan()
{

}

Artisan::Artisan(int cin, string nom, string prenom, int tel, string email, string adresse, string specialite,int nbLangues)
    : personne(cin, nom, prenom, tel, email, adresse,nbLangues){
    this->specialite = specialite;
}
Artisan::Artisan(const Artisan &ar) :personne(ar), specialite(ar.specialite)
{
    creations.resize(ar.creations.size());
     for (unsigned i=0; i<ar.creations.size();i++)
    {
        if (typeid(*(ar.creations[i]))== typeid(Sculpture)){
            this->creations.push_back(new Sculpture(*static_cast<Sculpture*>(ar.creations[i])));
        }
        else {
            if (typeid(*(ar.creations[i]))== typeid(Broderie)){
            this->creations.push_back(new Broderie(*static_cast<Broderie*>(ar.creations[i])));
        }
        else {
            this->creations.push_back(new Bijouterie(*static_cast<Bijouterie*>(ar.creations[i])));
        }

        }
    }
}

Artisan  & Artisan::operator=(const Artisan& ar) {
    if (this != &ar) {
        personne::operator=(ar);
        specialite = ar.specialite;

        creations.clear();
        for (unsigned i=0; i<ar.creations.size();i++)
        {
            if (typeid(*(ar.creations[i]))== typeid(Sculpture)){
                this->creations.push_back(new Sculpture(*static_cast<Sculpture*>(ar.creations[i])));
            }
            else {
                if (typeid(*(ar.creations[i]))== typeid(Broderie)){
                this->creations.push_back(new Broderie(*static_cast<Broderie*>(ar.creations[i])));
            }
            else {
                this->creations.push_back(new Bijouterie(*static_cast<Bijouterie*>(ar.creations[i])));
            }

            }
        }
    }
    return *this;
}
Artisan::~Artisan() {
     for (unsigned i = 0; i <creations.size(); ++i) {
        delete creations[i];
    }
}
void Artisan::saisirArtisan()
{
    cout<<endl<<"--------- Saisir Artisan --------"<<endl;
    personne::saisir_personne();
    cout<<"Specialite : ";
    cin>>specialite;
}
void Artisan::ajouterCreation(Creation*  c){
    creations.push_back(c);
}
void Artisan::afficher()
{
    personne::afficherPersonne();
    cout<<"Specialite : "<<specialite<<endl;
    cout<<"Affichage des creations : "<<endl;
    for(int i =0;i<creations.size();i++)
    {
        cout<<"Creation n:"<<i+1<<endl;
        cout<<*creations[i];
    }
}
std::ostream& operator<<(std::ostream& o,const Artisan& a )
{
    o<<endl<<"-------------"<<"Affichage artisan "<<"------------"<<endl;
    o << static_cast<const personne &>(a);
    o<<"Specialite : "<<a.specialite<<endl;
    o<<"Affichage des creations : "<<endl;
    o<<"Nombre de creations "<<a.creations.size()<<endl;
    for(int i =0;i<a.creations.size();i++)
    {
        o<<"Creation n:"<<i+1<<endl;
        o<<*(a. creations[i]);

        if (typeid(*(a.creations[i]))== typeid(Broderie)){
             Broderie *b = new Broderie(*static_cast<Broderie*>(a.creations[i]));
             o << *b;
         }
         else {
             if (typeid(*(a.creations[i]))== typeid(Sculpture)){
             Sculpture *s = new Sculpture(*static_cast<Sculpture*>(a.creations[i]));
             o << *s;
             }
             else {
                Bijouterie *bij = new Bijouterie(*static_cast<Bijouterie*>(a.creations[i]));
                o << *bij;
             }
         }
         }

    return o;
}
istream& operator>>(istream &in, Artisan &a)
{
     cout<<endl<<"--------- Saisir Artisan --------"<<endl;
    // Utiliser la surcharge de l'op�rateur >> de la classe personne
    in >> static_cast<personne&>(a);
    cout<<"Specialite : ";
    in >>a.specialite;

    return in;
}

void Artisan::modifier()
{
    cout<<"Mise � jour d'un artisan "<<endl;
   char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? N: Nom, P: Prenom, T :num�ro de t�l�phone , A : adresse de r�sidence , M : adresse mail  , S : Specialite, C: Creations"<<endl;
        cin>>rep;
        switch(rep)
        {
            case 'N':
              cout<<"saisir le nouveau nom : "<<endl;
              cin>>nom;
            break;
            case 'P':
              cout<<"saisir le nouveau prenom : "<<endl;
              cin>>prenom;
            break;
            case 'T':
              cout<<"saisir le nouveau num�ro de telephone : "<<endl;
              cin>>tel;
            break;
            case 'A':
             cout<<"saisir la nouvelle adresse de r�sidence : "<<endl;
             cin>>adresse;
             break;
            case 'M':
              cout<<"saisir la nouvelle adresse mail : "<<endl;
              cin>>email;
            break;
            case 'S' :
              cout<<"saisir la nouvelle specialite : "<<endl;
              cin>>specialite;
              break;
          case 'C' :
          int position;
                cout << "Saisissez la position de la cr�ation � modifier : ";
                cin >> position;
                if (position < 0 || position >= creations.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    creations[position]->modifier();
                }
                break;
          break;
            default :
              cout<<"r�ponse invalide !"<<endl;
              break;


        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');

}

vector<Creation*> Artisan::getCreations()
{
    return creations;
}
string Artisan::getSpecialite()
{
    return specialite;
}
void Artisan::setSpecialite(string specialite)
{
    this->specialite = specialite;
}

void Artisan::enregistrer()
{
     ofstream fichier ("artisansDB.txt",ios::app);
    if (!fichier)
        cout << "erreur"<<endl ;
    fichier<<*this ;
    fichier.close();

}

// Impl�mentation de la m�thode pour obtenir le nombre de cr�ations pour cet artisan
int Artisan::nombreDeCreations() const {
    return creations.size();
}
