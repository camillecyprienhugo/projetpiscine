#include "svgfile.h"
#include <iostream>

/// Toute la partie sur la g�n�ration du SVG est un code founi par monsieur Fercoq

/// Voir impl�mentation apr�s le main
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
    /// ( options � voir svgfile.h ligne 23 )
    Svgfile svgout;

    /// Dessin du rep�re cart�sien
    svgout.addGrid();


    /// L'objet svgout est automatiquement lib�r� � la sortie
    /// de ce sous-programme : le fichier output.svg est alors ferm�
}
