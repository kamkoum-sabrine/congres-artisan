#include"Creation.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Broderie::Broderie()
{

}

Broderie::Broderie(int id, string nom, string description)
    : Creation(id, nom, description){

}
Broderie::Broderie(const Broderie &b)
{

    tissusUtilises.resize(b.tissusUtilises.size());
    for (unsigned int i=0;i<b.tissusUtilises.size();i++){
        tissusUtilises[i] = b.tissusUtilises[i];
    }
}
Broderie  & Broderie::operator=(const Broderie& b) {
    if (this != &b) { 
        Creation::operator=(b); 
        tissusUtilises.clear(); 
        for (unsigned i=0; i<b.tissusUtilises.size();i++)
        {
            tissusUtilises[i] = b.tissusUtilises[i];
        }
    }
    return *this;
}

void Broderie::ajouterTissus(string*  tissus){
    tissusUtilises.push_back(tissus);
}
void Broderie::saisirBroderie()
{
    cout<<endl<<"-------Saisir broderie-----------"<<endl;
    Creation::saisirCreation();
    int nbTissus;
    cout<<"saisir le nombre de tissus utilises :  "<<endl;
    cin>>nbTissus;
    for(int i=0;i<nbTissus;i++)
    {
        string tissus;
        cout<<"saisir le tissus numero : "<<i+1<<endl;
        std::cin>>tissus;
        tissusUtilises.push_back(&tissus);
    }
}
void Broderie::afficher()
{
    cout<<*this;
    cout<<"Affichage des tissus : "<<endl;
    for(int i =0;i<tissusUtilises.size();i++)
    {
        cout<<"Tissu n:"<<i+1<<endl;
        cout<<*(tissusUtilises[i])<<endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Broderie& c )
{
    o<<"Affichage des tissus : "<<endl;
    for(int i =0;i<c.tissusUtilises.size();i++)
    {
        o<<"Tissu n:"<<i+1<<endl;
        o<<*(c.tissusUtilises[i])<<endl;
    }
    return o;
}
istream& operator>>(istream& in, Broderie& c )
{
    cout<<endl<<"------- Saisir Broderie -----------"<<endl;
    Creation*cr = &c;
    in>>*cr;
    int nbTissus;
    cout<<"saisir le nombre de tissus utilises :  "<<endl;
    cin>>nbTissus;
    for(int i=0;i<nbTissus;i++)
    {
        string* tissu = new string;
        cout<<"saisir le tissus numero : "<<i+1<<endl;
        in>>*tissu;
        c.tissusUtilises.push_back(tissu);
    }
    return in;
}
void Broderie::modifier()
{
    cout<<"Mise � jour du broderie"<<endl;
    char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? I :Identifiant , N : Nom , D : Description, P: Photo, T: Tissus  "<<endl;
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
                cin.ignore(); 
                getline(cin, nouveauNom);
                nom = nouveauNom;
                break;
            }
            case 'D': {
                string nouvelleDescription;
                cout << "Saisissez la nouvelle description : ";
                cin.ignore();
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
                    cin.ignore();
                    getline(cin, nouvellePhoto);
                    photos[position] = nouvellePhoto;
                }
                break;
            }
            case 'T': {
                int position;
                cout << "Saisissez la position du tissu � modifier : ";
                cin >> position;
                if (position < 0 || position >= tissusUtilises.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    string nouveauTissu;
                    cout << "Saisissez le nouveau tissu : ";
                    cin.ignore();
                    getline(cin, nouveauTissu);
                    *(tissusUtilises[position]) = nouveauTissu;
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

vector<string*> Broderie::getTissusUtilises()
{
    return tissusUtilises;
}
void Broderie::setTissusUtilises(vector<string*> tissuesUtilises)
{
    this->tissusUtilises = tissusUtilises;
}

