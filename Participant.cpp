///#include"personne.h"
//#include"personne.cpp"
#include"Participant.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;
Participant::Participant():personne()
{

}
void Participant::saisir_participant()

{
    personne::saisir_personne();
    cout<<"saisir le role : "<<endl;
    cin>>role;
}
Participant::Participant(int c,string n,string p ,int t ,string e,string a,int nblg,string role ):personne(c,n,p,t,e,a,nblg)
{
    this->role=role;
}
void Participant::afficherPersonne()
{
    personne::afficherPersonne();
    cout<<"le role est : "<<role<<endl;
}
void Participant::modifier() {
    // Demander à l'utilisateur s'il souhaite modifier les informations
    char choix;
    cout << "Voulez-vous modifier les informations du responsable ? (o/n) ";
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        int choixParam;
        do {
            // Demander à l'utilisateur ce qu'il souhaite modifier
            cout << "Quel param�tre souhaitez-vous modifier ?" << endl;
            cout << "1. Nom" << endl;
            cout << "2. Prenom" << endl;
            cout << "3. Email" << endl;
            cout << "4. Adresse" << endl;
            cout << "5. Nombre de logements" << endl;
            cout << "6. Role" << endl;
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
                    cout << "Nouveau role : ";
                    cin >> role;
                    break;
                }
                default:
                    cout << "Choix invalide. Veuillez saisir � nouveau." << endl;
            }
        } while (choixParam < 1 || choixParam > 6);
    }
}

Participant::Participant(const Participant &r):personne(r)
{
    role=r.role;


}
string Participant::getrole()
{
    return role;
}

void Participant::setrole(string role)
{
    this->role=role;
}

Participant::~Participant() {}

ostream& operator<<(ostream &o,const Participant &r)
{
    o<<"Participant :"<<endl;
    o<<static_cast<const personne&>(r);
    o<<"role : "<<r.role<<endl;
    return o;
}
istream& operator>>(istream &in, Participant &r)
{
    // Utiliser la surcharge de l'op�rateur >> de la classe personne
    in >> static_cast<personne&>(r);

    cout << "Saisir le r�le : " << endl;
    in >> r.role;

    return in;
}
Participant& Participant::operator=(const Participant &other) {
    if (this != &other) {
        // Appeler l'op�rateur d'affectation de la classe de base (personne), si n�cessaire
        personne::operator=(other);
        // Copier les attributs sp�cifiques de la classe Participant
        role = other.role;
    }
    return *this;
}
