#include "svgfile.h"
#include <iostream>

/// Toute la partie sur la génération du SVG est un code founi par monsieur Fercoq

/// Voir implémentation après le main
void svgTest();

int main()
{
    svgTest();

    return 0;
}

/// Code initial pour comprendre les ajouts de primitives
void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options à voir svgfile.h ligne 23 )
    Svgfile svgout;

    /// Dessin du repère cartésien
    svgout.addGrid();


    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
}
