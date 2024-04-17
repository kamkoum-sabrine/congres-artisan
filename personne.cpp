#include"personne.h"
#include<iostream>
#include<vector>
using namespace std;
personne::personne()
{

    /**cout<<"saisir le numero de cin : "<<endl;
    cin>>Cin;
    cout<<"saisir le nom : "<<endl;
    cin>>nom;
    cout<<"saisir le prenom : "<<endl;
    cin>>prenom;
    cout<<"saisir le num de telephone : "<<endl;
    cin>>tel;
    cout<<"saisir l email : "<<endl;
    cin>>email;
    cout<<"saisir l adresse : "<<endl;
    cin>>adresse;
    cout<<"saisir le nombre de de langues :  "<<endl;
    cin>>nblangues;
    for(int i=0;i<nblangues;i++)
    {
        string langue;
        cout<<"saisir la langue numero : "<<i+1<<endl;
        std::cin>>langue;
        langues.push_back(langue);}*/

}
personne::personne(int c,string n,string p ,int t ,string e,string a,int nblg)
{

    Cin=c;
    nom=n;
    prenom=p;
    tel=t;;
    email=e;
    adresse=a;
    nblangues=nblg;
  /** for(int i=0;i<nblangues;i++)
    {
        string langue;
        cout<<"saisir la langue numero : "<<i+1<<endl;
        std::cin>>langue;
        langues.push_back(langue);}**/




}
void personne::saisir_personne()
{
    cout<<"saisir le numero de cin : "<<endl;
    cin>>Cin;
    cout<<"saisir le nom : "<<endl;
    cin>>nom;
    cout<<"saisir le prenom : "<<endl;
    cin>>prenom;
    cout<<"saisir le num de telephone : "<<endl;
    cin>>tel;
    cout<<"saisir l email : "<<endl;
    cin>>email;
    cout<<"saisir l adresse : "<<endl;
    cin>>adresse;
    cout<<"saisir le nombre de de langues :  "<<endl;
    cin>>nblangues;
    for(int i=0;i<nblangues;i++)
    {
        string langue;
        cout<<"saisir la langue numero : "<<i+1<<endl;
        std::cin>>langue;
        langues.push_back(langue);}
}
personne::personne(const personne &p)
{
    Cin=p.Cin;
    nom=p.nom;
    prenom=p.prenom;
    tel=p.tel;
    email=p.email;
    adresse=p.adresse;
    nblangues=p.nblangues;
    for(int i=0;i<(p.langues).size();i++)
    {
        string langue;
        langue=p.langues[i];
        langues.push_back(langue);
    }
}/*personne::~personne()
{
    for (int i=0;i<langues.size();i++)
    {
        delete
    }
    langues.clear();
}*/
int personne::getcin()
{

    return Cin;
}
string personne::getnom()
{

    return nom;
}
string personne::getprenom()
{
    cout<<"le prenom de ce personne est : "<<endl;
    return prenom;
}
int personne::gettel()
{
    cout<<"le numero de telephone de ce personne est : "<<endl;
    return tel;
}
string personne::getemail()
{
    cout<<"l'adresse email de ce personne est : "<<endl;
    return email;
}
string personne::getadresse()
{
    cout<<"l'adresse de ce personne est : "<<endl;
    return adresse;
}
void personne::getlangues()
{
    cout<<"Les langues que ce personne maitrisent sont : "<<endl;
    for(int i=0;i<langues.size();i++)
    {
        cout<<"langue "<<i+1<<" : "<<langues[i]<<endl;
    }
}
void personne::setcin(int c)
{
    Cin=c;
}
void personne::setnom(string nom)
{
    this->nom=nom;
}
void personne::setprenom(string)
{
    this->prenom=prenom;
}
void personne::settel(int tel)
{
   this->tel=tel;
}
void personne::setemail(string email)
{
    this->email=email;
}
void personne::setadresse(string adresse )
{
    this->adresse=adresse;
}
void personne::saisirlangues()
{
    int nblg;
    cout<<"saisir le nombre de de langues :  "<<endl;
    cin>>nblg;
    for(int i=0;i<nblg;i++)
    {
        string langue;
        cout<<"saisir la langue numero : "<<i+1<<endl;
        std::cin>>langue;
        langues.push_back(langue);}}

void personne::afficherPersonne()
{
    cout<<"Affichage des informations relatives a ce personne : "<<endl;
    cout<<"Cin : "<<Cin<<endl;
    cout<<"Nom : "<<nom<<endl;
    cout<<"Prenom : "<<prenom<<endl;
    cout<<"Numero de telephone : "<<tel<<endl;
    cout<<"Adresse email :  "<<email<<endl;
    cout<<"Adresse de residence : "<<adresse<<endl;
    cout<<"Nombre de langues : "<<nblangues<<endl;
    getlangues();

}
 void personne::modifier() {
    char reponse;

    do {
        cout << "Que voulez-vous modifier pour cette personne ?" << endl;
        cout << "N : Nom, P : Prenom, T : Telephone, E : Email, A : Adresse" << endl;
        cout << "L : Langues, Q : Quitter" << endl;
        cin >> reponse;

        switch (toupper(reponse)) {
            case 'N':
                cout << "Saisir le nouveau nom : ";
                cin >> nom;
                break;
            case 'P':
                cout << "Saisir le nouveau prenom : ";
                cin >> prenom;
                break;
            case 'T':
                cout << "Saisir le nouveau numero de telephone : ";
                cin >> tel;
                break;
            case 'E':
                cout << "Saisir le nouvel email : ";
                cin >> email;
                break;
            case 'A':
                cout << "Saisir la nouvelle adresse : ";
                cin >> adresse;
                break;
            case 'L':
                int nbLangues;
                cout << "Combien de langues voulez-vous ajouter ? : ";
                cin >> nbLangues;
                for (int i = 0; i < nbLangues; ++i) {
                    string langue;
                    cout << "Saisir la langue " << i + 1 << " : ";
                    cin >> langue;
                    langues.push_back(langue);
                }
                break;
            case 'Q':
                return; // Quitter la methode
            default:
                cout << "Reponse invalide !" << endl;
                continue; // Revenir au debut de la boucle pour redemander une reponse valide
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

void personne::ajouterLangue()
{
   int nb_langues;
  cout<<"combien de langues voulez-vous ajoutez ? "<<endl;
  cin>>nb_langues;
  string lang;
  for(int i=0;i<nb_langues;i++)
  {
      cout<<"saisir la langue" <<i+1<<"que vous voulez ajouter : "<<endl;
      cin>>lang;
      langues.push_back(lang);
  }
  nblangues=nblangues+nb_langues;


}
void personne::supprimer_langue() {
    // V�rifier si la liste des langues est vide
    if (langues.empty()) {
        cout << "La liste des langues est vide." << endl;
        return;
    }

    // Afficher les langues actuellement disponibles
    cout << "Langues actuellement disponibles :" << endl;
    for (size_t i = 0; i < langues.size(); ++i) {
        cout << i + 1 << ". " << langues[i] << endl;
    }

    // Demander à l'utilisateur le numero de la langue à supprimer
    int choix;
    cout << "Entrez le numero de la langue a supprimer : ";
    cin >> choix;

    // Verifier si le numero est valide
    if (choix < 1 || choix > langues.size()) {
        cout << "Numero invalide. Operation annulee." << endl;
        return;
    }

    // Supprimer la langue selectionnee
    langues.erase(langues.begin() + choix - 1);

    // Mettre à jour nblangues
    nblangues = langues.size();

    cout << "Langue supprimee avec succes." << endl;
}


ostream& operator<<(ostream& o,const personne &p)
{
    o<<"Affichage des informations relatives a ce personne : "<<endl;
    o<<"Cin : "<<p.Cin<<endl;
    o<<"Nom : "<<p.nom<<endl;
    o<<"Prenom : "<<p.prenom<<endl;
    o<<"Numero de telephone : "<<p.tel<<endl;
    o<<"Adresse mail : "<<p.email<<endl;
    o<<"Adresse de vie : "<<p.adresse<<endl;
    o<<"Nombre de langues : "<<p.nblangues<<endl;
    o<<"Les langues que ce personne maitrisent sont : "<<endl;
    for(int i=0;i<(p.langues).size();i++)
    {
        o<<"Langue "<<i+1<<" : "<<p.langues[i]<<endl;
    }
    return o;
}
istream& operator>>(istream &i,personne &p)
{
    cout<<"Saisir le numero d'identité : "<<endl;
    i>>p.Cin;
    cout<<"Saisir le nom : "<<endl;
    i>>p.nom;
    cout<<"Saisir le prénom : "<<endl;
    i>>p.prenom;
    cout<<"Saisir le numero de telephone : "<<endl;
    i>>p.tel;
    cout<<"Saisir l'adresse mail : "<<endl;
    i>>p.email;
    cout<<"Saisir l'adresse de vie : "<<endl;
    i>>p.adresse;
    cout<<"Saisir le nombre de langues pratiquées : "<<endl;
    i>>p.nblangues;
   for(int j = 0; j < p.nblangues; j++)
    {
        string langue;
        cout << "Saisir la langue " << j + 1 << " : " << endl;
        i >> langue;
        p.langues.push_back(langue);
    }
    return i ;
}
