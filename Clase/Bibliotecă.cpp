#include "Bibliotecă.h"
#include <iostream>

void Biblioteca::Adaugă_carte(const std::string &Titlu, const std::string &Autor, const std::string &ISBN)
{
    Inventar_Cărți.push_back(std::make_unique<Carte>(Titlu, Autor, ISBN));
}

void Biblioteca::Adaugă_persoană(const std::string &Nume, int ID)
{
    Listă_Membri.push_back(std::make_unique<Persoană>(Nume, ID));
}

Carte *Biblioteca::găsește_Carte(const std::string &ISBN)
{
    for (auto &Carte : Inventar_Cărți)
    {
        if (Carte->getISBN() == ISBN)
            return Carte.get();
    }
    return nullptr;
}
Persoană *Biblioteca::găsește_Persoană(int ID)
{
    for (auto &Persoană : Listă_Membri)
    {
        if (Persoană->getID() == ID)
            return Persoană.get();
    }
    return nullptr;
}
bool Biblioteca::procesează_împrumut(int ID, const std::string &ISBN)
{
    Persoană *Persoană = găsește_Persoană(ID);
    Carte *Carte = găsește_Carte(ISBN);

    if (Persoană && Carte && !Carte->statusÎmprumut())
    {
        Carte->setÎmprumutată(true);
        Persoană->Adaugă_carte(Carte);
        return true;
    }
    return false;
}

void Biblioteca::afișează_toate_cărțile() const
{
    std::cout << "\n--- Inventar Bibliotecă! \n";
    for (const auto &Carte : Inventar_Cărți)
    {
        Carte->afișareDetalii();
    }
}