#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <new>
#include <math.h>
#include <queue>
#include <limits>
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

        svgout.addLine(coorx*100, coory*100, coorxx*100, cooryy*100, "black");

    }

}

void Graphe :: degre_somm()
{
    int degre=0;
    char lettre;
    int a;
    int b;

    for (int i=0 ; i<m_ordreS; ++i)
    {
        //std::cout << "testaaaa"<<std::endl;
        for (int j=0 ; j<m_ordreA; ++j)
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


        for (int i=0; i<m_ordreS; ++i)
        {
            c[i]=0;
        }

        for (int i=0 ; i<m_ordreS; ++i) //parcour des sommets
        {
            for (int j=0 ; j<m_ordreA ; ++j) //parcour des aretes
            {
                if (m_listeA[j]->getextrem1()==i) ///si l'extremite1 de l'arete est egale
                {
                    //val=m_listeA[j]->getextrem2(); ///alors val prend la valeur de l'extremite 2 (indce d'un sommet)
                    c[i]=c[i]+cvp[i];///on met l'indice du sommet adjacent dans un vecteur du sommet traité
                }
                else {}
                if (m_listeA[j]->getextrem2()==i) ///iverse du premier
                {
                    //val=m_listeA[j]->getextrem1();
                    c[i]=c[i]+cvp[i];
                }
                else {}
                //std::cout<<c[i]<<std::endl;

            }
        }

        for (int i=0; i<m_ordreS; ++i)
        {
            C = C + (c[i]*c[i]);
        }

        lambda=sqrt(C);

        for (int i=0; i<m_ordreS; ++i)
        {
            cvp[i]=(c[i]/lambda);
        }

        plambda=lambda-t;

        if (plambda<0)
        {
            plambda=-plambda;
        }

    }
    while(plambda>0.01);

    for (int i=0; i<m_ordreS; i++)
    {
        std::cout<< "le vecteur propre de "<<m_listeS[i]->getnom()<< " egal " << cvp[i]<<std::endl;

    }


}

void Graphe :: ponderation ()
{
    /// ***OUVERTURE DU FICHIER DE PONDERATION***
    std::ifstream ponderation("extroiP.txt");
    if (ponderation)
    {

        ponderation>>m_ordreA;

        for (int i=0 ; i < m_ordreA ; ++i)
        {
            int indiceA;
            ponderation>>indiceA;

            int poids;
            ponderation>>poids;

            m_listeA[i]->setpoids(poids); ///on injecte à chaque tour le poids de chaque arete
        }

    }
}



void Graphe :: Dijkstra ()
{


    using namespace std;

    auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    };


    //ifstream TestFile("Test Dijkstra 3.txt", ios::in);                            // open the test file
    //if (!TestFile) return 1;
    //cin.rdbuf(TestFile.rdbuf());

    //int NbNodes, NbEdges;
    //cin >> NbNodes >> NbEdges;

    vector<vector<pair<int, int>>> G(m_ordreS);                                    // The graph is a vector with NbNodes nodes.
    // Each node is connected to others nodes via weighted edges. This information is stored in a vector of pair
    for (auto i = 0; i != m_ordreA; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));                                            // Each pair contains : first=index of the node connected to u, second=weight/distance/codst of the path from v to u
        G[v].push_back(make_pair(u, w));                                          // Comment this line if the graph use directed edges.
        // With undirected edges, create link from v to u and u to v. Both with weight w
    }

    int  noeudDepart;
    cout << "Veuillez rentrer le sommet initial"<< endl;
    cin >> noeudDepart;


    vector<int> Distances(m_ordreS, numeric_limits<int>::max());                   // Distances is a vector of NbNodes cells. All cells are initialized with max()
    // Distances[i] is the distance from StartNode to node whose index is i

    Distances[noeudDepart] = 0;                                                     // Distance to StartNode is initialized to 0

    vector<int> Parents(m_ordreS, -1);                                             // Parents is a vector of NbNodes cells. All cells are initialized with -1

    // Priority queue storing pairs and using a specific comparator function
    // Because of the comparator we need to specify the 3 parameters
    // The comparator make sure that the closest node is always on top of the queue
    // Each pair is made of : index of the node and the distance to StartNode
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);
    Q.push(make_pair(noeudDepart, 0));                                              // Initialize the priority queue with StartNode

    while (!Q.empty())                                                            // Dijkstra
    {
        int v = Q.top().first;                                                      // get the index of the nearest node
        int w = Q.top().second;                                                     // get the weight/cost/distance
        Q.pop();

        if (w <= Distances[v])                                                      // Pay attention to this test.
        {
            // It can be removed, however, it avoid duplicated work

            for (const auto& i : G[v])                                                // v is the index of the nearest node
            {
                auto v2 = i.first;                                                      // For each node connected to node v
                auto w2 = i.second;

                if (Distances[v] + w2 < Distances[v2])                                  // If distance from StartNode to v2 thru v is shorter then the current distance from StartNode to v2
                {
                    Distances[v2] = Distances[v] + w2;                                    // then update the distance from StartNode to v2 and parent[v2]
                    Parents[v2] = v;                                                      // https://www.youtube.com/watch?v=8Ls1RqHCOPw
                    Q.push(make_pair(v2, Distances[v2]));
                }
            }
        }
    }

    for (auto i = 0; i != m_ordreS; ++i)                                            // display the results
    {
        std::cout << "\La longueur depuis le noeud " << noeudDepart << " au noeud " << i << " mesure " << Distances[i] << endl;

        std::cout << i;
        for (auto p = Parents[i]; p != -1; p = Parents[p])
        {
            std::cout << " <- " << p;                                                      // when links are not bi directional the output is accurate when using <- instead of ->
            std::cout << endl;
        }                                                              // otherwise it make no difference
    }
    getchar();
}


/*** DEBUT DE DIJKSTRA***
void Graphe :: Dijkstra ()
{


double num_s0;
    std::cout << "Veuillez rentrer le sommet initial"<< std::endl;
    std::cin >> num_s0;

 /// Initialisation
 std::vector<double> distance((int)m_listeS.size(),-1);
 distance[num_s0]=0;



}
/* auto cmp = [](std::pair<const Sommet*,double> p1, std::pair<const Sommet*,double> p2)
 {
     return p2.second<p1.second;
 };
 std::priority_queue<std::pair<const Sommet*,double>,std::vector<std::pair<const Sommet*,double>>,decltype(cmp)> file(cmp);
 file.push({m_listeS[num_s0],0});

 p=file.top();
 file.pop();
 while((!file.empty())&&(couleurs[p.first->getNum()]))
 {
     p=file.top();
     file.pop();
 }
}*/

/*
void Graphe :: Dijksra()
{
    ///***CODE MADAME PALASI***
    std::vector<int> couleurs((int)m_listeS.size(),0);
    std::vector<int> preds((int)m_listeS.size(),-1);
    std::queue<const Sommet*>file;
    file.push(m_listeS[num_s0]);
    couleurs[num_s0]=1;
    while(!file.empty())
    {
        s=file.front();
        file.pop();
        for(auto succ:s->getSuccesseurs())
        {
            if(couleurs[succ->getNum()]==0)
                file.push(succ);
            couleurs[succ->getNum()]=1;
            preds[succ->getNum()]= s->getNum();
        }
    }
    return preds;
    ///*** FIN CODE MADAME PALASI ***
}*/

