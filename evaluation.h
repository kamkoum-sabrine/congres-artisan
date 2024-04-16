#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include"Employe.h"
#include"Artisan.h"
#include<iostream>
#include<string>
using namespace std;
class evaluation
{
   double score;
   Artisan artisan;
   personne participant;
   ///Employe employe;
   public :
     evaluation(){};
     evaluation(double,Artisan&, personne&);
     ~evaluation();
     evaluation(const evaluation &);
     evaluation & operator=(const evaluation &);
     void setScore(double score){
        this->score = score;
     }
     void setParticipant(personne participant){
        this->participant = participant;
     }

     void setArtisan(Artisan artisan){
        this->artisan = artisan;
     }

     double getScore(){
        return score;
     }
     Artisan getArtisan(){
        return this->artisan;
     }
     personne getParticipant(){
        return this->participant;
     }

     void editerEvaluation();
     void afficher_evaluation();
     void saisir_evaluation();
     friend ostream& operator<<(ostream&,const evaluation&);
     friend istream& operator>>(istream&,evaluation&);

};

#endif // EVALUATION_H_INCLUDED
