#include "Persoana.h"
#include <iostream>
#include <algorithm>

Persoană::Persoana(std::string Nume, int ID)
    : Nume(Nume), ID(ID) {}

std::string Persoana::getNume() const { return Nume; }
int Persoana::getID() const { return ID; }

void Persoana::Adauga_carte(Carte *Carte)
{
    if (Carte != nullptr)
    {
        Carti_imprumutate.push_back(Carte);
    }
}

void Persoana::returneaza_Carte(const std::string &ISBN)
{
    Carti_imprumutate.erase(
        std::remove_if(Carti_imprumutate.begin(), Carti_imprumutate.end(), [&ISBN](Carte *Carte)
                       { return Carte->getISBN() == ISBN; }),
        Carti_imprumutate.end());
}

void Persoana::afisare_Activitate() const
{
    std::cout << "Utilizator: " << Nume << "(ID: " << ID << ")\n";
    if (Carti_imprumutate.empty())
    {
        std::cout << " Nu are cărți împrumutate!\n";
    }
    else
    {
        std::cout << " Cărți în posesie: \n ";
    }
    for (const auto &Carte : Carti_imprumutate)
    {
        std::cout << " *" << Carte->getTitlu() << " [ " << Carte->getISBN() << "]\n";
    }
};