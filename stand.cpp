#include"stand.h"
#include<iostream>
#include"string"
using namespace std;
stand::stand()
{


}
void stand::saisir_stand()
{
    cout<<"saisir l identifiant du stand : "<<endl;
    cin>>id_stand;
    cout<<"saisir l 'emplacement du stand : "<<endl;
    cin>>emplacement;
    cout<<"saisir l'heure d'ouverture du stand : "<<endl;
    cin>>heure_ouverture;
    cout<<"saisir l'heure de fermeture du stand : "<<endl;
    cin>>heure_fermeture;
}
stand::stand(int id_stand,string emplacement, string heure_ouverture, string heure_fermeture, Artisan artisan)
{
    this->id_stand=id_stand;
    this->emplacement=emplacement;
    this->heure_ouverture = heure_ouverture;
    this->heure_fermeture = heure_fermeture;
    this->artisan = artisan;
}

void stand::afficherStand()
{
    cout<<"AFFICHAGE DU STAND"<<endl;
    cout<<"l'identifiant de ce stand est : "<<id_stand<<endl;
    cout<<"l'emplacement de ce stand est : "<<emplacement<<endl;
    cout<<"L'heure d'ouverture de ce stand est : "<<heure_ouverture<<endl;
    cout<<"L'heure d'ouverture de ce stand est : "<<heure_fermeture<<endl;
}
/*void stand::editerStand()
{
    char reponse,rep;
    do
    {
        cout<<"Que voulez-vous modifier pour ce stand ? I : identifiant , E : emplacement"<<endl;
        cin>>reponse;
        switch(reponse)
        {
            case 'I':
              cout<<"Saisir le nouveau identifiant  : "<<endl;
              cin>>id_stand;
               break;
            case 'E':
              cout<<"Saisir le nouveau emplacement : "<<endl;
              cin>>emplacement;
              break;
            default :
               cout<<"Réponse invalide ! "<<endl;
                break;
        }
        cout<<"Voulez-vous encore modifier ? O : OUI , N: NON"<<endl;
        cin>>rep;
    }
    while((rep=='O')||(rep=='o'));
}*/
void stand::editerStand() {
    char reponse;

    do {
        cout << "Que voulez-vous modifier pour ce stand ?" << endl;
        cout << "I : Identifiant" << endl;
        cout << "E : Emplacement" << endl;
        cout << "H : Heure d'ouverture" << endl;
        cout << "F : Heure de fermeture" << endl;
        cin >> reponse;

        switch (toupper(reponse)) {
            case 'I':
                cout << "Saisir le nouvel identifiant : ";
                cin >> id_stand;
                break;
            case 'E':
                cout << "Saisir le nouvel emplacement : ";
                cin.ignore(); // Ignorer le caractère de nouvelle ligne restant dans le buffer
                getline(cin, emplacement);
                break;
            case 'H':
                cout << "Saisir la nouvelle heure d'ouverture : ";
                cin >> heure_ouverture;
                break;
            case 'F':
                cout << "Saisir la nouvelle heure de fermeture : ";
                cin >> heure_fermeture;
                break;
            default:
                cout << "Réponse invalide !" << endl;
                continue; // Revenir au début de la boucle pour redemander une réponse valide
        }

        do {
            cout << "Voulez-vous encore modifier ? O : OUI, N : NON" << endl;
            cin >> reponse;

            if (toupper(reponse) != 'O' && toupper(reponse) != 'N') {
                cout << "Réponse invalide !" << endl;
            }
        } while (toupper(reponse) != 'O' && toupper(reponse) != 'N');

    } while (toupper(reponse) == 'O');
}



ostream& operator<<(ostream& o,const stand &s)
{
    o<<"Affichage des informations relatives à ce stand : "<<endl;
    o<<"Identifiant du stand :"<<s.id_stand<<endl;
    o<<"Emplacement du stand : "<<s.emplacement<<endl;
    o<<"Heure d'ouverture : "<<s.heure_ouverture<<endl;
    o<<"Heure fermeture : "<<s.heure_fermeture<<endl;
    o<<s.artisan<<endl;
    return o;
}
stand::~stand(){}
istream& operator>>(istream &i,stand &s)
{
    cout<<"Saisir l'identifiant du stand : "<<endl;
    i>>s.id_stand;
    cout<<"Saisir l'emplacement du stand : "<<endl;
    i>>s.emplacement;
    cout<<"Saisir l'heure d'ouverture : "<<endl;
    i>>s.heure_ouverture;
    cout<<"Saisir l'heure de fermeture : "<<endl;
    i>>s.heure_fermeture;
    return i;

}

bool stand::estOuvert(string heure_actuelle) const {
    return (heure_actuelle >= heure_ouverture && heure_actuelle <= heure_fermeture);
}
