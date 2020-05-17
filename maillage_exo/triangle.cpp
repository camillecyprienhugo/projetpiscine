#include "triangle.h"
#include "maillage.h"
#include "svgfile.h"
#include "styledessin.h"
#include <iostream>

Triangle::Triangle(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : m_couleur{rouge, vert, bleu}
{ }

Triangle::Triangle()
    : Triangle{0, 0, 0}
{ }

void Triangle::afficher() const
{
    m_couleur.afficher();
}

void Triangle::saisir(const Maillage& maillageActuel)
{
    /// Cette méthode a été réalisée avec l'aide du code en page 5 du sujet de TDTP6
    std::cout << "Veuillez entrer a la suite les identifiants des 3 sommets a selectionner: " << std::endl;
    for (size_t i=0; i<3; ++i)
    {
        m_sommets[i]=maillageActuel.trouverSommet();
    }

    m_couleur.saisir();
}

void Triangle::dessiner(Svgfile& svgout) const
{
    StyleDessin style;
    if (style.dessinerAretes == true)
    {
        svgout.addTriangle(m_sommets[0]->getX(), m_sommets[0]->getY(), m_sommets[1]->getX(), m_sommets[1]->getY(), m_sommets[2]->getX(), m_sommets[2]->getY(), m_couleur, style.epaisseurArete, style.couleurArete );
    }
    else
    {
        svgout.addTriangle(m_sommets[0]->getX(), m_sommets[0]->getY(), m_sommets[1]->getX(), m_sommets[1]->getY(), m_sommets[2]->getX(), m_sommets[2]->getY(), m_couleur);
    }
}

Couleur Triangle::getCouleur() const
{
    return (m_couleur);
}
