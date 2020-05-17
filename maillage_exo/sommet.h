#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include "coords.h"

class Triangle;
class Svgfile;

class Sommet
{
    public :
        Sommet(double x, double y);
        Sommet();

        void afficher() const;
        void saisir();
        void dessiner(Svgfile& svgout) const;

        double getX() const;
        double getY() const;

        void setSelection(bool selection);
        void translaterSommet(Coords vecTranslation);

        //friend Sommet operator+(const Sommet& s1, const Sommet& s2);

    private :
        Coords m_position;
        bool m_selectionne=false;
};




#endif // SOMMET_H_INCLUDED
