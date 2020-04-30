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

        std::vector < int > m_sommetadj;
        double m_cvp; ///nouvel indice pour la methode vecteur propre sans lien avec m_indiceS
        std::vector <int > m_somm; ///vecteur dans lequel on va mettre les sommes d'indices cvp de chaque sommet





    public :
        Sommet(int indiceS, char nom, int coorX , int coorY);

        void setindice(int indice);
        void setnom(char nom);
        void setcoorX(int coorX);
        void setcoorY (int coorY);
        void setsommetadj (int sommetadj);
        void setcvp (double cvp);
        void setsomm(int somme);

        int getX();
        int getY();
        char getnom();
        double getcvp();
        std::vector <int> getsommetadj();
        int getsomm(int i);


        void afficher_sommet();


};


#endif // SOMMET_H_INCLUDED
