#include <iostream>
#include <vector>
#include <fstream>
#include <string>



void lire_fichier(std::string *nomF)
{
    std::string m_nom_fichier;
    m_nom_fichier = *nomF;
    std::ifstream graphe(m_nom_fichier);

    using namespace std;

    if (graphe)
    {
        int orientation;
        graphe>>orientation;
        std::cout<< orientation<<endl;


        int ordreS;
        graphe>>ordreS;
        std :: cout << ordreS<<endl;

        for (int i=1 ; i <= ordreS ; ++i)
        {
            int indiceS;
            graphe>>indiceS;
            std :: cout << indiceS;

            char nom;
            graphe>>nom;
            std :: cout << nom;

            int coorX;
            graphe>>coorX;
            std :: cout << coorX;

            int coorY;
            graphe>>coorY;
            std :: cout << coorY;

            cout<<endl;
        }

        int ordreA;
        graphe>>ordreA;
        std :: cout << ordreA<<endl;

        for ( int y=0 ; y < ordreA ; ++y)
        {
            int indiceA;
            graphe>>indiceA;
            std::cout << indiceA;

            int extremite1;
            graphe>>extremite1;
            std::cout << extremite1;

            int extremite2;
            graphe>>extremite2;
            std::cout << extremite2;

            cout<<endl;

        }
    }
    else
        std::cout<<"Impossible d'ouvrir le fichier"<< std::endl;
}

