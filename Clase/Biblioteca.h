#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

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
    void Adauga_persoana(const std::string &Nume, const int ID);

    bool proceseaza_imprumut(int ID, const std::string &ISBN);
    bool proceseaza_returnare(int ID, const std::string &ISBN);

    void afiseaza_toate_cartile() const;
    void afiseaza_toti_membrii() const;

    Carte *gaseste_Carte(const std::string &ISBN) const;
    Persoana *gaseste_Persoana(int ID) const;
};

#endif;