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
    if (this != &b) { // Check for self-assignment
        Creation::operator=(b); // Assign base class members using base class assignment operator
        // Deep copy creations vector to avoid shallow copying
        tissusUtilises.clear(); // Clear existing creations to prevent memory leaks
        for (unsigned i=0; i<b.tissusUtilises.size();i++)
        {
            tissusUtilises[i] = b.tissusUtilises[i];
        }
    }
    return *this;
}
/**Broderie::~Broderie() {
     for (unsigned i = 0; i <tissusUtilises.size(); ++i) {
        delete tissusUtilises[i];
    }
    }**/
void Broderie::ajouterTissus(string*  tissus){
    tissusUtilises.push_back(tissus);
}
void Broderie::afficher()
{
    ///Creation::afficher();
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

    //cout<<c;
    o << static_cast<const Creation &>(c);
    o<<"Affichage des tissus : "<<endl;
    for(int i =0;i<c.tissusUtilises.size();i++)
    {
        o<<"Tissu n:"<<i+1<<endl;
        o<<*(c.tissusUtilises[i])<<endl;
    }
    return o;
}
void Broderie::modifier()
{
    cout<<"Mise à jour du broderie"<<endl;
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
            case 'T': {
                int position;
                cout << "Saisissez la position du tissu à modifier : ";
                cin >> position;
                if (position < 0 || position >= tissusUtilises.size()) {
                    cout << "Position invalide" << endl;
                } else {
                    string nouveauTissu;
                    cout << "Saisissez le nouveau tissu : ";
                    cin.ignore(); // Ignore any previous newline character
                    getline(cin, nouveauTissu);
                    *(tissusUtilises[position]) = nouveauTissu;
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

vector<string*> Broderie::getTissusUtilises()
{
    return tissusUtilises;
}
void Broderie::setTissusUtilises(vector<string*> tissuesUtilises)
{
    this->tissusUtilises = tissusUtilises;
}

