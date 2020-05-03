#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <vector>
#include <string>
#include "arete.h"
#include "sommet.h"
#include "svgfile.h"


class Sommet;
class Arete;

class Graphe
//on defini une calss graphe qui contient son orientation, son ordre et sa taille. elle contient aussi deux vecteurs de type sommet et arete
{
    private :

        int m_orientation;
        //orienantation du graphe
        int m_ordreS;
        //ordre du graphe
        int m_ordreA;
         //nombre d'arete

        std::vector<Sommet*>m_listeS;
        //vecteur de type sommet qui content toutes les infos des sommets
        std::vector<Arete*>m_listeA;
        //vecteur de type arete qui contient toutes les informations des aretes

    public :
        Graphe ();

        void setorientation (int orientation);
         //ici nous definissons tous les seter dont nous vons besoin. ils seront developees dans graphe.cpp
        void setordreS (int ordreS);
        void setordreA (int ordreA);



        void lire_fichier(std::string *nomF);
        //ici nous definissons toutes les methodes de fontions qui sont developees dans graphe.cpp
        void afficher_grapheC();
        void svg_sommet();
        void degre_somm();
        void vec_propre();
        void ponderation (std :: string*nomP);

};


#endif // GRAPHE_H_INCLUDED
