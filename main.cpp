#include"personne.h"
#include<iostream>
#include<vector>
#include<string>
#include"stand.h"
#include"Respensable.h"
///#include"Respensable.cpp"
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
#include "Employe.h"
#include "Employe.cpp"
#include "evaluation.h"
#include "stand.h"
#include "Participant.h"
#include "Participant.cpp"
#include <fstream>
#include <cstdlib>
#include"functions.h"
///#include "evaluation.cpp"
using namespace std;
int main()
{
    cout<<endl<<"*****Bienvevue dans votre application de planification du congres d'artisans*****"<<endl<<endl;
    ///vider_fichier("respensableDB.txt");
    respensable *R = new respensable("Chef d'organisation", 123, "Kamkoum", "Sabrine", 12654987, "sabrine@email.com", "Bizerte", 3);
   /// R->enregistrer();
    ///cout<<"affichage fichier : "<<endl;
    ///recuperer_fichier();
    int sess = 2021;
    R->ajouter_session(&sess);
    Employe *E = new Employe() ;
    int availableEmp = 0;
    vector<Artisan*> art;
    vector<Participant*> part;
    vector<Artisan*> artisans;
    vector<stand> stands;
    if(E->getNumGuichet()==-1) availableEmp = 1;
    else art = E->getArtisans();
    int actor,gererEmp,gererArt,gererStand;
    int optionResp, optionEmpl;
    do {
        cout<<"Vous etes connecte en tant que : "<<endl<<endl<<"1: Responsable d'organisation."<<endl<<"2: Employe."<<endl<<"3: Quitter."<<endl;
        cin>>actor;

        switch (actor) {
            case 1:
                do {
                    cout << endl<<"Bienvenue monsieur le responsable "<<R->getnom()<<" "<<R->getprenom()<< endl;
                    cout <<"1- Gerer employes "<<endl;
                    ///cout <<"2- Organiser les stands "<<endl;
                    cout<<"2- Consulter artisans "<<endl;
                    cout<<"3- Consulter participants "<<endl;
                    cout<<"4- Annoncer resultat"<<endl;
                    cout<<"5- Afficher votre experience professionnelle"<<endl;
                    cout<<"0- Retour au menu principal"<<endl;
                    cin>>optionResp;

                    switch (optionResp) {
                        case 1:
                        {
                            do{
                            cout<<endl<<"***** Gerer employes *****"<<endl;
                            cout<<"1- Ajouter"<<endl;
                            cout<<"2- Consulter"<<endl;
                            cout<<"3- Modifier"<<endl;
                            cout<<"0- Retour au menu principal"<<endl;
                            cin>>gererEmp;

                                switch (gererEmp){
                                    case 1:

                                         cout<<endl<<"***** Ajouter *****"<<endl;
                                        /// E = new Employe();
                                        cin>>*E;
                                    break;
                                    case 2:

                                         cout<<endl<<"***** Consulter *****"<<endl;
                                         if(availableEmp = 0) cout<<"Pas d'employe disponible"<<endl;
                                            else cout<<*E;
                                    break;
                                    case 3:

                                        cout<<endl<<"***** Modifier *****"<<endl;
                                        if(availableEmp = 0) cout<<"Pas d'employe disponible"<<endl;
                                         else E->modifier();
                                    break;
                                    case 0 : cout<<"revenir au menu responsable"<<endl;
                                        break;
                                    default:
                                        cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                                }
                            }while(gererEmp!=0);
                        }
                        break;
                        case 2:
                            cout<<"Consulter artisans"<<endl;
                             if(E->getNumGuichet()==-1) cout<<"Pas d'employe disponible"<<endl;
                            else
                            {
                                for  (int i=0;i<art.size();i++){
                                    cout<<art[i];
                                }
                            }
                            ///vector<Artisan*> art = E->getArtisans();

                         break;

                        case 3:
                            cout<<"Consulter participants"<<endl;
                            if(E->getNumGuichet()==-1) cout<<"Pas de participant disponible"<<endl;
                            else {
                                for  (int i=0;i<part.size();i++){
                                    cout<<part[i];
                                }
                            }
                        break;
                        case 4:
                            cout<<"Annoncer resultat"<<endl;
                            if (E->getEvaluation().size()==0) cout<<"Service non disponible !"<<endl;
                            else {
                                vector<evaluation> evaluations = E->getEvaluation();
                               R->afficherArtisanGagnant(evaluations);
                            }
                        break;
                     case 5:
                        cout<<"Afficher votre experience"<<endl;
                        cout<<"Vous avez "<<R->calculerExperience()<< " ans d'experience dans la planification des congres"<<endl;
                     break;
                    case 0 : cout<<"revenir au menu principal"<<endl;
                            break;
                        default:
                            cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                    }
                } while (optionResp != 0);
                break;

            case 2:
                do {
                    cout<<endl<<"***** MENU Employe *****"<<endl;
                    cout<<"1- Gerer artisans"<<endl;
                    cout<<"2- Gerer participants"<<endl;
                    cout<<"3- Gerer evaluation"<<endl;
                    cout<<"4- Gerer stands"<<endl;
                    cout<<"0- Retour au menu principal"<<endl;
                    cin>>optionEmpl;

                    switch (optionEmpl) {
                        case 1:

                            do{
                            cout<<endl<<"***** Gerer artisans *****"<<endl;
                            cout<<"1- Ajouter"<<endl;
                            cout<<"2- Consulter"<<endl;
                            cout<<"3- Modifier"<<endl;
                            cout<<"4- Afficher contenu fichier"<<endl;
                            cout<<"0- Retour au menu principal"<<endl;
                            cin>>gererArt;

                                switch (gererArt){
                                    case 1:

                                        {int nbArt;
                                        cout<<endl<<"***** Ajouter *****"<<endl;
                                        cout<<endl<<"Saisir le nombre des artisans a ajouter "<<endl;
                                        cin>>nbArt;
                                        Artisan * A;
                                        artisans = E->getArtisans();
                                        for (int i=0;i<nbArt;i++)
                                        {

                                            A = new Artisan();
                                            cin>>*A;
                                            int nbCrea,typeCrea;
                                            cout<<"Saisir le nombre des creations ";
                                            cin>>nbCrea;
                                            for (int k=0;k<nbCrea;i++){
                                                cout<<endl<<"***** Saisir le type de creation *****"<<endl;
                                                cout<<"1- Broderie"<<endl;
                                                cout<<"2- Sculpture"<<endl;
                                                cout<<"3- Bijouterie"<<endl;
                                                cin>>typeCrea;

                                                switch (typeCrea){
                                                    case 1:

                                                    {
                                                        Broderie *B = new Broderie();
                                                        cin>>*B;
                                                        A->ajouterCreation(B);

                                                    }
                                                    break;
                                                    case 2:

                                                       {
                                                         Sculpture *S= new Sculpture();
                                                        cin>>*S;
                                                        A->ajouterCreation(S);
                                                       }
                                                    break;
                                                    case 3:
                                                    {
                                                         Bijouterie *B = new Bijouterie();
                                                        cin>>*B;
                                                        A->ajouterCreation(B);

                                                    }

                                                    break;
                                                    default:
                                                            cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                                                        }


                                            }

                                            E->ajouter_artisan(A);
                                            A->enregistrer();
                                        }
                                        }
                                    break;
                                    case 2:

                                       {
                                        cout<<endl<<"***** Consulter *****"<<endl;


                                         artisans = E->getArtisans();
                                         for (int i=0;i<artisans.size();i++)
                                         {
                                             cout<<*artisans[i];
                                         }
                                       }
                                    break;
                                    case 3:
                                    {
                                        int cinArt;
                                        int trouve=0;
                                        cout<<endl<<"***** Modifier *****"<<endl;
                                        cout<<"Saisir le cin de l'artisan à modifier "<<endl;
                                        cin>>cinArt;
                                        for (int i=0;i<artisans.size();i++)
                                        {

                                            if (artisans[i]->getcin()==cinArt){
                                                cout<<*artisans[i];
                                                artisans[i]->modifier();
                                                trouve=1;
                                            }
                                        }
                                        if (trouve==0){
                                            cout<<"Artisan introuvable !";
                                        }

                                    }

                                    break;
                                    case 4:
                                        {
                                        cout <<"****affichage de contenu de fichier****"<<endl ;
                                        ifstream fichier ("artisansDB.txt",ios::app);
                                           if (!fichier)
                                            cout << "erreur"<<endl ;
                                        char ch ;
                                        while (fichier.get(ch))
                                            cout <<ch;
                                        }
                                    break;
                                    case 0 : cout<<"revenir au menu responsable"<<endl;
                                        break;
                                    default:
                                        cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                                }
                            }while(gererArt!=0);
                             break;

                        case 2:

                            do{
                            cout<<endl<<"***** Gerer participants *****"<<endl;
                            cout<<"1- Ajouter"<<endl;
                            cout<<"2- Consulter"<<endl;
                            cout<<"3- Modifier"<<endl;
                            cout<<"0- Retour au menu principal"<<endl;
                            cin>>gererArt;
                                switch (gererArt){
                                    case 1:
                                    {
                                        int nbPart;
                                        cout<<endl<<"***** Ajouter Participants*****"<<endl;
                                        cout<<endl<<"Saisir le nombre des participants a ajouter "<<endl;
                                        cin>>nbPart;
                                        Participant * P;
                                        for (int i=0;i<nbPart;i++)
                                        {
                                            P= new Participant();
                                            cin>>*P;
                                            E->ajouter_participant(P);
                                        }
                                    }
                                    break;
                                    case 2:

                                       {
                                        cout<<endl<<"***** Consulter Participants*****"<<endl;


                                         part = E->getParticipants();
                                         for (int i=0;i<part.size();i++)
                                         {
                                             cout<<*part[i];
                                         }
                                       }
                                    break;
                                    case 3:
                                    {
                                       int cinPart;
                                        int trouve=0;
                                        cout<<endl<<"***** Modifier *****"<<endl;
                                        cout<<"Saisir le cin du participant à modifier "<<endl;
                                        cin>>cinPart;
                                        for (int i=0;i<part.size();i++)
                                        {

                                            if (part[i]->getcin()==cinPart){
                                                cout<<*part[i];
                                                part[i]->modifier();
                                                trouve=1;
                                            }
                                        }
                                        if (trouve==0){
                                            cout<<"Participant introuvable !";
                                        }

                                    }

                                    break;
                                    case 4:
                                        {
                                        cout <<"****affichage de contenu de fichier****"<<endl ;
                                        ifstream fichier ("artisansDB.txt",ios::app);
                                           if (!fichier)
                                            cout << "erreur"<<endl ;
                                        char ch ;
                                        while (fichier.get(ch))
                                            cout <<ch;
                                        }
                                    break;
                                    case 0 : cout<<"revenir au menu responsable"<<endl;
                                        break;
                                    default:
                                        cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                                }
                            }while(gererArt!=0);
                            break;
                        case 3:
                            cout<<"3- Gerer evaluation"<<endl;
                            E->ajouter_evaluation();
                        break;
                        case 4:

                            do{
                            cout<<endl<<"***** Gerer stands *****"<<endl;
                            cout<<"1- Ajouter"<<endl;
                            cout<<"2- Consulter"<<endl;
                          ///  cout<<"3- Modifier"<<endl;
                          ///  cout<<"3- Verifier stand ouvert ou non ?"<<endl;
                            cout<<"0- Retour au menu principal"<<endl;
                            cin>>gererStand;

                                switch (gererStand){
                                    case 1:

                                        {
                                        int nbStand;
                                        cout<<endl<<"***** Ajouter *****"<<endl;
                                        cout<<endl<<"Saisir le nombre des stands a ajouter "<<endl;
                                        cin>>nbStand;
                                        stand * S;

                                        for (int i=0;i<nbStand;i++)
                                        {
                                            S = new stand();
                                            cin>>*S;
                                            int cinArtStand;
                                            cout<<"Saisir le cin d'artisan pour ce stand "<<endl;
                                            cin>>cinArtStand;
                                            int trouve=0;
                                            for (int i=0;i<artisans.size();i++)
                                            {
                                                if (artisans[i]->getcin()==cinArtStand){
                                                    cout<<*artisans[i];
                                                    //artisans[i]->modifier();
                                                    S->setArtisan(*artisans[i]);
                                                    trouve=1;
                                                }
                                            }
                                            if (trouve=0){
                                                cout<<"Artisan introuvable ! "<<endl;;
                                            } else {
                                                stands.push_back(*S);
                                            }
                                        }
                                        }
                                    break;
                                    case 2:

                                       {
                                        cout<<endl<<"***** Consulter *****"<<endl;



                                         for (int i=0;i<stands.size();i++)
                                         {
                                             cout<<stands[i];
                                         }
                                       }
                                    break;
                                    /**case 3:
                                    {
                                        int idStand;
                                        int trouve=0;
                                        cout<<endl<<"***** Modifier *****"<<endl;
                                        cout<<"Saisir l'identifiant du stand à modifier "<<endl;
                                        cin>>idStand;
                                        for (int i=0;i<stands.size();i++)
                                        {

                                            if (stands[i].getId()==idStand){
                                                cout<<*artisans[i];
                                                artisans[i]->modifier();
                                                trouve=1;
                                            }
                                        }
                                        if (trouve==0){
                                            cout<<"Artisan introuvable !";
                                        }

                                    }

                                    break;**/
                                    /**case 3:
                                        {
                                        cout <<"**** Verifier stand ouvert ou non ? ****"<<endl ;

                                        }
                                    break;**/
                                    case 0 : cout<<"revenir au menu responsable"<<endl;
                                        break;
                                    default:
                                        cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                                }
                            }while(gererArt!=0);
                             break;
                        default:
                            cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
                    }
                } while (optionEmpl != 0);
                break;
            case 3:
                cout<<"Au revoir !"<<endl;
                break;
            default:
                cout<<"Choix invalide. Veuillez sélectionner une option valide."<<endl;
        }


       }while (actor!= 3);
    printf("\nFIN\n");

   /** do {

    cout<<endl<<"*****Bienvevue dans votre application de planification du congres d'artisans*****"<<endl<<endl;
    cout<<"Vous etes connecte en tant que : "<<endl<<endl<<"R: Responsable d'organisation."<<endl<<"E: Employe."<<endl<<"Q: Quitter."<<endl;
    cin>>actor;
    switch (toupper(actor)) {
            case 'R':
                cout << endl<<"Bienvenue monsieur le responsable "<<R->getnom()<<" "<<R->getprenom()<< endl;


                break;
            case 'E':
                cout << endl<<"Bienvenue monsieur l'employe "<< endl;

                break;

            case 'Q':
                exit; // Quitter la methode
            default:
                cout << "Reponse invalide !" << endl;

        }

    }while (toupper(actor) != 'Q');**/

   /**personne *P1=NULL;

   P1 = new Employe();
    Employe *E = dynamic_cast<Employe*>(P1);
    ///A->saisirArtisan();
    cin >> *E;
    cout << *E;**/
    ///Creation *C1 =NULL;
    ///C1 = new Creation();
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
    ///cout<<*S1;
    Artisan *P2=NULL;

   P2 = new Artisan(123, "ahmed","ben ahmed", 123456, "email@email.com", "Bizerte", "khayat",1);
    ///P = new Artisan();
    Artisan *A2 = dynamic_cast<Artisan*>(P2);
    ///A->saisirArtisan();
    cin >> *A2;
    ///cout << *A2;
   ///Creation *C = dynamic_cast<Creation*>(S1);
    A2->ajouterCreation(S1);
    ///A2->ouvrirFichier(f);
    A2->enregistrer();
    ///A2->recuperer_fichier("artisansDB.txt");
    cout <<"****affichage de contenu de fichier****"<<endl ;
    ifstream fichier ("artisansDB.txt",ios::app);
       if (!fichier)
        cout << "erreur"<<endl ;
    char ch ;
    while (fichier.get(ch))
        cout <<ch;
    stand *st = new stand();
    cin >> *st;
    cout<<*st;
    st->setArtisan(*A2);

    cout << *st;
   /** Creation *C2;
    C2 = new Creation(456,"triza","c'est une creation de type broderie");
    C2->ajouterPhoto("image.png");
    C2->ajouterPhoto("image.jpeg");**/



    /**Broderie *B1;
    B1 = new Broderie();
    ///B1->saisirBroderie();
    cin >> *B1;
    cout << *B1;
    Bijouterie *Bij;
    Bij = new Bijouterie();
    cin >> *Bij;**/

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

   Artisan *P=NULL;

   P = new Artisan(123, "ahmed","ben ahmed", 123456, "email@email.com", "Bizerte", "khayat",1);
    ///P = new Artisan();
    Artisan *A = dynamic_cast<Artisan*>(P);
    ///A->saisirArtisan();
    cin >> *A;
   ///Creation *C = dynamic_cast<Creation*>(S1);
    A->ajouterCreation(S1);
    ///A->ajouterCreation(B1);
    ///A->ajouterCreation(Bij);
    ///A->afficher();
   /// cout << endl << "ched ched "<<endl;
    ///cout << *A;
    Participant* parti = new Participant();
    cout<<endl<<"-------Saisir participant------"<<endl;
    cin >> *parti;
     ///E->ajouter_artisan(A);
   // E->ajouter_participant(parti);
    evaluation * eva = new evaluation(12.5, *A, *parti);
    cout<< *eva;

   /// cout<<*E;
}
