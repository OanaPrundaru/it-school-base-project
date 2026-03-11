#include "Persoană.h"
#include <iostream>
#include <algorithm>

Persoană::Persoană(std::string Nume, int ID)
    : Nume(Nume), ID(ID) {}

std::string Persoană::getNume() const { return Nume; }
int Persoană::getID() const { return ID; }

void Persoană::Adaugă_carte(Carte *Carte)
{
    if (Carte != nullptr)
    {
        Cărți_împrumutate.push_back(Carte);
    }
}

void Persoană::returnează_Carte(const std::string &ISBN)
{
    Cărți_împrumutate.erase(
        std::remove_if(Cărți_împrumutate.begin(), Cărți_împrumutate.end(), [&ISBN](Carte *Carte)
                       { return Carte->getISBN() == ISBN; }),
        Cărți_împrumutate.end());
}

void Persoană::afișare_Activitate() const
{
    std::cout << "Utilizator: " << Nume << "(ID: " << ID << ")\n";
    if (Cărți_împrumutate.empty())
    {
        std::cout << " Nu are cărți împrumutate!\n";
    }
    else
    {
        std::cout << " Cărți în posesie: \n ";
    }
    for (const auto &Carte : Cărți_împrumutate)
    {
        std::cout << " *" << Carte->getTitlu() << " [ " << Carte->getISBN() << "]\n";
    }
};