#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED


class Arete
{
    private :
        //definition de la class arete qui comporte les attributs et les methodes qui permettent de bine gerer une arete

        int m_indiceA;
        //variable qui correspond a l'indice de l'arete
        int m_extremite1;
        //variable qui correspond a l'indice de son sommet 1
        int m_extremite2;
        //variable qui correspond a l'indice de son sommet 2
        int m_poids;
        //variable qui correspond au poids d'une arete


    public :

        Arete(int indiceA, int extremite1, int extremite2);

        void setindiceA (int indiceA);
        //tous les seter des differents attributs de la class arete
        void setextremite1 (int extremite1);
        void setextremite2 (int extremite2);
        void setpoids(int poids);

        int getextrem1();
        int getextrem2();

        void afficher_arete();
         //affichage des aretes en console
};

#endif // ARETE_H_INCLUDED
