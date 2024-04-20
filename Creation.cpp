#include"Creation.h"
#include<iostream>
#include<vector>

using namespace std;
Creation::Creation()
{

}
Creation::Creation(int id,string nom,string description)
{
    this->id = id;
    this->nom = nom;
    this->description = description;
}
Creation::Creation(const Creation &c)
{
    this->id = c.id;
    this->nom = c.nom;
    this->description = c.description;
    for(int i=0;i<this->photos.size();i++)
    {
        string photo;
        photo = c.photos[i];
        this->photos.push_back(photo);
    }
}

int Creation::getId()
{
    return id;
}
string Creation::getNom()
{
    return nom;
}
string Creation::getDescription()
{
    return description;
}
vector<string> Creation::getPhotos()
{
    return photos;
}
void Creation::setId(int id)
{
   this->id = id;
}

void Creation::setNom(string nom)
{
    this->nom = nom;
}
void Creation::setDescription(string description)
{
    this->description = description;
}
void Creation::ajouterPhoto(string photo)
{
    this->photos.push_back(photo);
}
void Creation::saisirCreation()
{
    cout<<endl<<"-------Saisir creation-----------"<<endl;
    cout<<"Id : ";
    cin>>id;
    cout<<"Nom ";
    cin>>nom;
    cout<<"Description : ";
    cin>>description;
    int nbPh;
    cout<<"Saisir le nombre des photos a ajouter ";
    cin>>nbPh;
    for(int i=0;i<nbPh;i++)
    {
        string photo;
        cout<<"saisir la photo numero : "<<i+1<<endl;
        std::cin>>photo;
        photos.push_back(photo);
    }
}
void Creation::afficher()
{
    cout<<"Affichage des informations relatives à une creation : "<<endl;
    cout<<"Id : "<<id<<endl;
    cout<<"Nom : "<<nom<<endl;
    cout<<"Description : "<<description<<endl;
    cout<<"Les photos de cette creation:"<<endl;
    for (unsigned int i=0; i<photos.size();i++)
    {
        cout<<"Photo "<<i<<endl<<photos[i]<<endl;
    }
}
std::ostream& operator<<(std::ostream& o, const Creation& c )
{
    o<<"Affichage des informations relatives a une creation : "<<endl;
    o<<"Id : "<<c.id<<endl;
    o<<"Nom : "<<c.nom<<endl;
    o<<"Description : "<<c.description<<endl;
    o<<"Les photos de cette creation:"<<endl;
    for (unsigned int i=0; i<c.photos.size();i++)
    {
        o<<"Photo "<<i<<endl<<c.photos[i]<<endl;
    }
    return o;
}
istream& operator>>(istream& i, Creation& c )
{
    cout<<endl<<"-------Saisir creation-----------"<<endl;
    cout<<"Id : ";
    i>>c.id;
    cout<<"Nom ";
    i>>c.nom;
    cout<<"Description : ";
    i>>c.description;
    int nbPh;
    cout<<"Saisir le nombre des photos � ajouter ";
    i>>nbPh;
    for(int k=0;k<nbPh;k++)
    {
        string photo;
        cout<<"saisir la photo numero : "<<k+1<<endl;
        i>>photo;
        c.photos.push_back(photo);
    }
    return i;
}

