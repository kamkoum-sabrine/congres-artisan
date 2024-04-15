#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class evaluation
{
   int id_evaluation;
   int points;
   string date_evaluation;
   public :
     evaluation();
     evaluation(int,int,string);
     void setId(int);
     void setPoints(int);
     void setDate_evaluation(string);
     int getId();
     int getPoints();
     string getDate_evalution();
    // void evaluer(int);
     void editerEvaluation();
     void afficher_evaluation();
     void saisir_evaluation();
     friend ostream& operator<<(ostream&,const evaluation&);
     friend istream& operator>>(istream&,evaluation&);
     ~evaluation();
};

#endif // EVALUATION_H_INCLUDED
