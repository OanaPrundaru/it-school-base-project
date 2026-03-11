#include "Bibliotecă.h"
#include "Persoană.h"
#include "Carte.h"
#include <iostream>

void Biblioteca::Adaugă_carte(const std::string &Titlu, const std::string &Autor, const std::string &ISBN)
{
    Inventar_Cărți.push_back(std::make_unique<Carte>(Titlu, Autor, ISBN));
    std::cout << "Cartea '" << Titlu << "' a fost adaugata in inventar.\n";
}

void Biblioteca::Adaugă_persoană(const std::string &Nume, int ID)
{
    Listă_Membri.push_back(std::make_unique<Persoană>(Nume, ID));
    std::cout << "Persoana '" << Nume << "' (ID: " << ID << ") a fost inregistrata.\n";
}

Carte *Biblioteca::găsește_Carte(const std::string &ISBN) const
{
    for (auto &Carte : Inventar_Cărți)
    {
        if (Carte->getISBN() == ISBN)
            return Carte.get();
    }
    return nullptr;
}

Persoană *Biblioteca::găsește_Persoană(int ID) const
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

    if (Persoană != nullptr && Carte != nullptr)
    {
        Carte->setÎmprumutată(true);
        Persoană->Adaugă_carte(Carte);
        return true;
    }
    else
    {
        std::cout << "Eroare: Cartea este deja imprumutata de altcineva.\n";
    }
    return false;
}

void Biblioteca::afișează_toate_cărțile() const
{
    std::cout << "\n--- Listă cărți--- \n";
    for (const auto &Carte : Inventar_Cărți)
    {
        Carte->afișareDetalii();
    }
}

void Biblioteca::afișează_toți_membrii() const
{
    std::cout << "\n--- LISTA MEMBRI ---\n";
    for (const auto &Persoană : Listă_Membri)
    {
        Persoană->afișare_Activitate();
    }
}