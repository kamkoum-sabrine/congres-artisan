#include"Employe.h"
#include"personne.h"
#include"Artisan.h"
#include"Participant.h"
#include"evaluation.h"
///#include"evaluation.cpp"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

Employe::Employe(int numGuichet,int c,string n,string p ,int t ,string e,string a,int nblg ):personne(c,n,p,t,e,a,nblg)
{

    this->numGuichet=numGuichet;
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

        // Copie de l'attribut specifique � employ�
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
        // Copie des nouveax artisans
        for (int i = 0; i < autre.participants.size(); ++i) {
            Participant* newParticipant = new Participant(*autre.participants[i]); // Allouer une nouvelle memoire et copier la valeur
            participants.push_back(newParticipant);
        }
    }
    return *this; // Retourner une reference vers l'objet actuel
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
        cout << "Saisir l'artisan numero " << i+1 << " : ";
        cin >> *A;
        artisans.push_back(A);
    }
    int nbParticipants;
    cout<<"saisir le nombre des participants : "<<endl;
    cin>>nbParticipants;
    Participant *p = new Participant();
    for (int i = 0; i < nbParticipants; i++) {
        cout << "Saisir le participant numero " << i+1 << " : ";
        cin >> *p;
        participants.push_back(p);
    }
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
    // Demander � l'utilisateur s'il souhaite modifier les informations
    char choix;
    cout << "Voulez-vous modifier les informations de l'employe ? (o/n) ";
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        int choixParam;
        do {
            // Demander � l'utilisateur ce qu'il souhaite modifier
            cout << "Quel param�tre souhaitez-vous modifier ?" << endl;
            cout << "1. Nom" << endl;
            cout << "2. Prenom" << endl;
            cout << "3. Email" << endl;
            cout << "4. Adresse" << endl;
            cout << "5. Nombre de logements" << endl;
            cout << "6. Role" << endl;
            cout << "7. T�ches" << endl;
            cout << "8. Sessions" << endl;
            cin >> choixParam;

            switch (choixParam) {
                case 1: {
                    string nouveauNom;
                    cout << "Nouveau nom : ";
                    cin >> nouveauNom;
                    personne::setnom(nouveauNom);
                    break;
                }
                case 2: {
                    string nouveauPrenom;
                    cout << "Nouveau prenom : ";
                    cin >> nouveauPrenom;
                    personne::setprenom(nouveauPrenom);
                    break;
                }
                case 3: {
                    string nouvelEmail;
                    cout << "Nouvel email : ";
                    cin >> nouvelEmail;
                    personne::setemail(nouvelEmail);
                    break;
                }
                case 4: {
                    string nouvelleAdresse;
                    cout << "Nouvelle adresse : ";
                    cin >> nouvelleAdresse;
                    personne::setadresse(nouvelleAdresse);
                    break;
                }
                case 5: {
                    int nouveauNbLogements;
                    cout << "Nouveau nombre de logements : ";
                    cin >> nouveauNbLogements;
                   personne::setnblangues(nouveauNbLogements);
                    break;
                }
                case 6: {
                    cout << "Nouveau numero de guichet : ";
                    cin >> numGuichet;
                    break;
                }

                default:
                    cout << "Choix invalide. Veuillez saisir � nouveau." << endl;
            }
        } while (choixParam < 1 || choixParam > 6);
    }
}


void Employe::ajouter_artisan(Artisan* a)
{
   artisans.push_back(a);
}
void Employe::ajouter_participant(Participant* p)
{
   participants.push_back(p);
}
void Employe::ajouter_evaluation()
{
    int cinArt,cinPart;
    int trouveA = 0;
    int trouveP = 0;
    Artisan A;
    Participant P;
    cout<<"Donner le cin de l'artisan a evaluer ";
    cin>>cinArt;
    cout<<"Donner le cin du participant ";
    cin>>cinPart;
    for (int i=0;i<artisans.size();i++)
    {
        if (artisans[i]->getcin()==cinArt){
         A = *artisans[i];
         cout<<"l9ith art "<<endl;
         trouveA = 1;
        }
    }
        for (int i=0;i<participants.size();i++)
    {
        if (participants[i]->getcin()==cinPart){
            cout<<"l9ith part "<<endl;
         P = *participants[i];
         trouveP = 1;
        }
    }
    if ((trouveA==1)&&(trouveP==1)){
        cout<<"l9ithom ezouz "<<endl;
        evaluation  e ;
        cout<<"neewww "<<endl;
        double score;
        cout<<"A : "<<A.getcin();
        e.setArtisan(A);
        e.setParticipant(P);
        cout<<"seettinneehom "<<endl;
        cout<<"Donner le score attribue ";
        cin>>score;
        e.setScore(score);
        evaluations.push_back(e);
    }
    else {
        cout<<"Artisan ou Participant introuvable !"<<endl;
    }

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
    // Utiliser la surcharge de l'op�rateur >> de la classe personne
    in >> static_cast<personne&>(e);
    cout << "Saisir le num guichet : " << endl;
    in >> e.numGuichet;

    return in;
}

