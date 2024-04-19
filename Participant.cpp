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
            cout << "Quel paramètre souhaitez-vous modifier ?" << endl;
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
                    cout << "Choix invalide. Veuillez saisir à nouveau." << endl;
            }
        } while (choixParam < 1 || choixParam > 6);
    }
}
/*void respensable::modifier()
{

    personne::modifier();
    char rep='O';
    do
    {
        cout<<"voulez vous modifier le role du responsable ? O:OUI , N:NON "<<endl;
        cin>>rep;
        if ((rep=='O')||(rep=='o'))
        {
            cout<<"Quelle est la nouvelle role ? : "<<endl;
            cin>>role;
        }

    }
    while((rep=='O')||(rep=='o'));}


    /*char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? T :numero de telephone , A : adresse de residence , M : adresse mail  , R : Role"<<endl;
        cin>>rep;
        switch(rep)
        {
            case 'T':
              cout<<"saisir le nouveau numero de telephone : "<<endl;
              cin>>tel;
            break;
            case 'A':
             cout<<"saisir la nouvelle adresse de residence : "<<endl;
             cin>>adresse;
             break;
            case 'M':
              cout<<"saisir la nouvelle adresse mail : "<<endl;
              cin>>email;
            break;
            case 'R' :
              cout<<"saisir le nouveau role : "<<endl;
              cin>>role;
              break;
            default :
              cout<<"reponse invalide !"<<endl;
              break;


        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');*/
/**void respensable::modifier() {
    // Appeler d'abord la methode modifier de la classe de base personne
    personne::modifier();

    char reponse;
    do {
        cout << "Que voulez-vous modifier pour ce responsable ?" << endl;
        cout << "R : Role, S : Sessions, Q : Quitter" << endl;
        cin >> reponse;

        switch (toupper(reponse)) {
            case 'R':
                cout << "Saisir le nouveau role : ";
                cin >> role;
                break;
            case 'S': {
                char choix;
                do {
                    cout << "Que voulez-vous faire avec les sessions ?" << endl;
                    cout << "A : Ajouter une session, S : Supprimer une session, Q : Quitter" << endl;
                    cin >> choix;

                    switch (toupper(choix)) {
                        case 'A': {
                            int* session = new int;
                            cout << "Saisir le numero de la nouvelle session : ";
                            cin >> *session;
                            sessions.push_back(session);
                            cout << "Session ajoutee avec succes." << endl;
                            break;
                        }
                        case 'S': {
                            if (sessions.empty()) {
                                cout << "La liste des sessions est vide." << endl;
                            } else {
                                int numero;
                                cout << "Saisir le numero de session a supprimer : ";
                                cin >> numero;
                                if (numero >= 1 && numero <= sessions.size()) {
                                    delete sessions[numero - 1];
                                    sessions.erase(sessions.begin() + numero - 1);
                                    cout << "Session supprimee avec succes." << endl;
                                } else {
                                    cout << "Numero de session invalide." << endl;
                                }
                            }
                            break;
                        }
                        case 'Q':
                            break; // Quitter la boucle interne
                        default:
                            cout << "Choix invalide." << endl;
                    }
                } while (toupper(choix) != 'Q');
                break;
            }
            case 'Q':
                return; // Quitter la methode
            default:
                cout << "Reponse invalide !" << endl;
        }

        do {
            cout << "Voulez-vous encore modifier ? O : OUI, N : NON" << endl;
            cin >> reponse;

            if (toupper(reponse) != 'O' && toupper(reponse) != 'N') {
                cout << "Reponse invalide !" << endl;
            }
        } while (toupper(reponse) != 'O' && toupper(reponse) != 'N');

    } while (toupper(reponse) == 'O');
}
**/


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
    // Utiliser la surcharge de l'opérateur >> de la classe personne
    in >> static_cast<personne&>(r);

    cout << "Saisir le rôle : " << endl;
    in >> r.role;

    return in;
}
Participant& Participant::operator=(const Participant &other) {
    if (this != &other) {
        // Appeler l'opérateur d'affectation de la classe de base (personne), si nécessaire
        personne::operator=(other);
        // Copier les attributs spécifiques de la classe Participant
        role = other.role;
    }
    return *this;
}
