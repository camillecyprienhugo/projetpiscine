#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <new>
#include <math.h>
#include "arete.h"
#include "graphe.h"
#include "sommet.h"
#include "svgfile.h"

Graphe :: Graphe()
{

}


void Graphe :: setorientation (int orientation)
{
    orientation = m_orientation;
}

void Graphe :: setordreA (int ordreA)
{
    ordreA = m_ordreA;
}

void Graphe :: setordreS (int ordreS)
{
    ordreS = m_ordreS;
}


void Graphe :: lire_fichier(std::string *nomF)
{
     std::string m_nom_fichier;
    m_nom_fichier = *nomF;
    std::ifstream graphe(m_nom_fichier);
    if (graphe)
    {
        graphe>>m_orientation;

        graphe>>m_ordreS;

        for (int i=0 ; i < m_ordreS ; ++i)
        {
            int indiceS;
            graphe>>indiceS;

            char nom;
            graphe>>nom;

            int coorX;
            graphe>>coorX;

            int coorY;
            graphe>>coorY;

            m_listeS.push_back(new Sommet{indiceS,nom,coorX,coorY}); //on injecte a chaque tour de la boucle les 4 indices
        }

        graphe>>m_ordreA;

        for ( int y=0 ; y < m_ordreA ; ++y)
        {
            int indiceA;
            graphe>>indiceA;

            int extremite1;
            graphe>>extremite1;

            int extremite2;
            graphe>>extremite2;

            m_listeA.push_back(new Arete {indiceA, extremite1, extremite2});  //on injecte a chaque tour de la boucle les 3 indices
        }
    }
    else
        std::cout<<"Impossible d'ouvrir le fichier"<< std::endl;
}




void Graphe:: afficher_grapheC ()
{
    std::cout<< m_orientation<<std::endl;

    std::cout<< m_ordreS<<std::endl;

    for (int i=0 ; i< m_ordreS; ++i)
    {
        m_listeS[i]->afficher_sommet();
        std::cout<<std ::endl;
    }

    std::cout<< m_ordreA<<std::endl;

    for (int i=0 ; i< m_ordreA; ++i)
    {
        m_listeA[i]->afficher_arete();
        std::cout<<std::endl;
    }
}

void Graphe :: svg_sommet()
{
      int coorx;
      int coory;
      int indix;
      int indiy;
      int coorxx;
      int cooryy;
      std::string texte;
      Svgfile svgout;
      svgout.addGrid();


      for (int i=0 ; i< m_ordreS; ++i)
      {
          coorx = m_listeS[i]->getX();
          coory = m_listeS[i]->getY();
          svgout.addDisk(coorx*100,coory*100,10,"black");
          texte=m_listeS[i]->getnom();
          svgout.addText(coorx*120,coory*110,texte,"black");
      }

      for (int i=0 ; i< m_ordreA; ++i)
      {
          indix=m_listeA[i]->getextrem1();
          indiy=m_listeA[i]->getextrem2();

          coorx = m_listeS[indix]->getX();
          coory = m_listeS[indix]->getY();
          coorxx = m_listeS[indiy]->getX();
          cooryy = m_listeS[indiy]->getY();

          svgout.addLine(coorx*100, coory*100 , coorxx*100, cooryy*100, "black");

      }

}

void Graphe :: degre_somm()
{
    int degre=0;
    char lettre;
    int a;
    int b;

        for (int i=0 ; i<m_ordreS;++i)
        {
            //std::cout << "testaaaa"<<std::endl;
            for (int j=0 ; j<m_ordreA;++j)
            {
                a=m_listeA[j]->getextrem1();
                b=m_listeA[j]->getextrem2();

                //std::cout << "testbbbb"<<std::endl;
                if ((i==a)||(i==b) )
                {
                    degre = degre+1;
                    //std::cout << "testcccc"<<std::endl;
                }
                else
                {

                }
                    //degre=0;
            }

            lettre = m_listeS[i]->getnom();
            std::cout<< " le degre de " << lettre << " est " << degre << std::endl;
            degre=0;
        }
}


void Graphe :: vec_propre()
{
    std::vector<double>c(m_ordreS,0);
    std::vector<double>cvp(m_ordreS,1);
    double C=0;
    double lambda=0;
    double plambda=0;
    double t;


    do
    {


        t=lambda;
        C=0;


        for (int i=0; i<m_ordreS;++i)
        {
            c[i]=0;
        }

        for (int i=0 ; i<m_ordreS;++i) //parcour des sommets
        {
            for (int j=0 ; j<m_ordreA ; ++j) //parcour des aretes
            {
                if (m_listeA[j]->getextrem1()==i) ///si l'extremite1 de l'arete est egale
                {
                    //val=m_listeA[j]->getextrem2(); ///alors val prend la valeur de l'extremite 2 (indce d'un sommet)
                    c[i]=c[i]+cvp[i];///on met l'indice du sommet adjacent dans un vecteur du sommet traité
                }
                else{}
                if (m_listeA[j]->getextrem2()==i) ///iverse du premier
                {
                    //val=m_listeA[j]->getextrem1();
                    c[i]=c[i]+cvp[i];
                }
                else{}
           //std::cout<<c[i]<<std::endl;

             }
        }

        for (int i=0;i<m_ordreS;++i)
        {
            C = C + (c[i]*c[i]);
        }

    lambda=sqrt(C);

        for (int i=0;i<m_ordreS;++i)
        {
            cvp[i]=(c[i]/lambda);
        }

    plambda=lambda-t;

        if (plambda<0)
        {
            plambda=-plambda;
        }

    }while(plambda>0.01);

    for (int i=0;i<m_ordreS;i++)
    {
        std::cout<< "le vecteur propre de "<<m_listeS[i]->getnom()<< "egal" << cvp[i]<<std::endl;

    }


}




