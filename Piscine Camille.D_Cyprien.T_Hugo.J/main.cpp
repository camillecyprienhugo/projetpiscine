#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "svgfile.h"
#include "arete.h"
#include "graphe.h"

int main()
{
    std::cout<< "Bonjour quel fichier voulez vous traiter?"<<std::endl;
    Graphe a;

    std:: string *nomF(0); //on commence par demander a l'utilisateur de saisir le fichier qu'il veux traiter
    std:: string nom;
    std::cout<< "Rentrez le nom du fichier de topologie sans oublier le .txt" <<std::endl;
    std::cin >> nom ;
    nomF = &nom ;
    a.lire_fichier(nomF);

    std:: string *nomP(0);
    std:: string nomPo;
    std::cout<< "Rentrez le nom du fichier de ponderation sans oublier le .txt" <<std::endl;
    std::cin >> nomPo ;
    nomP = &nomPo ;
    a.ponderation(nomP);





    int choix;

    std::cout<<"1: Je veux afficher mon fichier topologique et de ponderation"<<std::endl;
    std::cout<<"2: Je veux afficher le graphe dans mon navigateur"<<std::endl;
    std::cout<<"3: Je voudrais connaitre le degre de chacun des sommets"<<std::endl;
    std::cout<<"4: Je voudrais afficher la centralite de vecteur propre"<<std::endl;
    std::cout<<"5: Quitter"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"votre choix: ";
    std::cin>>choix;

    switch(choix)
    {
    case 1:
        {
            a.afficher_grapheC();
        }break;
    case 2:
        {
            a.svg_sommet();
        }break;
    case 3:
        {
            a.degre_somm();
        }break;
    case 4:
        {
           a.vec_propre();
        }break;

    case 5:
        {
            exit(0);
        }break;
    }

}

