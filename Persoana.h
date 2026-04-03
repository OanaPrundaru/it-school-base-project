#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <vector>
#include <memory>
#include "Carte.h"

class Persoana
{
private:
    int ID;
    std::string Nume;
    std::vector<Carte *> Carti_imprumutate;

public:
    Persoana(int ID, std::string Nume);
    
    int getID() const;
    std::string getNume() const;

    void Adauga_carte(Carte *Carte);
    void returneaza_Carte(const std::string &ISBN);
    void afisare_Activitate() const;
};
#endif
