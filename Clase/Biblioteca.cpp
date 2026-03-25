#include "Biblioteca.h"
#include "Persoana.h"
#include "Carte.h"
#include <iostream>

void Biblioteca::Adauga_carte(const std::string &Titlu, const std::string &Autor, const std::string &ISBN)
{
    Inventar_Carti.push_back(std::make_unique<Carte>(Titlu, Autor, ISBN));
    std::cout << "Cartea '" << Titlu << "' a fost adaugata in inventar.\n";
}

void Biblioteca::Adauga_persoana(int ID, const std::string &Nume)
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
bool Biblioteca::proceseaza_imprumut(int ID, const std::string &ISBN)
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

void Biblioteca::afiseaza_toti_membrii() const
{
    std::cout << "\n--- LISTA MEMBRI ---\n";
    for (const auto &Persoana : Lista_Membri)
    {
        Persoana->afisare_Activitate();
    }
}

void Biblioteca::incarcaCarti(const std::string &numeFisier)
{
    std::ifstream file(numeFisier);
    if (!file.is_open())
    {
        std::cout << "Eroare: Nu s-a putut deschide fisierul " << numeFisier << std::endl;
        return;
    }

    std::string linie;
    while (std::getline(file, linie))
    {
        std::stringstream ss(linie);
        std::string ISBN, titlu, autor;

        if (std::getline(ss, ISBN, ',') &&
            std::getline(ss, titlu, ',') &&
            std::getline(ss, autor))
        {

            try
            {
                this->Adauga_carte(std::string(ISBN), titlu, autor);
            }
            catch (...)
            {
                continue;
            }
        }
    }
    file.close();
    std::cout << "Carti incarcate cu succes!" << std::endl;
}

void Biblioteca::incarcaMembri(const std::string &numeFisier)
{
    std::ifstream file(numeFisier);
    if (!file.is_open())
    {
        std::cout << "Eroare: Nu s-a putut deschide fisierul " << numeFisier << std::endl;
        return;
    }

    std::string linie;
    while (std::getline(file, linie))
    {
        std::stringstream ss(linie);
        std::string idStr;
        std::string Nume;

        if (std::getline(ss, idStr, ','))
        {
            if (std::getline(ss, Nume))
            {
                try
                {
                    int ID = std::stoi(idStr);
                    this->Adauga_persoana(ID, Nume);
                }
                catch (...)
                {
                    continue;
                }
            }
        }
    }
    file.close();
    std::cout << "Membri incarcati: " << Lista_Membri.size() << std::endl;
}
