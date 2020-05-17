#ifndef MAILLAGE_H_INCLUDED
#define MAILLAGE_H_INCLUDED

#include "triangle.h"
#include "sommet.h"
#include <vector>

class Svgfile;

class Maillage
{
    public :
        Maillage();

        void ajouterSommet();
        void afficherSommets() const;
        void ajouterTriangle();
        Sommet *trouverSommet() const;
        void dessinerMaillage() const;
        void selectionSommet(bool selectionDesiree);
        void translaterSommetsSelect();
        ~Maillage();
    private :
        std::vector<Sommet *> m_sommets;
        std::vector<Triangle *> m_triangles;
};

#endif // MAILLAGE_H_INCLUDED
