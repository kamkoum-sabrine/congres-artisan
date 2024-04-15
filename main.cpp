#include"personne.h"
#include<iostream>
#include<vector>
#include<string>
#include"stand.h"
#include"Respensable.h"
#include"Artisan.h"
#include"Artisan.cpp"
#include "Creation.h"
#include "Creation.cpp"
#include "Sculpture.h"
#include "Sculpture.cpp"
#include "Broderie.h"
#include "Broderie.cpp"
#include "Bijouterie.h"
#include "Bijouterie.cpp"
using namespace std;
int main()
{
    Creation *C1;
    C1 = new Creation();
  ///  C1->saisirCreation();
    ///C1->ajouterPhoto("image.png");
    ///C1->ajouterPhoto("image.jpeg");
    ///cout<<*C1;

   /** C1->afficherCreation();
    C1->modifier();
    C1->afficherCreation();**/

   Sculpture *S1;
   S1 = new Sculpture();
    /**string nom = C1->getNom();
    string description = C1->getDescription();
    int id = C1->getId();
    vector<string> photos = C1->getPhotos();

    S1 = new Sculpture(123, "art", "c'est une creation de type art" );
     string materiel1,materiel2;

    cout<<"Donner le mateirel à ajouter ";
    cin>>materiel1;
    S1->ajouterMateriaux(&materiel1);
    cout<<"Donner le materiel à ajouter ";
    cin>>materiel2;
    S1->ajouterMateriaux(&materiel2);**/
    ///S1->saisirSculpture();
    cin >> *S1;

   /** Creation *C2;
    C2 = new Creation(456,"triza","c'est une creation de type broderie");
    C2->ajouterPhoto("image.png");
    C2->ajouterPhoto("image.jpeg");**/



    Broderie *B1;
    B1 = new Broderie();
    ///B1->saisirBroderie();
    cin >> *B1;
    Bijouterie *Bij;
    Bij = new Bijouterie();
    cin >> *Bij;
    ///Bij->saisirBijouterie();
  /**  string nom2 = C2->getNom();
    string description2 = C2->getDescription();
    int id2 = C2->getId();
    vector<string> photos2 = C2->getPhotos();
    B1 = new Broderie(id2, nom2, description2);
    string tissu;
    cout<<"Donner le tissu à ajouter ";
    cin>>tissu;
    B1->ajouterTissus(&tissu);

    Creation *C3;
    C3 = new Creation(789,"Bijouterie","c'est une creation de type bijouterie");
    C3->ajouterPhoto("image.png");
    C3->ajouterPhoto("image.jpeg");



    Bijouterie *Bij;
    string nom3 = C3->getNom();
    string description3 = C3->getDescription();
    int id3 = C3->getId();
    vector<string> photos3 = C3->getPhotos();
    Bij = new Bijouterie(id3, nom3, description3,"dhhab");
    string pierre;
    cout<<"Donner la pierre à ajouter ";
    cin>>pierre;
    Bij->ajouterPierresUtilises(&pierre);
    string pierre2;

    cout<<"Donner la pierre à ajouter ";
    cin>>pierre2;
    Bij->ajouterPierresUtilises(&pierre2);**/
   ///Artisan *A;

   personne *P=NULL;

   ///P = new Artisan(123, "ahmed","ben ahmed", 123456, "email@email.com", "Bizerte", "khayat");
    P = new Artisan();
    Artisan *A = dynamic_cast<Artisan*>(P);
    ///A->saisirArtisan();
    cin >> *A;
   ///Creation *C = dynamic_cast<Creation*>(S1);
    A->ajouterCreation(S1);
    A->ajouterCreation(B1);
    A->ajouterCreation(Bij);
    ///A->afficher();
    cout << *A;
    Artisan * A2 = new Artisan();
    A2 = A;
    ///A2->afficher();
    cout << *A2;
}
