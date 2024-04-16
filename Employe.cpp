#include"Employe.h"
#include"personne.h"
#include"Artisan.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Employe::Employe():personne()
{

}
void Employe::saisir_employe()

{
    personne::saisir_personne();
    int nbArtisans;
    cout<<"saisir le num guichet : "<<endl;
    cin>>numGuichet;
    cout<<"saisir le nombre des artisans : "<<endl;
    cin>>nbArtisans;
    Artisan *A = new Artisan();
    for (int i = 0; i < nbArtisans; i++) {
        ///int* session = new int; // Allouer dynamiquement un nouvel entier
        cout << "Saisir l'artisan numero " << i+1 << " : ";
        cin >> *A;
        ///cin >> *session;
        artisans.push_back(A);
    }
    int nbParticipants;
    cout<<"saisir le nombre des participants : "<<endl;
    cin>>nbParticipants;
    personne *p = new personne();
    for (int i = 0; i < nbParticipants; i++) {
        ///int* session = new int; // Allouer dynamiquement un nouvel entier
        cout << "Saisir le participant numero " << i+1 << " : ";
        cin >> *p;
        ///cin >> *session;
        participants.push_back(p);
    }
}
Employe::Employe(int numGuichet,int c,string n,string p ,int t ,string e,string a,int nblg ):personne(c,n,p,t,e,a,nblg)
{

    this->numGuichet=numGuichet;
}
void Employe::afficherPersonne()
{
    personne::afficherPersonne();
    cout<<"le num guichet : "<<numGuichet<<endl;
    cout<<"Affichage des artisans : "<<endl;
    for(int i =0;i<artisans.size();i++)
    {
        cout<<"Artisan numero "<<i+1<<endl;
        cout<<*(artisans[i])<<endl;
    }
}
void Employe::modifier() {
    // Appeler d'abord la methode modifier de la classe de base personne
    personne::modifier();

    char reponse;
    do {
        cout << "Que voulez-vous modifier pour cet employe ?" << endl;
        cout << "G : Num Guichet, Q : Quitter" << endl;
        cin >> reponse;

        switch (toupper(reponse)) {
            case 'G':
                cout << "Saisir le nouveau num guichet : ";
                cin >> numGuichet;
                break;

            case 'Q':
                return; // Quitter la methode
            default:
                cout << "Reponse invalide !" << endl;
        }

        do {
            cout << "Voulez-vous encore modifier ? O : OUI, N : NON" << endl;
            cin >> reponse;

            if (toupper(reponse) != 'O' && toupper(reponse) != 'N') {
                cout << "Reponse invalide !" << endl;
            }
        } while (toupper(reponse) != 'O' && toupper(reponse) != 'N');

    } while (toupper(reponse) == 'O');
}


Employe::Employe(const Employe &e):personne(e)
{
    numGuichet=e.numGuichet;

    for(int i=0;i<e.artisans.size();i++)

    {
        Artisan *artisan;
        artisan=e.artisans[i];
        artisans.push_back(artisan);
    }

}
int Employe::getNumGuichet()
{
    return numGuichet;
}
void Employe::ajouter_artisan(Artisan* a)
{
   artisans.push_back(a);
}
void Employe::ajouter_participant(personne* p)
{
   participants.push_back(p);
}
vector<Artisan*> Employe::getArtisans()
{
    return artisans;
}
vector<personne*> Employe::getParticipants()
{
    return participants;
}
void Employe::setNumGuichet(int numGuichet)
{
    this->numGuichet=numGuichet;
}

Employe::~Employe() {
      for (unsigned i = 0; i < artisans.size(); ++i) {
        delete artisans[i];
        }
        for (unsigned i = 0; i < participants.size(); ++i) {
            delete participants[i];
        }
}

Employe& Employe::operator=(const Employe &autre) {
    if (this != &autre) { // Verifier que ce n'est pas la meme instance
        // Copie des attributs de l'objet passe en argument dans l'objet actuel
        personne::operator=(autre); // Appel de l'operateur d'assignation de la classe de base

        // Copie de l'attribut specifique à employé
        numGuichet = autre.numGuichet;

        // Suppression des anciens artisans
        for (int i = 0; i < artisans.size(); ++i) {
            delete artisans[i];
        }
        artisans.clear(); // Effacer le vecteur

        // Suppression des anciens participants
        for (int i = 0; i < participants.size(); ++i) {
            delete participants[i];
        }
        participants.clear(); // Effacer le vecteur
        // Copie des nouveax artisans
        for (int i = 0; i < autre.artisans.size(); ++i) {
            Artisan* newArtisan = new Artisan(*autre.artisans[i]); // Allouer une nouvelle memoire et copier la valeur
            artisans.push_back(newArtisan);
        }
    }
    return *this; // Retourner une reference vers l'objet actuel
}
ostream& operator<<(ostream &o,Employe &e)
{
    o<<static_cast<const personne&>(e);
    o<<"Num guichet : "<<e.numGuichet<<endl;
    o<<"Les artisans : "<<endl;
    for(int i=0;i<e.artisans.size();i++)
    {
        o<<"Artisan  "<<i+1<<" : "<<*(e.artisans[i])<<endl;

    }
    o<<"Les participants : "<<endl;
    for(int i=0;i<e.participants.size();i++)
    {
        o<<"Participant  "<<i+1<<" : "<<*(e.participants[i])<<endl;

    }
    return o;
}
istream& operator>>(istream &in, Employe &e)
{
    // Utiliser la surcharge de l'opérateur >> de la classe personne
    in >> static_cast<personne&>(e);

    cout << "Saisir le num guichet : " << endl;
    in >> e.numGuichet;

    // Saisie des artisans
    cout << "Saisir le nombre des artisans : ";
    int nbArtisans;
    in >> nbArtisans;
    for (int i = 0; i < nbArtisans; ++i) {
        Artisan* artisan = new Artisan();
        cout << "Saisir l'artisan " << i + 1 << " : ";
        in >> *artisan;
        e.artisans.push_back(artisan);
    }


    // Saisie des participants
    cout << "Saisir le nombre des participants : ";
    int nbPart;
    in >> nbPart;
    for (int i = 0; i < nbPart; ++i) {
        personne* participant = new personne();
        cout << "Saisir le participant " << i + 1 << " : ";
        in >> *participant;
        e.participants.push_back(participant);
    }


    return in;
}

