#include"personne.h"
#include<iostream>
#include<vector>
using namespace std;
personne::personne()
{

}
personne::personne(int c,string n,string p ,int t ,string e,string a)
{

    Cin=c;
    nom=n;
    prenom=p;
    tel=t;;
    email=e;
    adresse=e;
    int nblg;
    cout<<"saisir le nombre de de langues :  "<<endl;
    cin>>nblg;
    for(int i=0;i<nblg;i++)
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
    for(int i=0;i<langues.size();i++)
    {
        string langue;
        langue=langues[i];
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
    return prenom;
}
int personne::gettel()
{
    return tel;
}
string personne::getemail()
{
    return email;
}
string personne::getadresse()
{
    return adresse;
}
vector<string> personne::getlangues()
{
    return langues;
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
        langues.push_back(langue);
    }
}

void personne::afficherPersonne()
{
    cout<<"Affichage des informations relatives à ce personne : "<<endl;
    cout<<"Cin : "<<Cin<<endl;
    cout<<"Nom : "<<nom<<endl;
    cout<<"Prénom : "<<prenom<<endl;
    cout<<"Numéro de téléphone : "<<tel<<endl;
    cout<<"Adresse email :  "<<email<<endl;
    cout<<"Adresse de résidence : "<<adresse<<endl;
    getlangues();

}
void personne::modifier()
{
    char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? T :numéro de téléphone , A : adresse de résidence , M : adresse mail  "<<endl;
        cin>>rep;
        switch(rep)
        {
            case 'T':
              cout<<"saisir le nouveau numéro de telephone : "<<endl;
              cin>>tel;
            break;
            case 'A':
             cout<<"saisir la nouvelle adresse de résidence : "<<endl;
             cin>>adresse;
             break;
            case 'M':
              cout<<"saisie la nouvelle adresse mail : "<<endl;
              cin>>email;
            break;
            default :
              cout<<"réponse invalide !"<<endl;
              break;


        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');
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


}
