#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <new>
#include "arete.h"
#include "graphe.h"
#include "sommet.h"
#include "svgfile.h"

Graphe :: Graphe()
{

}


void Graphe :: setorientation (int orientation)
{
    orientation = m_orientation;
}

void Graphe :: setordreA (int ordreA)
{
    ordreA = m_ordreA;
}

void Graphe :: setordreS (int ordreS)
{
    ordreS = m_ordreS;
}


void Graphe :: lire_fichier(std::string *nomF)
{
     std::string m_nom_fichier;
    m_nom_fichier = *nomF;
    std::ifstream graphe(m_nom_fichier);
    if (graphe)
    {
        graphe>>m_orientation;

        graphe>>m_ordreS;

        for (int i=0 ; i < m_ordreS ; ++i)
        {
            int indiceS;
            graphe>>indiceS;

            char nom;
            graphe>>nom;

            int coorX;
            graphe>>coorX;

            int coorY;
            graphe>>coorY;

            m_listeS.push_back(new Sommet{indiceS,nom,coorX,coorY}); //on injecte a chaque tour de la boucle les 4 indices
        }

        graphe>>m_ordreA;

        for ( int y=0 ; y < m_ordreA ; ++y)
        {
            int indiceA;
            graphe>>indiceA;

            int extremite1;
            graphe>>extremite1;

            int extremite2;
            graphe>>extremite2;

            m_listeA.push_back(new Arete {indiceA, extremite1, extremite2});  //on injecte a chaque tour de la boucle les 3 indices
        }
    }
    else
        std::cout<<"Impossible d'ouvrir le fichier"<< std::endl;
}




void Graphe:: afficher_grapheC ()
{
    std::cout<< m_orientation<<std::endl;

    std::cout<< m_ordreS<<std::endl;

    for (int i=0 ; i< m_ordreS; ++i)
    {
        m_listeS[i]->afficher_sommet();
        std::cout<<std ::endl;
    }

    std::cout<< m_ordreA<<std::endl;

    for (int i=0 ; i< m_ordreA; ++i)
    {
        m_listeA[i]->afficher_arete();
        std::cout<<std::endl;
    }
}

void Graphe :: svg_sommet()
{
      int coorx;
      int coory;
      Svgfile svgout;
      svgout.addGrid();


      for (int i=0 ; i< m_ordreS; ++i)
      {
          coorx = m_listeS[i]->getX();
          coory = m_listeS[i]->getY();
          svgout.addDisk(coorx*100,coory*100,10,"black");
      }

}



