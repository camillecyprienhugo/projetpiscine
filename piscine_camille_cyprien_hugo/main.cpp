#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "svgfile.h"
#include "arete.h"
#include "graphe.h"

void svgTest();

int main()
{
     Graphe a;

     a.lire_fichier();

     a.afficher_grapheC();

     svgTest();
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


