#include "arete.h"
#include <iostream>

Arete :: Arete(int indiceA,int extremite1,int extremite2)
//constructeur de la class arete
{
    m_indiceA = indiceA;
    m_extremite1 = extremite1;
    m_extremite2 = extremite2;
}

void Arete :: setindiceA (int indiceA)
//seter de l'indice d'una arete pour modifier cette valeur ou la definir en lisant un fichier txt
{
    indiceA = m_indiceA;
}

void Arete :: setextremite1 (int extremite1)
//seter de l'extremite 1 de l'arete qui correspond a un indice de sommet
{
    extremite1 = m_extremite1;
}

void Arete :: setextremite2 (int extremite2)
//seter de l'extremite 2 de l'arete qui correspond a l'indice d'un autre sommet
{
    extremite2 = m_extremite2;
}

int Arete :: getextrem1 ()
 //geter de l'extremite 1 de l'arete qui permet de la recuperer
{
    return m_extremite1;
}

int Arete :: getextrem2()
//geter de l'extremite 1 de l'arete qui permet de la recuperer
{
    return m_extremite2;
}

void Arete :: afficher_arete()
//methode d'affichage en console d'une arete qui sera appeler par la fonction d'affichage d'un graphe en cosole
{
    std::cout << m_indiceA << m_extremite1 << m_extremite2<<" "<<m_poids;
}

void Arete :: setpoids (int poids)
{
    m_poids = poids;
}
//seter du poids de aretes
