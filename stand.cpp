#include"stand.h"
#include<iostream>
#include"string"
#include<map>
#include<list>
using namespace std;
stand::stand()
{
    jours.push_back("Lundi");
    jours.push_back("Mardi");
    jours.push_back("Mercredi");
    jours.push_back("Jeudi");
    jours.push_back("Vendredi");
    jours.push_back("Samedi");
    jours.push_back("Dimande");
}

void stand::saisir_stand() {
    // Saisir l'identifiant du stand
    cout << "Saisir l'identifiant du stand : " << endl;
    cin >> id_stand;

    // Saisir l'emplacement du stand
    cout << "Saisir l'emplacement du stand : " << endl;
    cin.ignore(); // Ignorer les caractères résiduels
    getline(cin, emplacement);

    // Définir un map pour stocker les horaires d'ouverture et de fermeture
    map<string, pair<string, string> > nouveauxHoraires;

    // Demander à l'utilisateur de saisir les jours de la semaine
    cout << "Saisir les jours de la semaine pour lesquels vous souhaitez définir les horaires (saisir 'fin' pour arrêter) : " << endl;

    string jour;
    while (true) {
        cout << "Saisir un jour de la semaine (ou 'fin' pour terminer) : ";
        cin >> jour;
        // Vérifier si l'utilisateur souhaite arrêter la saisie
        if (jour == "fin") {
            break;
        }
        // Saisir les heures d'ouverture et de fermeture pour le jour saisi
        string heureOuverture, heureFermeture;
        cout << "Saisir l'heure d'ouverture du stand le " << jour << " : " << endl;
        cin >> heureOuverture;

        cout << "Saisir l'heure de fermeture du stand le " << jour << " : " << endl;
        cin >> heureFermeture;

        // Stocker les heures dans le map
        nouveauxHoraires[jour] = make_pair(heureOuverture, heureFermeture);
    }

    // Mettre à jour les horaires dans l'objet stand
    setHoraires(nouveauxHoraires);
}

stand::stand(int id_stand,string emplacement, Artisan artisan,  map<string, pair<string, string> > horaires)
{
    this->id_stand=id_stand;
    this->emplacement=emplacement;
    this->artisan = artisan;
    this->horaires = horaires;
    jours.push_back("Lundi");
    jours.push_back("Mardi");
    jours.push_back("Mercredi");
    jours.push_back("Jeudi");
    jours.push_back("Vendredi");
    jours.push_back("Samedi");
    jours.push_back("Dimande");
}

void stand::afficherStand()
{
    cout<<"AFFICHAGE DU STAND"<<endl;
    cout<<"l'identifiant de ce stand est : "<<id_stand<<endl;
    cout<<"l'emplacement de ce stand est : "<<emplacement<<endl;
    // Afficher les horaires par jour de la semaine
    cout << "Horaires par jour de la semaine :" << endl;
    for (int i = 0; i < jours.size(); i++) {
        string jour = jours[i];
        // Vérifiez si le jour existe dans la map horaires
        map<string, pair<string, string> >::iterator it = horaires.find(jour);
        if (it != horaires.end()) {
            pair<string, string> horairesJour = it->second;
            cout << jour << ": " << horairesJour.first << " - " << horairesJour.second << endl;
        } else {
            // Si le jour n'existe pas dans la map, indiquez que les horaires ne sont pas spécifiés
            cout << jour << ": Horaires non spécifiés" << endl;
        }
    }
}
void stand::editerStand() {
    char reponse;

    do {
        cout << "Que voulez-vous modifier pour ce stand ?" << endl;
        cout << "I : Identifiant" << endl;
        cout << "E : Emplacement" << endl;
        cout << "J: Horaire par jour de la semaine "<<endl;
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
             case 'J':
                // Gérer les horaires par jour de la semaine
                {
                    string jour;
                    string nouvelleHeureOuverture, nouvelleHeureFermeture;
                    cout << "Saisissez le jour à modifier (Lundi, Mardi, ... Dimanche) : ";
                    cin.ignore();
                    getline(cin, jour);

                    // Vérifiez si le jour existe dans le vecteur `jours`
                    bool jourExiste = false;
                    for (int i = 0; i < jours.size(); i++) {
                        if (jours[i] == jour) {
                            jourExiste = true;
                            break;
                        }
                    }

                    if (jourExiste) {
                        cout << "Saisir la nouvelle heure d'ouverture pour " << jour << " : ";
                        cin >> nouvelleHeureOuverture;
                        cout << "Saisir la nouvelle heure de fermeture pour " << jour << " : ";
                        cin >> nouvelleHeureFermeture;
                        horaires[jour] = make_pair(nouvelleHeureOuverture, nouvelleHeureFermeture);
                    } else {
                        cout << "Jour invalide ou non existant." << endl;
                    }
                }
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



ostream& operator<<(ostream& o, stand &s)
{
    o<<"Affichage des informations relatives à ce stand : "<<endl;
    o<<"Identifiant du stand :"<<s.id_stand<<endl;
    o<<"Emplacement du stand : "<<s.emplacement<<endl;
    o << "Horaires par jour de la semaine :" << endl;
    for (int i = 0; i < s.jours.size(); i++) {
        string jour = s.jours[i];
        pair<string, string> horairesJour = s.horaires.at(jour);
        o << jour << ": " << horairesJour.first << " - " << horairesJour.second << endl;
    }
    o<<s.artisan.getcin()<<" "<<s.artisan.getnom()<<" "<<s.artisan.getprenom()<<endl;
    return o;
}
stand::~stand(){}
istream& operator>>(istream &i,stand &s)
{
    cout<<"Saisir l'identifiant du stand : "<<endl;
    i>>s.id_stand;
    cout<<"Saisir l'emplacement du stand : "<<endl;
    i>>s.emplacement;
    cout << "Saisissez les horaires par jour de la semaine :" << endl;
    for (int k = 0; k < s.jours.size(); k++) {
        string jour = s.jours[k];
        cout << "Pour le jour " << jour << " :" << endl;
        string heureOuverture;
        string heureFermeture;
        cout << "Heure d'ouverture : ";
        i >> heureOuverture;
        cout << "Heure de fermeture : ";
        i >> heureFermeture;
        s.horaires[jour] = make_pair(heureOuverture, heureFermeture);
    }
    return i;
}

bool stand::estOuvert(const string& heure_actuelle, const string& jour)  {
    // Trouver les horaires pour le jour donné dans la map horaires
    map<string, pair<string, string> >::iterator it = horaires.find(jour);

    if (it != horaires.end()) {
        // Récupérer les heures d'ouverture et de fermeture pour le jour donné
         pair<string, string>& horairesJour = it->second;
         string& heureOuverture = horairesJour.first;
         string& heureFermeture = horairesJour.second;

        // Vérifier si l'heure actuelle se situe entre les heures d'ouverture et de fermeture
        return (heure_actuelle >= heureOuverture && heure_actuelle <= heureFermeture);
    } else {
        // Si le jour n'est pas trouvé dans la map, le stand est considéré comme fermé
        return false;
    }
}

