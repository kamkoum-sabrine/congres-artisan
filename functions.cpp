
#include<fstream>
#include<string>
#include<iostream>
#include"functions.h"
using namespace std;
void recuperer_fichier()
{
    ifstream fichier ("respensableDB.txt",ios::app);
       if (!fichier)
        cout << "erreur"<<endl ;
        cout <<"****affichage de contenu de fichier****"<<endl ;
    char ch ;
    while (fichier.get(ch))
        cout <<ch;
        fichier.close();

}
void vider_fichier(const string& nom_fichier) {
    ofstream fichier;
    fichier.open(nom_fichier.c_str(), ofstream::out | ofstream::trunc);

    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nom_fichier << endl;
        return;
    }

    cout << "**** Contenu du fichier " << nom_fichier << " effacé ****" << endl;

    fichier.close();
}
