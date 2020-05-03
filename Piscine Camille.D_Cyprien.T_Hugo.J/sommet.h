#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string.h>
#include "svgfile.h"
#include <vector>

class Sommet
//definition de la class sommet qui comporte les attributs et les methodes qui permettent de bine gerer un sommet
{
    private :
        int m_indiceS;
        char m_nom;
        int m_coorX;
        int m_coorY;

    public :
        Sommet(int indiceS, char nom, int coorX , int coorY);

        void setindice(int indice);
        //seter qui permettent de donner des valeurt aux attributs de notre classe
        //il serons developes dans le fichier cpp correspondant a l classe sommet
        void setnom(char nom);
        void setcoorX(int coorX);
        void setcoorY (int coorY);

        int getX();
        int getY();
        char getnom();
        int getindice();



        void afficher_sommet();
        //methode d'affichage des sommets


};


#endif // SOMMET_H_INCLUDED
