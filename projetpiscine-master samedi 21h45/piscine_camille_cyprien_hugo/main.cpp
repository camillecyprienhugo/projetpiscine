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

    std:: string *nomF(0);
    std:: string nom;
    std::cout<< "Rentrez le nom du fichier sans oublier le .txt" <<std::endl;
    std::cin >> nom ;
    nomF = &nom ;

    a.lire_fichier(nomF);

    a.ponderation();

    a.afficher_grapheC();

    a.svg_sommet();

    a.degre_somm();

    a.vec_propre();

    a.Dijkstra();

}

