#include "arete.h"
#include <iostream>

Arete :: Arete(int indiceA,int extremite1,int extremite2)
{
    m_indiceA = indiceA;
    m_extremite1 = extremite1;
    m_extremite2 = extremite2;
}

void Arete :: setindiceA (int indiceA)
{
    indiceA = m_indiceA;
}

void Arete :: setextremite1 (int extremite1)
{
    extremite1 = m_extremite1;
}

void Arete :: setextremite2 (int extremite2)
{
    extremite2 = m_extremite2;
}

void Arete :: afficher_arete()
{
    std::cout << m_indiceA << m_extremite1 << m_extremite2;
}
