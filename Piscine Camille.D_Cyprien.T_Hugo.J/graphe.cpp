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
//constructeur de la class graphe
{

}


void Graphe :: setorientation (int orientation)
//set de l'indice d'orientation qui permet de definir une vaeut a cet indice
{
    orientation = m_orientation;
}

void Graphe :: setordreA (int ordreA)
//set de la taille du graphe qui corespond au nombre d'arete du graphe traité
{
    ordreA = m_ordreA;
}

void Graphe :: setordreS (int ordreS) //set de l'ordre du graphe etudie qui permet de con,naitre son nombre de sommet
{
    //cet indice est grandement utilise pour le parcour des sommet dans les algorithmes
    ordreS = m_ordreS;
}


void Graphe :: lire_fichier(std::string *nomF) //lecteure du fichier texte demande par l'utilisateur en console
{
    std::string m_nom_fichier;
    //on recupere le nom du fichier.txt demande par l'utilisateur
    m_nom_fichier = *nomF;
    std::ifstream graphe(m_nom_fichier);
    //on ouvre le fichier grace a ifstream (lecture seule)
    if (graphe)
        //condition qui permet de verifier que le fichier est bien ouvert
    {
        graphe>>m_orientation;
        //on lit le premier caracter qui correspond a l'indice d'orientation

        graphe>>m_ordreS;
        //on lit et recupere l'ordre du graphe (le nombre de sommet)

        for (int i=0 ; i < m_ordreS ; ++i)
            //on parcour les lignes suivantes grace a l'ordre du graphe
            //le nombre de ligne suivantes correspond à l'ordre du graphe
        {
            int indiceS;
            graphe>>indiceS;
            //on recupere l'indice de chaque sommet (premier indice de la ligne qui donne les information du sommet)

            char nom;
            graphe>>nom;
            //on lit et recupere le nom du sommet m_ordreS fois

            int coorX;
            graphe>>coorX;
            //on lit et recupere la coordonnne en X de chaque sommet

            int coorY;
            graphe>>coorY;
            //on lit et recupere la coordonne en Y de chaque sommet

            m_listeS.push_back(new Sommet{indiceS,nom,coorX,coorY}); //on injecte a chaque tour de la boucle les 4 indices que l'on vient de recuperer
        }

        graphe>>m_ordreA;

        for ( int y=0 ; y < m_ordreA ; ++y)
        {
            int indiceA;
            //on lit et recupere l'indice de chaque arete
            graphe>>indiceA;

            int extremite1;
            //on recupere les extremite de chaque arete qui correspondent au indice des sommet qu'elle possede
            graphe>>extremite1;

            int extremite2;
            //on recupere les extremite de chaque arete qui correspondent au indice des sommet qu'elle possede
            graphe>>extremite2;

            m_listeA.push_back(new Arete {indiceA, extremite1, extremite2});  //on injecte a chaque tour de la boucle les 3 indices
        }
    }
    else
        std::cout<<"Impossible d'ouvrir le fichier"<< std::endl;
    //si le fichier n'a pas pu etre ouvert on met un message d'erreur
}




void Graphe:: afficher_grapheC ()
//methode d'affichage des graphes precedement lu dans leur fichier
// ici on reproduit l'affichage du fichier texte en console
//cela peut etre un moyen de verifier que le fichier a bien ete lu
{
    std::cout<< m_orientation<<std::endl; //on affiche chaque inforation tel qu'elle a ete enregistre dans la methode ci-dessus

    std::cout<< m_ordreS<<std::endl;

    for (int i=0 ; i< m_ordreS; ++i)
        //on parcour chaque sommet pour en afficher les informations (indice nom X et Y)
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
//ici nous allons afficher notre graphe sous forme de schema visible dans un navigateur internet
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
        //nous parcourons les sommets de notre graphe pour tracer des cercles et on en profite pour marque leur noms
    {
        coorx = m_listeS[i]->getX();
        //pour afficher un disque nous avons besoin des coordonnes en X du sommet
        coory = m_listeS[i]->getY();
        //pour afficher un disque nous avons besoin des coordonnes en Y du sommet
        svgout.addDisk(coorx*100,coory*100,10,"blue");
        //nous choisissons une valeur arbitraire qui sera notre cooeficient pour l'affichage etant donne la taille de notre fenetre. nous definissons la couleur bleu
        texte=m_listeS[i]->getnom();
        svgout.addText(coorx*120,coory*110,texte,"black");
    }

    for (int i=0 ; i< m_ordreA; ++i)
        //nous parcourons les aretes pour tracer des traits entre les sommets du graphes qui sont adjacents
    {
        indix=m_listeA[i]->getextrem1();
        //on commence par recupere les expremites de l'aretes qui sont les indices des sommetes auxquelles elles sont reliees
        indiy=m_listeA[i]->getextrem2();

        coorx = m_listeS[indix]->getX();
        //grace aux extremites des aretes on recupere les coordonnes des sommets
        coory = m_listeS[indix]->getY();
        coorxx = m_listeS[indiy]->getX();
        //nous avons besoin de ces 4 informations car les deux extremites du trait possedent des coordonnes selon X et Y
        cooryy = m_listeS[indiy]->getY();

        svgout.addLine(coorx*100, coory*100, coorxx*100, cooryy*100, "black");
        //nous choisissons une valeur arbitraire qui sera notre cooeficient pour l'affichage etant donne la taille de notre fenetre. nous definissons la couleur noir

    }

}

void Graphe :: degre_somm()
//ici nous voulons calculer le degres des sommet à savoir à combien d'autres sommets ils sont adjacent
{
    int degre=0;
    char lettre;
    int a;
    int b;

    for (int i=0 ; i<m_ordreS; ++i)
        //nous parcourons chaque sommet de notre graphe
    {
        //std::cout << "testaaaa"<<std::endl;
        for (int j=0 ; j<m_ordreA; ++j)
            //puis nous parcourons chaque arete de ce graphe pour chaque sommet (for dans for)
        {
            a=m_listeA[j]->getextrem1();
            //nous recuperons l'indice extremite 1 de l'arete
            b=m_listeA[j]->getextrem2();
            //nous recuperons l'indice extremite 2 de l'arete

            //std::cout << "testbbbb"<<std::endl;
            if ((i==a)||(i==b) )
                //si l'extremite1 de l'arete (qui correspond a l'indice d'un sommet) est egale a l'indice du sommet traite   ou   inversement
            {
                degre = degre+1;
                //alors le degre de se sommet augment de 1 jusqu'a la fin du parcour des aretes.
                //std::cout << "testcccc"<<std::endl;
            }
            else
            {

            }
            //degre=0;
        }

        lettre = m_listeS[i]->getnom();
        //ici nous recouperons le nom de l'arete pour que l'affichage soit plus lisible
        std::cout<< " le degre de " << lettre << " est " << degre << std::endl;
        //on afficeh donc le nom de l'arete et son degre
        degre=0;
    }
}


void Graphe :: vec_propre() //ici nous cherchons à calculer l'indice de veteur propre
{
    std::vector<double>c(m_ordreS,0);
    //on declare un vecteur qui stokera les sommes de cvp
    std::vector<double>cvp(m_ordreS,1);
    //on declare un vecteur de cvp
    double somm=0;
    //cette variable permet de stocker les sommes au carree des cvp
    double lambda=0;
    //declaration de la variable lambda
    double delta=0;
    //declaration de la variable qui est utilise pour garder en tampon le lampda precendente
    double lambdapreced;
    //permet de retenir la valeutr de lambda a chaque tour


    do //
    {


        lambdapreced=lambda;
        somm=0;


        for (int i=0; i<m_ordreS; ++i) //notre vecteur qui permet de faire la somme revient a 0 car les cvp changent
        {
            c[i]=0;
        }

        for (int i=0 ; i<m_ordreS; ++i) //parcour des sommets
        {
            for (int j=0 ; j<m_ordreA ; ++j)
                //parcour des aretes
            {
                if (m_listeA[j]->getextrem1()==i)
                    //si l'extremite1 de l'arete est egale
                {
                    //val=m_listeA[j]->getextrem2(); ///alors val prend la valeur de l'extremite 2 (indce d'un sommet)
                    c[i]=c[i]+cvp[i];
                    //on met l'indice du sommet adjacent dans un vecteur du sommet traité
                    //std::cout<< "test1"<<c[i]<<std::endl;
                }
                else {}
                if (m_listeA[j]->getextrem2()==i)
                    //iverse du premier
                {
                    //val=m_listeA[j]->getextrem1();
                    c[i]=c[i]+cvp[i];
                    //std::cout<< "test2"<<c[i]<<std::endl;
                }
                else {}
                //std::cout<<c[i]<<std::endl;

            }
        }

        for (int i=0; i<m_ordreS; ++i)
        {
            somm = somm + (c[i]*c[i]);
        }

        lambda=sqrt(somm);
        //std::cout<<"lambda= "<< lambda <<std::endl;


        for (int i=0; i<m_ordreS; ++i)
        {
            cvp[i]= c[i]/lambda;
            //std::cout<<"cvp=="<<cvp[i]<<std::endl;
        }

        delta=lambdapreced-lambda;
        //on fait la diference entre le lamda precedent et le nouveau

        if (delta<0)
        {
            delta=-delta; ///on fait la valeur absolue de cette difference.
        }

    }
    while(delta>=0.01);
    //condition detreminee grace aux orbservation. on cosidere que lambda est stable si entre deux tour il varie moins que 0,01

    for (int i=0; i<m_ordreS; i++)
    {
        std::cout<< "le vecteur propre de "<<m_listeS[i]->getnom()<< " egal " << cvp[i]<<std::endl; //on affiche le resultat obtenue en console

    }
}

void Graphe :: ponderation (std :: string*nomP)
{
    /// **OUVERTURE DU FICHIER DE PONDERATION**
    std::string m_nom_ponderation;
    m_nom_ponderation = *nomP;
    std::ifstream ponderation(m_nom_ponderation);

    if (ponderation)
    {

        ponderation>>m_ordreA;

        for (int i=0 ; i < m_ordreA ; ++i)
        {
            int indiceA;
            ponderation>>indiceA;

            int poids;
            ponderation>>poids;

            m_listeA[i]->setpoids(poids); //on injecte à chaque tour le poids de chaque arete
        }

    }
}




//ici je rajouterais en commentaire l'algorithme de dijkstra que nous n'avons pas reussi a faire fonctionner mais

/* CODE PROVENANT DE : https://www.40tude.fr/algorithme-de-dijkstra-en-c/ : on a essayé de l'adapter à notre code en vain, plusieurs tentatives
                                                                            on été effectué en vain également !
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
FIN DU CODE PROVENANT DE : https://www.40tude.fr/algorithme-de-dijkstra-en-c/
*/

