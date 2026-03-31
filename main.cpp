
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

    int optiune;
    while (true)
    {
        std::cout << "\n  MENIU BIBLIOTECA  \n";
        std::cout << " 1. Afiseaza toate cartile\n";
        std::cout << " 2. Afiseaza toti membrii \n";
        std::cout << " 3. Imprumuta o carte \n";
        std::cout << " 4. Afiseaza carti disponibile\n";
        std::cout << " 0. Iesire\n";
        std::cout << " Alege o optiune: \n";
        std::cin >> optiune;

        switch (optiune)
        {
        case 1:
            b.afiseaza_toate_cartile();
            break;

        case 2:
            b.afiseaza_toti_membrii();
            break;

        case 3:
        {
            int idPersoana;
            std::string isbnCarte;

            std::cout << "Introduceti ID-ul membrului: " << std::endl;
            std::cin >> idPersoana;
            std::cin.ignore(1000, '\n');

            std::cout << " Introduceti ISBN-ul cartii: " << std::endl;
            std::getline(std::cin, isbnCarte);
            b.Imprumuta_carte(idPersoana, isbnCarte);
            break;
        }

        case 4:
            b.afiseaza_carti_disponibile();
            break;

        case 0:
            b.salveaza_carti("Carti.csv");
            b.salveaza_membri("Membri.csv");
            std::cout << "Date salvate. La reverdere!\n";
            exit(-1);

        default:
            std::cout << " Optiune invalida! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            break;
        }
    }


    return 0;
}
