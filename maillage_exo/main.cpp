#include "svgfile.h"
#include "couleur.h"
#include "util.h"
#include "maillage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void svgTest();
void afficherMenu();


int main()
{
    int choixMenu=0;
    Maillage maillageActuel;
    afficherMenu();
    util::startAutoCin("test2.txt", 50);
    do
    {
        do
        {
            std::cout << "Choix menu : ";
            std::cin >> choixMenu;
        } while ((choixMenu<0)||(choixMenu>7));
        if (choixMenu == 1)
        {
            maillageActuel.dessinerMaillage();
        }
        else if (choixMenu == 2)
        {
            maillageActuel.afficherSommets();
        }
        else if (choixMenu == 3)
        {
            maillageActuel.ajouterSommet();
        }
        else if (choixMenu == 4)
        {
            maillageActuel.ajouterTriangle();
        }
        else if (choixMenu == 5)
        {
            maillageActuel.selectionSommet(true);
        }
        else if (choixMenu == 6)
        {
            maillageActuel.selectionSommet(false);
        }
        else if (choixMenu == 7)
        {
            maillageActuel.translaterSommetsSelect();
        }


    } while (choixMenu!=0);

    util::stopAutoCin();

    return 0;
}

void afficherMenu()
{
    std::cout << "0/ Quitter" << std::endl << "1/ Dessiner scene" << std::endl
              << "2/ Afficher tous sommets" << std::endl << "3/ Ajouter sommet"
              << std::endl << "4/ Ajouter triangle" << std::endl
              << "5/ Selectionner sommet" << std::endl
              << "6/ Deselectionner sommet" << std::endl
              << "7/ Translater selection" << std::endl;
}


/// Code initial pour comprendre les ajouts de primitives
void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options à voir svgfile.h au niveau du constructeur )
    Svgfile svgout;

    /// Dessin du repère cartésien (facultatif)
    // svgout.addGrid();

    /// On a perdu les dessins de sphères (une autre fois peut-être)

    /// Nouveau : on peut toujours utiliser les couleurs "red" "green"...
    /// Mais on a maintenant un type Couleur qui prend 3 composantes RVB
    /// Exemple pour déclarer du Jaune (beaucoup Rouge + Vert, pas de bleu)
    /// Chaque canal est dans l'intervalle [0..255]
    Couleur jaune{255, 200, 0};

    /// Dessin de disque : xcentre ycentre rayon couleur
    svgout.addDisk(100, 100, 30, jaune);
    svgout.addDisk(200, 100, 30, Couleur{100, 150, 200});
    svgout.addDisk(300, 100, 30, "pink");
    svgout.addDisk(400, 100, 30);

    /// Dessin de cercle : xcentre ycentre rayon epaisseur couleur
    svgout.addCircle(100, 200, 30, 10, "red");
    svgout.addCircle(200, 200, 30, 5, "red");
    svgout.addCircle(300, 200, 30, 1, "red");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage ...
    ///                         epaisseur_bordure couleur_bordure
    svgout.addTriangle(100,300, 200,300, 150,250, "green", 5, "orange");

    /// Dessin de triangle : x1 y1 x2 y2 x3 y3 couleur_remplissage
    svgout.addTriangle(300,300, 400,300, 350,250, "green");

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(100, 320, "Hello Triangles !", Couleur{0,100,0} );

    /// Dessin de texte : xcentre ycentre texte couleur
    svgout.addText(342, 320, 6*7, "black");

    /// Dessin de croix : xcentre ycentre taille couleur
    svgout.addCross(400, 200, 25);

    /// Dessin de segments : x1 y1 x2 y2 couleur
    svgout.addLine(300, 70, 400, 70);
    svgout.addLine(300, 130, 400, 130);
    svgout.addLine(340, 70, 300, 30, "blue");
    svgout.addLine(360, 70, 400, 30, "red");

    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
}
