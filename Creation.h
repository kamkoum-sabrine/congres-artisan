#ifndef CREATION_H_INCLUDED
#define CREATION_H_INCLUDED
using namespace std;

class Creation
{
    protected :
      int id;
      string nom;
      string description;
      vector<string> photos;

    public :
       Creation();
       Creation(int,string,string);
       Creation(const Creation &);
       virtual ~Creation(){};
       int getId(); // methode qui retourne l'identifiant de la création
       string getNom(); //methode qui retourne le nom de la Creation
       string getDescription(); // methode qui retourne la description de la création
       vector<string> getPhotos(); //methode qui retourne les photos de la création

       void setId(int); //methode qui permet le saisie de num de cin de la personne
       void setNom(string);//methode qui permet le saisie du nom de la personne
       void setDescription(string);

       void ajouterPhoto(string);

       virtual void afficher();
       virtual void modifier();

       friend std::ostream& operator<<(std::ostream& o, const Creation& c);
};


#endif // CREATION_H_INCLUDED
