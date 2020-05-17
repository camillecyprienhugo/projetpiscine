#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "couleur.h"

class Sommet;
class Maillage;
class Svgfile;

class Triangle
{
    public :
        Triangle(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Triangle();

        void afficher() const;
        void saisir(const Maillage& maillageActuel);
        void dessiner(Svgfile& svgout) const;

        Couleur getCouleur() const;

    private :
        Couleur m_couleur;
        Sommet* m_sommets[3];
};



#endif // TRIANGLE_H_INCLUDED
