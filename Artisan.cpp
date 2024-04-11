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
using namespace std;
Artisan::Artisan()
{

}

Artisan::Artisan(int cin, string nom, string prenom, int tel, string email, string adresse, string specialite)
    : personne(cin, nom, prenom, tel, email, adresse){
    this->specialite = specialite;
}
Artisan::Artisan(const Artisan &ar)
{
    specialite = ar.specialite;
    creations.resize(ar.creations.size());
   /** for (unsigned int i=0;i<ar.creations.size();i++){
        creations[i] = ar.creations[i];
    }**/
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
Artisan::~Artisan() {
     for (unsigned i = 0; i <creations.size(); ++i) {
        delete creations[i];
    }
    }
void Artisan::ajouterCreation(Creation*  c){
    ///creations.push_back(c);
     if (typeid(*c)== typeid(Sculpture)){
            this->creations.push_back(new Sculpture(*static_cast<Sculpture*>(c)));
        }
        else {
            if (typeid(*c)== typeid(Broderie)){
            this->creations.push_back(new Broderie(*static_cast<Broderie*>(c)));
        }
        else {
            this->creations.push_back(new Bijouterie(*static_cast<Bijouterie*>(c)));
        }

        }
}
void Artisan::afficher()
{
    personne::afficher();
    cout<<"Specialite : "<<specialite<<endl;
    cout<<"Affichage des creations : "<<endl;
    for(int i =0;i<creations.size();i++)
    {
        cout<<"Creation n:"<<i+1<<endl;


         if (typeid(*(creations[i]))== typeid(Broderie)){
             Broderie *b = new Broderie(*static_cast<Broderie*>(creations[i]));
             b->afficher();
         }
         else {
             if (typeid(*(creations[i]))== typeid(Sculpture)){
             Sculpture *s = new Sculpture(*static_cast<Sculpture*>(creations[i]));
             s->afficher();
             }
             else {
                Bijouterie *bij = new Bijouterie(*static_cast<Bijouterie*>(creations[i]));
             bij->afficher();
             }
         }
         }
        /** if (typeid(*(creations[i]))== typeid(Sculpture)){
            this->creations->afficher();
        }**/
    }

void Artisan::editer()
{
    cout<<"Mise à jour d'un artisan "<<endl;
   char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? N: Nom, P: Prenom, T :numéro de téléphone , A : adresse de résidence , M : adresse mail  , S : Specialite, C: Creations"<<endl;
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
              cout<<"saisir le nouveau numéro de telephone : "<<endl;
              cin>>tel;
            break;
            case 'A':
             cout<<"saisir la nouvelle adresse de résidence : "<<endl;
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
                cout << "Saisissez la position de la création à modifier : ";
                cin >> position;
                if (position < 0 || position >= creations.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    creations[position]->modifier();
                }
                break;
          break;
            default :
              cout<<"réponse invalide !"<<endl;
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

