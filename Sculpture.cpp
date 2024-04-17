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
      // Copie des sessions
    for (list<string*>::const_iterator it = s.materiaux.begin(); it != s.materiaux.end(); ++it) {
        string* materiel = new string(**it); // Allouer dynamiquement un nouvel entier et copier la valeur
        materiaux.push_back(materiel);
    }

    /** materiaux.resize(s.materiaux.size());
    for (unsigned int i=0;i<s.materiaux.size();i++){
        materiaux[i] = s.materiaux[i];
    }**/
}
Sculpture  & Sculpture::operator=(const Sculpture& s) {
    if (this != &s) { // Check for self-assignment
        Creation::operator=(s); // Assign base class members using base class assignment operator
        // Deep copy creations vector to avoid shallow copying
        materiaux.clear(); // Clear existing creations to prevent memory leaks
        for (list<string*>::const_iterator it = s.materiaux.begin(); it != s.materiaux.end(); ++it) {
        string* materiel = new string(**it); // Allouer dynamiquement un nouvel entier et copier la valeur
        materiaux.push_back(materiel);
    }
       /** for (unsigned i=0; i<s.materiaux.size();i++)
        {
            materiaux[i] = s.materiaux[i];
        }**/
    }
    return *this;
}
/**Sculpture::~Sculpture() {
      for (unsigned i = 0; i < materiaux.size(); ++i) {
        delete materiaux[i];
    }
    }**/
void Sculpture::ajouterMateriaux(string  *materiel){
    materiaux.push_back(materiel);
}
void Sculpture::saisirSculpture()
{

    cout<<endl<<"-------Saisir sculpture-----------"<<endl;
    Creation::saisirCreation();
    int nbMat;
    cout<<"saisir le nombre de materiaux :  "<<endl;
    cin>>nbMat;
    for(int i=0;i<nbMat;i++)
    {
        string* materiel = new string;
        cout<<"saisir le materiel numero : "<<i+1<<endl;
        std::cin>>*materiel;
        materiaux.push_back(materiel);
    }
}
void Sculpture::afficher()
{
    ///Creation::afficher();
    cout<<*this;
    cout<<"Affichage des materiaux : "<<endl;
    /**for(int i =0;i<materiaux.size();i++)
    {
        cout<<"Materiel n:"<<i+1<<endl;
        cout<<*(materiaux[i])<<endl;
    }**/
    int i = 1;
    // Déclaration manuelle de l'itérateur
    list<string*>::const_iterator it;
    for (it = materiaux.begin(); it != materiaux.end(); ++it) {
        cout << "Materiel numero " << i << " : " << **it << endl; // Affichage de la session
        ++i;
    }
}

std::ostream& operator<<(std::ostream& o, const Sculpture& s )
{

    ///o << static_cast<const Creation &>(s);
    o<<"Affichage des materiaux : "<<endl;
    /**for(int i =0;i<s.materiaux.size();i++)
    {
        o<<"Materiel n:"<<i+1<<endl;
        o<<*(s.materiaux[i])<<endl;
    }**/

    for (list<string*>::const_iterator it = s.materiaux.begin(); it != s.materiaux.end(); ++it) {
        o << "- Materiel: " << **it << endl;
    }
    return o;
}
istream& operator>>(istream& in, Sculpture& c )
{
    cout<<endl<<"-------Saisir sculpture-----------"<<endl;
    Creation*cr = &c;
    in>>*cr;


    int nbMat;
    cout<<"saisir le nombre de materiaux :  "<<endl;
    in>>nbMat;

    for(int i=0;i<nbMat;i++)
    {
        string* materiel= new string;
        cout<<"saisir le materiel numero : "<<i+1<<endl;
        in>>*materiel;
        c.materiaux.push_back(materiel);
    }
    return in;
}
void Sculpture::modifier()
{
    cout<<"Mise à jour du sculpture"<<endl;
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
                // Supprimer les anciennes sessions
                    for (list<string*>::iterator it = materiaux.begin(); it != materiaux.end(); ++it) {
                        delete *it; // Supprimer chaque pointeur de session
                    }
                    materiaux.clear(); // Effacer la liste des sessions

                    // Saisir les nouvelles sessions
                    int nbMat;
                    cout << "Saisir le nouveaux nombre de materiel : ";
                    cin >> nbMat;
                    for (int i = 0; i < nbMat; i++) {
                        string* materiel = new string;
                        cout << "Saisir le materiel " << i+1 << " : ";
                        cin >> *materiel;
                        materiaux.push_back(materiel);
                    }
                    break;
                /**int position;
                cout << "Saisissez la position du materiel à modifier : ";
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
                break;**/
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

list<string*> Sculpture::getMateriaux()
{
    return materiaux;
}
void Sculpture::setMateriaux(list<string*> materiaux)
{
    this->materiaux = materiaux;
}

