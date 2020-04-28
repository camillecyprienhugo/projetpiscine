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
    /// ( options � voir svgfile.h ligne 23 )
    Svgfile svgout;

    /// Dessin du rep�re cart�sien
    svgout.addGrid();


    /// L'objet svgout est automatiquement lib�r� � la sortie
    /// de ce sous-programme : le fichier output.svg est alors ferm�
}


