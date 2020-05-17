#include "sommet.h"
#include "svgfile.h"
#include "styledessin.h"

Sommet::Sommet(double x, double y)
    : m_position{x, y}
{ }

Sommet::Sommet()
    : m_position{0, 0}
{ }

void Sommet::afficher() const
{
    m_position.afficher();
}

void Sommet::saisir()
{
    m_position.saisir();
}

void Sommet::dessiner(Svgfile& svgout) const
{
    StyleDessin style;
    if (style.dessinerSommets == true)
        svgout.addDisk(m_position.getX(), m_position.getY(), style.rayonSommet, style.couleurSommet);
    if (m_selectionne)
        svgout.addCircle (m_position.getX(), m_position.getY(), style.rayonSommetSelect, style.epaisseurSommetSelect, style.couleurSommetSelect);
}

double Sommet::getX() const
{
    return (m_position.getX());
}

double Sommet::getY() const
{
    return (m_position.getY());
}

void Sommet::setSelection(bool selection)
{
    m_selectionne=selection;
}

void Sommet::translaterSommet(Coords vecTranslation)
{
    if (m_selectionne)
        m_position = m_position + vecTranslation;
}
