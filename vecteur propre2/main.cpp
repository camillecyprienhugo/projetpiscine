#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int nombreS=5; ///nombre de sommet
    int cv[4]; ///centralité de vecteur propre
    int c[4];
    int degre[4];
    int lambda=0;
    int carre=0;

    degre[0]=1;
    degre[1]=1;
    degre[2]=4;
    degre[3]=1;
    degre[4]=1;


    int i=0;
    int j=0;
    int h=0;
    int k=0;

    for(i=0; i<5; i++)
    {
        cv[i]=1;
    }
    for(j=0; j<5; j++)
    {
        c[j]=degre[j];
    }
    for (h=0; h<5; h++)
    {
        degre=c[h]+degre;
        lambda=sqrt()
    }
    for(k=0;k<5;k++)
    {
        cv[k]=c[k]/lambda;
        cout<< "le vecteur propre de "<< k << " est " << cv[k] << endl;
    }

    return 0;
}
