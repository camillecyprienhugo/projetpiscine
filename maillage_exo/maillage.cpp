#include "maillage.h"
#include "svgfile.h"
#include <iostream>

Maillage::Maillage()
{

}

void Maillage::ajouterSommet()
{
    Sommet *nouv= new Sommet;
    nouv->saisir();
    m_sommets.push_back(nouv);
}

void Maillage::afficherSommets() const
{
    for (size_t i=0; i<m_sommets.size(); ++i)
    {
        std::cout << i << ": ";
        m_sommets[i]->afficher();
        std::cout << std::endl;
    }
}

void Maillage::ajouterTriangle()
{
    if (m_sommets.size()<3)
    {
        std::cout << "Il n'y a pas assez de sommets pour former un triangle.";
    }
    else
    {
        Triangle *nouv = new Triangle;
        nouv->saisir(*this);
        m_triangles.push_back(nouv);
    }
}

Sommet *Maillage::trouverSommet() const
{
    size_t idChoix=0;
    do
    {
        std::cin >> idChoix;
        if (idChoix > m_sommets.size())
        {
            std::cout << "L'ID saisi ne correspond a aucun sommet. Reessayer: ";
        }
    } while (idChoix > m_sommets.size());
    return (m_sommets[idChoix]);
}

void Maillage::dessinerMaillage() const
{
    Svgfile svgout;
    svgout.addGrid();
    for (size_t i=0; i<m_triangles.size(); ++i)
    {
        m_triangles[i]->dessiner(svgout);
    }
    for (size_t i=0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->dessiner(svgout);
    }
}

void Maillage::selectionSommet(bool selectionDesiree)
{
    size_t idChoix=0;
    std::cout << "Veuillez choisir l'id du sommet a ";
    if (selectionDesiree == false)
    {
        std::cout << "de";
    }
    std::cout << "selectionner: ";
    do
    {
        std::cin >> idChoix;
        if (idChoix > m_sommets.size())
        {
            std::cout << "L'ID saisi ne correspond a aucun sommet. Reessayer: ";
        }
    } while (idChoix > m_sommets.size());
    m_sommets[idChoix]->setSelection(selectionDesiree);

}

void Maillage::translaterSommetsSelect()
{
    Coords vecTransl;
    std::cout << "Veuillez entrer les coordonnees du vecteur translation:" << std::endl;
    vecTransl.saisir();
    for (size_t i=0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->translaterSommet(vecTransl);
    }

}

Maillage::~Maillage()
{
    for (size_t i=0; i<m_triangles.size(); ++i)
    {
        delete m_triangles[i];
    }
    for (size_t i=0; i<m_sommets.size(); ++i)
    {
        delete m_sommets[i];
    }
}
