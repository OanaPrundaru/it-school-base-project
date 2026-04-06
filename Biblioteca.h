#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Carte.h"
#include "Persoana.h"

class Biblioteca
{
private:
    std::vector<std::unique_ptr<Carte>> Inventar_Carti;
    std::vector<std::unique_ptr<Persoana>> Lista_Membri;

public:
    void Adauga_carte(const std::string &titlu, const std::string &Autor, const std::string &ISBN);
    void adauga_carte_manual();
    void sterge_carte_manual();

    void Adauga_persoana(int ID, const std::string &Nume);
    void adauga_persoana_manual();

    bool proceseaza_imprumut(int ID, const std::string &ISBN);
    bool proceseaza_returnare();

    void afiseaza_toate_cartile() const;
    void afiseaza_toti_membrii() const;

    Carte *gaseste_Carte(const std::string &ISBN) const;
    Persoana *gaseste_Persoana(int ID) const;

    void incarcaCarti(const std::string &numeFisier);
    void incarcaMembri(const std::string &numeFisier);

    void Imprumuta_carte(int ID, const std::string &ISBN);
    void returneaza_carte(const std::string &numeFisier);

    void salveaza_carti(const std::string &numeFisier);
    void salveaza_membri(const std::string &numeFisier);

    void afiseaza_carti_disponibile(const std::string &numeFisier);
    void salveaza_Imprumuturi_in_fisier(std::string Nume, std::string Titlu, std::string Data);
    void afiseaza_istoric_imprumuturi() const;
};

#endif