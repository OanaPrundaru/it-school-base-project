#include <iostream>
#include <vector>
#include <memory>
#include "Biblioteca.h"

int main()
{
    Biblioteca b;

    std::cout << "Incarcare date din fisierele CSV ! >" << std::endl;

    b.incarcaCarti("Carti.csv");
    b.incarcaMembri("Membri.csv");

    std::cout << "Afiseaza inventar carti: " << std::endl;
    b.afiseazaToateCartile();

    std::cout << "Afiseaza lista membri: " << std::endl;
    b.afiseazaTotiMembri();

    return 0;
}
