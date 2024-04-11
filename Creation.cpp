#include"Creation.h"
#include<iostream>
#include<vector>

using namespace std;
Creation::Creation()
{

}
Creation::Creation(int id,string nom,string description)
{
    this->id = id;
    this->nom = nom;
    this->description = description;
}
Creation::Creation(const Creation &c)
{
    this->id = c.id;
    this->nom = c.nom;
    this->description = c.description;
    for(int i=0;i<this->photos.size();i++)
    {
        string photo;
        photo = c.photos[i];
        this->photos.push_back(photo);
    }
}


int Creation::getId()
{
    return id;
}
string Creation::getNom()
{
    return nom;
}
string Creation::getDescription()
{
    return description;
}
vector<string> Creation::getPhotos()
{
    return photos;
}
void Creation::setId(int id)
{
   this->id = id;
}

void Creation::setNom(string nom)
{
    this->nom = nom;
}
void Creation::setDescription(string description)
{
    this->description = description;
}
void Creation::ajouterPhoto(string photo)
{
    this->photos.push_back(photo);
}
void Creation::afficher()
{
    cout<<"Affichage des informations relatives à une création : "<<endl;
    cout<<"Id : "<<id<<endl;
    cout<<"Nom : "<<nom<<endl;
    cout<<"Description : "<<description<<endl;
    cout<<"Les photos de cette création:"<<endl;
    for (unsigned int i=0; i<photos.size();i++)
    {
        cout<<"Photo "<<i<<endl<<photos[i]<<endl;
    }
}
void Creation::modifier()
{
    cout<<"Mise à jour d'une creation"<<endl;
    char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? I :Identifiant , N : Nom , D : Description, P: Photo  "<<endl;
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
            default:
                cout << "Réponse invalide !" << endl;
                break;
        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');
}

