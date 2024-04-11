#include"Creation.h"
#include"Bijouterie.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Bijouterie::Bijouterie()
{

}

Bijouterie::Bijouterie(int id, string nom, string description, string typeMetal)
    : Creation(id, nom, description){
    this->typeMetal = typeMetal;
}
Bijouterie::Bijouterie(const Bijouterie &b)
{
    typeMetal = b.typeMetal;
    pierresUtilises.resize(b.pierresUtilises.size());
    for (unsigned int i=0;i<b.pierresUtilises.size();i++){
        pierresUtilises[i] = b.pierresUtilises[i];
    }
}
/**Bijouterie::~Bijouterie() {
     for (unsigned i = 0; i <pierresUtilises.size(); ++i) {
        delete pierresUtilises[i];
    }
    }**/
void Bijouterie::ajouterPierresUtilises(string*  pierre){
    pierresUtilises.push_back(pierre);
}
void Bijouterie::afficher()
{
    Creation::afficher();
    cout<<"Type metal : "<<typeMetal<<endl;
    cout<<"Affichage des pierres : "<<endl;
    for(int i =0;i<pierresUtilises.size();i++)
    {
        cout<<"Pierre n:"<<i+1<<endl;
        cout<<*(pierresUtilises[i])<<endl;
    }
}
void Bijouterie::modifier()
{
    cout<<"Mise à jour du bijouterie"<<endl;
    char rep,reponse;

    do
    {
        cout<<"Que voulez-vous modifiez ? I :Identifiant , N : Nom , D : Description, P: Photo, M: Type metal, U: Pierres utilises  "<<endl;
        cin>>rep;
        switch(rep) {
            case 'I': {
                int nouveauId;
                cout << "Saisissez le nouvel identifiant : ";
                cin >> nouveauId;
                id = nouveauId;
                break;
            }
            case 'N': {
                string nouveauNom;
                cout << "Saisissez le nouveau nom : ";
                cin.ignore(); // Ignore any previous newline character
                getline(cin, nouveauNom);
                nom = nouveauNom;
                break;
            }
            case 'D': {
                string nouvelleDescription;
                cout << "Saisissez la nouvelle description : ";
                cin.ignore(); // Ignore any previous newline character
                getline(cin, nouvelleDescription);
                description = nouvelleDescription;
                break;
            }
            case 'P': {
                int position;
                cout << "Saisissez la position de la photo à modifier : ";
                cin >> position;
                if (position < 0 || position >= photos.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    string nouvellePhoto;
                    cout << "Saisissez la nouvelle photo : ";
                    cin.ignore(); // Ignore any previous newline character
                    getline(cin, nouvellePhoto);
                    photos[position] = nouvellePhoto;
                }
                break;
            }
            case 'M': {
                string nouveauTypeMetal;
                cout << "Saisissez le nouveau type metal : ";
                cin.ignore(); // Ignore any previous newline character
                getline(cin, nouveauTypeMetal);
                typeMetal = nouveauTypeMetal;
                break;
            }
            case 'U': {
               int positionPi;
                cout << "Saisissez la position du pierre à modifier : ";
                cout<<"nb pierres "<<pierresUtilises.size()<<endl;
                cin >> positionPi;
                if (positionPi < 0 || positionPi >= pierresUtilises.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    string nouvellePierre;
                    cout << "Saisissez la nouvelle pierre : ";
                    cin>>nouvellePierre;

                    *(pierresUtilises[positionPi]) = nouvellePierre;
                }
                break;
            }
            default:
                cout << "Réponse invalide !" << endl;
                break;
        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');

}

vector<string*> Bijouterie::getPierresUtilises()
{
    return pierresUtilises;
}
void Bijouterie::setPierresUtilises(vector<string*> pierresUtilises)
{
    this->pierresUtilises = pierresUtilises;
}

