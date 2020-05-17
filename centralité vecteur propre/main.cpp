#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int compteur=0;
    int ligne=0;
    int colonne=0;
    int degre=0;
    int voisin1=0;
    int voisin2=0;
    int i=0;
    int N=9; //nombre de sommet dans le graphe
    int arete[12][2]; //tableau avec tt les infos des aretes faudra mettre un vector a la place mais ca marchait pas
    vector<int> voisin;

    arete[0][0]=0; //je rempli manuellement les indices des 2 sommets correspondant ex1 page 8 pareil faire avec un vector
    arete[0][1]=1;
    arete[1][0]=0;
    arete[1][1]=2;
    arete[2][0]=1;
    arete[2][1]=3;
    arete[3][0]=2;
    arete[3][1]=3;
    arete[4][0]=3;
    arete[4][1]=4;
    arete[5][0]=3;
    arete[5][1]=6;
    arete[6][0]=1;
    arete[6][1]=7;
    arete[7][0]=2;
    arete[7][1]=8;
    arete[8][0]=4;
    arete[8][1]=5;
    arete[9][0]=5;
    arete[9][1]=6;
    arete[10][0]=6;
    arete[10][1]=8;
    arete[11][0]=4;
    arete[11][1]=7;




    for(compteur=0;compteur<N;compteur++) //pour chacun des sommets
    {
        for(colonne=0;colonne<=11;colonne++)
        {
            if(arete[colonne][0]==compteur)
                //voisin1=aret e[colonne][1];
                //voisin.push_back(voisin1);
                cout << arete[colonne][1] << " est un voisin de "<< compteur << endl;

            if(arete[colonne][1]==compteur)
                //voisin2=arete[colonne][0];
                //voisin.push_back(voisin2);
                cout << arete[colonne][0] << " est un voisin de "<< compteur << endl;
                h=voisin.size;


        }

    }

    return 0;
}
