#ifndef PERSOANĂ_H
#define PERSOANĂ_H

#include <string>
#include <vector>
#include <memory>
#include "Carte.h"

class Persoană
{
private:
    std::string Nume;
    int ID;
    std::vector<Carte *> Cărți_împrumutate;

public:
    Persoană(std::string Nume, int ID);
    std::string getNume() const;
    int getID() const;

    void Adaugă_carte(Carte *Carte);
    void returnează_Carte(const std::string &ISBN);
    void afișare_Activitate() const;
};

#endif
