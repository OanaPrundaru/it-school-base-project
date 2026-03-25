#include "Biblioteca.h"
#include "Persoana.h"
#include "Carte.h"
#include <iostream>

void Biblioteca::Adaugă_carte(const std::string &Titlu, const std::string &Autor, const std::string &ISBN)
{
    Inventar_Carti.push_back(std::make_unique<Carte>(Titlu, Autor, ISBN));
    std::cout << "Cartea '" << Titlu << "' a fost adaugata in inventar.\n";
}

void Biblioteca::Adauga_persoana(const std::string &Nume, int ID)
{
    Lista_Membri.push_back(std::make_unique<Persoana>(Nume, ID));
    std::cout << "Persoana '" << Nume << "' (ID: " << ID << ") a fost inregistrata.\n";
}

Carte *Biblioteca::gaseste_Carte(const std::string &ISBN) const
{
    for (auto &Carte : Inventar_Carti)
    {
        if (Carte->getISBN() == ISBN)
            return Carte.get();
    }
    return nullptr;
}

Persoana *Biblioteca::gaseste_Persoana(int ID) const
{
    for (auto &Persoana : Lista_Membri)
    {
        if (Persoana->getID() == ID)
            return Persoana.get();
    }
    return nullptr;
}
bool Biblioteca::proceseaza_împrumut(int ID, const std::string &ISBN)
{
    Persoana *Persoana = gaseste_Persoana(ID);
    Carte *Carte = gaseste_Carte(ISBN);

    if (Persoana != nullptr && Carte != nullptr)
    {
        Carte->setImprumutata(true);
        Persoana->Adauga_carte(Carte);
        return true;
    }
    else
    {
        std::cout << "Eroare: Cartea este deja imprumutata de altcineva.\n";
    }
    return false;
}

void Biblioteca::afiseaza_toate_cartile() const
{
    std::cout << "\n--- Listă cărți--- \n";
    for (const auto &Carte : Inventar_Carti)
    {
        Carte->afisareDetalii();
    }
}

void Biblioteca::afisează_toti_membrii() const
{
    std::cout << "\n--- LISTA MEMBRI ---\n";
    for (const auto &Persoana : Lista_Membri)
    {
        Persoana->afisare_Activitate();
    }
}