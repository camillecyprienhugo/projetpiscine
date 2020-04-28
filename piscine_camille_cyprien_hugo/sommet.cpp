#include <iostream>
#include "sommet.h"


Sommet::Sommet(int indiceS,char nom,int coorX,int coorY)
{
    m_indiceS = indiceS;
    m_nom = nom;
    m_coorX = coorX;
    m_coorY = coorY;
}

void Sommet :: setindice(int indice)
{
    indice=m_indiceS;
}

void Sommet :: setnom(char nom)
{
    nom=m_nom;
}

void Sommet :: setcoorX(int coorX)
{
    coorX=m_coorX;
}

void Sommet :: setcoorY(int coorY)
{
    coorY=m_coorY;
}

void Sommet :: afficher_sommet()
{
       std::cout<< m_indiceS << m_nom<< m_coorX << m_coorY;
}
