#include"personne.h"
#include<iostream>
#include<vector>
using namespace std;

personne::personne(int Cin,string nom,string prenom ,int tel ,string email,string adresse,int nblangues)
{
    this->Cin = Cin;
    this->nom = nom;
    this->prenom = prenom;
    this->tel = tel;
    this->email = email;
    this->adresse = adresse;
    this->nblangues = nblangues;
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
        cin>>langue;
        langues.push_back(langue);}
}


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


void personne::supprimer_langue() {
    // Verifier si la liste des langues est vide
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
    o<<"Adresse de residence : "<<p.adresse<<endl;
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
    cout<<"Saisir l'adresse de residence : "<<endl;
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
