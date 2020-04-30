#include <iostream>
#include "sommet.h"*
#include "svgfile.h"
#include "graphe.h"


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

int Sommet :: getX()
{
    return m_coorX;
}

int Sommet :: getY()
{
    return m_coorY;
}

void Sommet :: setsommetadj(int i)
{
    m_sommetadj.push_back(i);
}

std::vector<int> Sommet :: getsommetadj()
{
    return m_sommetadj;
}


void Sommet :: setsomm (int i)
{
    m_somm.push_back(i);
}

int Sommet :: getsomm (int i)
{
    return m_somm[i];
}

void Sommet :: setcvp (double cvp)
{
    cvp=m_cvp;
}

double Sommet :: getcvp()
{
    return m_cvp;
}



char Sommet :: getnom()
{
    return m_nom;
}

void Sommet :: afficher_sommet()
{
       std::cout<< m_indiceS << m_nom<< m_coorX << m_coorY;
}


