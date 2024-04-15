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

Artisan::Artisan(int cin, string nom, string prenom, int tel, string email, string adresse, string specialite,int nbLangues)
    : personne(cin, nom, prenom, tel, email, adresse,nbLangues){
    this->specialite = specialite;
}
Artisan::Artisan(const Artisan &ar) :personne(ar), specialite(ar.specialite)
{
    ///specialite = ar.specialite;
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
    if (this != &ar) { // Check for self-assignment
        personne::operator=(ar); // Assign base class members using base class assignment operator
        specialite = ar.specialite;

        // Deep copy creations vector to avoid shallow copying
        creations.clear(); // Clear existing creations to prevent memory leaks
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
    /**cout<<"Saisir les créations :";
    int nbC;
    cout<<"saisir le nombre de créations :  "<<endl;
    cin>>nbC;
    for (int i=0;i<nbC;i++)
    {
        Creation *C = new Creation();
        cout<<"saisir la creation numero : "<<i+1<<endl;
        C->saisirCreation();
        creations.push_back(C);
    }**/
}
void Artisan::ajouterCreation(Creation*  c){
    creations.push_back(c);
   /** cout<<endl<<"Ajout Creation "<<c->getId()<<endl;
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

        }**/

}
void Artisan::afficher()
{
    personne::afficherPersonne();
    cout<<"Specialite : "<<specialite<<endl;
    cout<<"Affichage des creations : "<<endl;
    for(int i =0;i<creations.size();i++)
    {
        cout<<"Creation n:"<<i+1<<endl;


         /**if (typeid(*(creations[i]))== typeid(Broderie)){
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
         }**/
          ///creations[i]->afficher();
          cout<<*creations[i];
}
        /** if (typeid(*(creations[i]))== typeid(Sculpture)){
            this->creations->afficher();
        }**/
}
std::ostream& operator<<(std::ostream& o,const Artisan& a )
{
    o<<endl<<"-------------"<<"Affichage artisan "<<"------------"<<endl;

    ///cout << a;
    // Assuming there's an overloaded << for Personne (if Artisan inherits):
     /// static_cast<const personne&>(a) << o
     o << static_cast<const personne &>(a);
    o<<"Specialite : "<<a.specialite<<endl;
    o<<"Affichage des creations : "<<endl;
    o<<"Nombre de creations "<<a.creations.size()<<endl;
     for(int i =0;i<a.creations.size();i++)
    {
        o<<"Creation n:"<<i+1<<endl;
        o<<*(a.creations[i]);
    }
    /**for(int i =0;i<a.creations.size();i++)
    {
        o<<"Creation n:"<<i+1<<endl;
        if (typeid(*(a.creations[i]))== typeid(Broderie)){
             Broderie *b = new Broderie(*static_cast<Broderie*>(a.creations[i]));
             ///b->afficher();
             o << *b;
         }
         else {
             if (typeid(*(a.creations[i]))== typeid(Sculpture)){
             Sculpture *s = new Sculpture(*static_cast<Sculpture*>(a.creations[i]));
             ///s->afficher();
             o << *s;
             }
             else {
                Bijouterie *bij = new Bijouterie(*static_cast<Bijouterie*>(a.creations[i]));
                ///bij->afficher();
                o << *bij;
             }
         }
         }**/
        /** if (Broderie* broderie = dynamic_cast<Broderie*>(a.creations[i])) {
             Broderie* broderie = dynamic_cast<Broderie*>(a.creations[i]);
            // Appel de l'opérateur << pour Broderie
            ///o << *broderie;
            broderie->afficher();

        } else if (Sculpture* sculpture = dynamic_cast<Sculpture*>(a.creations[i])) {
            // Appel de l'opérateur << pour Sculpture
            Sculpture* sculpture = dynamic_cast<Sculpture*>(a.creations[i]);
            ///o << *sculpture;
            sculpture->afficher();
        } else if (Bijouterie* bijouterie = dynamic_cast<Bijouterie*>(a.creations[i])) {
            // Appel de l'opérateur << pour Bijouterie
            Bijouterie* bijouterie = dynamic_cast<Bijouterie*>(a.creations[i]);
            ///o << *bijouterie;
            bijouterie->afficher();
        } else {
            // Cas où le type de création est inconnu ou non géré
            o << "Type de création inconnu." << std::endl;
        }
    }**/
        /**if (typeid(*(a.creations[i]))== typeid(Broderie)){
             ///Broderie *b = new Broderie(*static_cast<Broderie*>(a.creations[i]));
             ///o << (*b);
             Broderie *b = new Broderie (*(static_cast< Broderie*>(a.creations[i])));
             o<<"Id ba3d dynamic cast "<<b->getId()<<endl;
             o << *(static_cast< Broderie*>(a.creations[i]));
             ///b->afficher();
         }
         else {
             if (typeid(*(a.creations[i]))== typeid(Sculpture)){
            /// Sculpture *s = new Sculpture(*static_cast<Sculpture*>(a.creations[i]));
            /// s->afficher();
            ///o << (*s);
            o << *(static_cast< Sculpture*>(a.creations[i]));
             }
             else {
                ///Bijouterie *bij = new Bijouterie(*static_cast<Bijouterie*>(a.creations[i]));
                ///bij->afficher();
                ///o << (*bij);
                o << *(static_cast< Bijouterie*>(a.creations[i]));
             }
         }**/
    ///cout << (*(a.creations[i]));

   ///}
    return o;
}
istream& operator>>(istream &in, Artisan &a)
{
     cout<<endl<<"--------- Saisir Artisan --------"<<endl;
    // Utiliser la surcharge de l'opérateur >> de la classe personne
    in >> static_cast<personne&>(a);
    cout<<"Specialite : ";
    in >>a.specialite;

    return in;
}
/**std::ostream& operator<<(std::ostream& o,const Artisan& a )
{
    o<<endl<<"-------------"<<"Affichage artisan "<<"------------"<<endl;

    ///cout << a;
    // Assuming there's an overloaded << for Personne (if Artisan inherits):
     /// static_cast<const personne&>(a) << o
     o << static_cast<const personne &>(a);
    o<<"Specialite : "<<a.specialite<<endl;
    o<<"Affichage des creations : "<<endl;
    o<<"Taille creations "<<a.creations.size()<<endl;
    for(int i =0;i<a.creations.size();i++)
    {
        o<<"Creation n:"<<i+1<<endl;

        cout << ((a.creations[i]));
         /**if (typeid(*(a.creations[i]))== typeid(Broderie)){
             o<<"Broder"<<endl;
             ///cout << *dynamic_cast<Broderie*>(a.creations[i]);
             Broderie *b = new Broderie(*static_cast<Broderie*>(a.creations[i]));
             b->afficher();
             ///cout << (b);
         }
         else {
             if (typeid(*(a.creations[i]))== typeid(Sculpture)){
             Sculpture *s = new Sculpture(*static_cast<Sculpture*>(a.creations[i]));
             o<<"sculp"<<endl;
              ///cout << *dynamic_cast<Sculpture*>(a.creations[i]);
            /// s->afficher();
             cout << (*s);
             }
             else {
                Bijouterie *bij = new Bijouterie(*static_cast<Bijouterie*>(a.creations[i]));
                o<<"bij "<<endl;
                 ///cout << *dynamic_cast<Bijouterie*>(a.creations[i]);
                bij->afficher();
                ///cout << (bij);
             }
         }
    }
    return o;
}**/

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

