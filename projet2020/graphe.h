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
{
    private :

        int m_orientation; //orienantation du graphe
        int m_ordreS; //ordre du graphe
        int m_ordreA; //nombre d'arete

    public :
        Graphe ();

        void setorientation (int orientation);
        void setordreS (int ordreS);
        void setordreA (int ordreA);

        std::vector<Sommet*>m_listeS;
        std::vector<Arete*>m_listeA;

        void lire_fichier(std::string *nomF);
        void afficher_grapheC();
        void svg_sommet(Svgfile &sommet);

};


#endif // GRAPHE_H_INCLUDED
