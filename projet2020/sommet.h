#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string.h>
#include "svgfile.h"
#include <vector>

class Sommet
{
    private :
        int m_indiceS;
        char m_nom;
        int m_coorX;
        int m_coorY;



    public :
        Sommet(int indiceS, char nom, int coorX , int coorY);

        void setindice(int indice);
        void setnom(char nom);
        void setcoorX(int coorX);
        void setcoorY (int coorY);

        int getX();
        int getY();


        void afficher_sommet();

};


#endif // SOMMET_H_INCLUDED
