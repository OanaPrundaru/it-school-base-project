#include "Persoana.h"
#include <iostream>
#include <algorithm>
#include <vector>

Persoana::Persoana(int ID, std::string Nume)
    : ID(ID), Nume(Nume) {}

int Persoana::getID() const { return ID; }
std::string Persoana::getNume() const { return Nume; }

void Persoana::Adauga_carte(Carte *Carte)
{
    if(Carte == nullptr){
        std::cout << "Cartea nu este valida!\n";
        return;
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