#include <iostream>
#include "sommet.h"*
#include "svgfile.h"
#include "graphe.h"


Sommet::Sommet(int indiceS,char nom,int coorX,int coorY)
 //ici on fait le construceur de la class sommet
{
    m_indiceS = indiceS;
    m_nom = nom;
    m_coorX = coorX;
    m_coorY = coorY;
}

void Sommet :: setindice(int indice)
 //seter de l'indice pour lui donner une valeure
{
    indice=m_indiceS;
}

int Sommet :: getindice()
 //geter de l'indice pour recuperer la valeur donnee
{
    return m_indiceS;
}

void Sommet :: setnom(char nom) //seter du nom pour lui donner un char
{
    nom=m_nom;
}

char Sommet :: getnom()
//geter du nom pour recuperer le nom du sommet si besoin
{
    return m_nom;
}


void Sommet :: setcoorX(int coorX)
//seter de la coor en X pour lui donner une valeure
{
    coorX=m_coorX;
}

void Sommet :: setcoorY(int coorY)

//seter de la coor en Y pour lui donner une vaeur
{
    coorY=m_coorY;
}

int Sommet :: getX()
//geter qui permet de recuperer la coor en X d'un sommmet
{
    return m_coorX;
}

int Sommet :: getY()
//geter qui permet de recuperer la coor en Y d'un sommmet
{
    return m_coorY;
}


void Sommet :: afficher_sommet()
//methode d'affichage en console de'un sommet qui sera appeler par la fonction d'affichage d'un graphe en cosole
{
       std::cout<< m_indiceS << m_nom<< m_coorX << m_coorY;
}


