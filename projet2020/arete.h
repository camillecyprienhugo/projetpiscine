#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED


class Arete
{
    private :

        int m_indiceA;
        int m_extremite1;
        int m_extremite2;


    public :

        Arete(int indiceA, int extremite1, int extremite2);

        void setindiceA (int indiceA);
        void setextremite1 (int extremite1);
        void setextremite2 (int extremite2);

        void afficher_arete();



};

#endif // ARETE_H_INCLUDED
