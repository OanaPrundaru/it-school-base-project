
#include <iostream>
#include <vector>
#include <memory>
#include <stdio.h>
#include "Biblioteca.h"

int main()
{
    std::string pathCarti = "../../Carti.csv"; 
    std::string pathMembri = "../../Membri.csv";
    Biblioteca b;

    std::cout << "Incarcare date din fisierele CSV ! >" << std::endl;

    b.incarcaCarti(pathCarti);
    b.incarcaMembri(pathMembri);

    int optiune;
    while (true)
    {
        std::cout << "\n  MENIU BIBLIOTECA  \n";
        std::cout << " 1. Afiseaza toate cartile\n";
        std::cout << " 2. Afiseaza toti membrii \n";
        std::cout << " 3. Imprumuta o carte \n";
        std::cout << " 4. Returneaza o carte \n";
        std::cout << " 5. Afiseaza carti disponibile\n";
        std::cout << " 6. Adauga carti manual\n";
        std::cout << " 7. Sterge carti manual\n";
        std::cout << " 8. Adauga membri manual\n";
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
            b.returneaza_carte(pathCarti);

        case 5:
            b.afiseaza_carti_disponibile(pathCarti);
            break;

        case 6:
            b.adauga_carte_manual();
            break;

        case 7:
            b.sterge_carte_manual();
            break;

        case 8:
            b.adauga_persoana_manual();
            break;

        case 0:
            b.salveaza_carti(pathCarti);
            b.salveaza_membri(pathMembri);
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
