#include"Creation.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Sculpture::Sculpture()
{

}
/**Sculpture::Sculpture(int nbMateriaux, int id, string nom, string desription):Creation(id, nom, description)
{
    cout<<"Nb materiaux "<<nbMateriaux<<endl;
    this->nbMateriaux = nbMateriaux;
   /// materiaux = new string[nbMateriaux];
   /// materiaux.resize(nbMateriaux);

}**/
Sculpture::Sculpture( int id, string nom, string description)
    : Creation(id, nom, description){

}
Sculpture::Sculpture(const Sculpture &s)
{

     materiaux.resize(s.materiaux.size());
    for (unsigned int i=0;i<s.materiaux.size();i++){
        materiaux[i] = s.materiaux[i];
    }
}
Sculpture::~Sculpture() {
      /** for (unsigned i = 0; i < materiaux.size(); ++i) {
        delete materiaux[i];
    }**/
    }
void Sculpture::ajouterMateriaux(string  *materiel){
    materiaux.push_back(materiel);
}
void Sculpture::afficher()
{
    Creation::afficherCreation();

    cout<<"Affichage des materiaux : "<<endl;
    for(int i =0;i<materiaux.size();i++)
    {
        cout<<"Materiel n:"<<i+1<<endl;
        cout<<*(materiaux[i])<<endl;
    }
}
void Sculpture::modifier()
{
    cout<<"Mise � jour du sculpture"<<endl;
    char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? I :Identifiant , N : Nom , D : Description, P: Photo, M: Materiaux  "<<endl;
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
                cout << "Saisissez la position de la photo � modifier : ";
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
                int position;
                cout << "Saisissez la position du materiel � modifier : ";
                cin >> position;
                if (position < 0 || position >= materiaux.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    string nouveauMateriel;
                    cout << "Saisissez le nouveau materiel : ";
                    cin.ignore(); // Ignore any previous newline character
                    getline(cin, nouveauMateriel);
                    *(materiaux[position]) = nouveauMateriel;
                }
                break;
            }
            default:
                cout << "R�ponse invalide !" << endl;
                break;
        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');

}

vector<string*> Sculpture::getMateriaux()
{
    return materiaux;
}
void Sculpture::setMateriaux(vector<string*> materiaux)
{
    this->materiaux = materiaux;
}

