#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "lecturefichier.h"

using namespace std;

int main()
{

    std:: string *nomF(0);
    std:: string nom;
    std::cout<< "Rentrez le nom du fichier sans oublier le .txt" <<endl;
    std::cin >> nom ;
    nomF = &nom ;

    lire_fichier(nomF);
}
