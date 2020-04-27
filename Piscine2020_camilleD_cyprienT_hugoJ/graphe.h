#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

class graphe
{
    private :

        int ordreS;
        bool orientation;
        int ordreA;

        std::vector<sommet*>m_listeS;
        std::vector<arete*>m_listeA

    public :
        graphe ();
        ~graphe();

        void lire_fichier();
};


#endif // GRAPHE_H_INCLUDED
