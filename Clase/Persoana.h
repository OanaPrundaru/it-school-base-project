#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <vector>
#include <memory>
#include "Carte.h"

class Persoana
{
private:
    std::string Nume;
    int ID;
    std::vector<Carte *> Carti_împrumutate;

public:
    Persoana(std::string Nume, int ID);
    std::string getNume() const;
    int getID() const;

    void Adauga_carte(Carte *Carte);
    void returneaza_Carte(const std::string &ISBN);
    void afisare_Activitate() const;
};

#endif
