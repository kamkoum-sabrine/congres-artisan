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
   /* personne *p;
    p=new personne();
    p->setcin(0000);
    p->setnom("ahmed");
    p->settel(20000);
    p->setadresse("gggg");
    p->setemail("jjh");
    p->setprenom("hfhfhf");
    p->saisirlangues();
    // p->getlangues();
    p->afficherPersonne();
    p->ajouterLangue();
    cout<<"affichage apres ajout"<<endl;
    p->afficherPersonne();
   /* p->modifier();
    cout<<"********affichage apres modification*********"<<endl;
    cout<<"***********************************"<<endl;
    cout<<endl;
    p->afficherPersonne();*/
    /*stand *s;
    s=new stand();
    s->afficherStand();
    s->editerStand();
    cout<<"*****affichage apres modification : "<<endl;
    s->afficherStand();*/
   /** respensable *r;
    r=new respensable("resp",0000,"salhi","hama",2000,"jdjdj","mourouj");
    r->afficherPersonne();
    r->editer();
    r->setrole("hhhhh");
    r->afficherPersonne();
    r->getsessions();
    cout<<"apres edit"<<endl;
    r->afficherPersonne();
    cout<<"***********************"<<endl;
    r->getrole();**/
    Creation *C1;
    C1 = new Creation(123,"Art","c'est une creation de type art");
    C1->ajouterPhoto("image.png");
    C1->ajouterPhoto("image.jpeg");
   /** C1->afficherCreation();
    C1->modifier();
    C1->afficherCreation();**/

   Sculpture *S1;
    string nom = C1->getNom();
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
    S1->ajouterMateriaux(&materiel2);



    Creation *C2;
    C2 = new Creation(456,"triza","c'est une creation de type broderie");
    C2->ajouterPhoto("image.png");
    C2->ajouterPhoto("image.jpeg");



    Broderie *B1;
    string nom2 = C2->getNom();
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
    Bij->ajouterPierresUtilises(&pierre2);


   ///Artisan *A;
   personne *P=NULL;
   /** p=new personne();
    p->setcin(0000);
    p->setnom("ahmed");
    p->settel(20000);
    p->setadresse("gggg");
    p->setemail("jjh");
    p->setprenom("hfhfhf");

    p->saisirlangues();
    int cin = p->getcin();
    string nomA = p->getnom();
    string prenomA = p->getprenom();
    int telA = p->gettel();
    string emailA = p->getemail();
    string adresseA = p->getadresse();
    vector <string> lA = p->getlangues();**/
   P = new Artisan(123, "ahmed","ben ahmed", 123456, "email@email.com", "Bizerte", "khayat");
   Artisan *A = dynamic_cast<Artisan*>(P);
   ///Creation *C = dynamic_cast<Creation*>(S1);
   A->ajouterCreation(S1);
   A->ajouterCreation(B1);
   A->ajouterCreation(Bij);
   cout<<"-------------"<<"Affichage artisan "<<"------------"<<endl;
   A->afficher();
}
