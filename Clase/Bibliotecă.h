#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <memory>
#include <string>
#include "Carte.h"
#include "Persoană.h"

class Biblioteca
{
private:
    std::vector<std::unique_ptr<Carte>> Inventar_Cărți;
    std::vector<std::unique_ptr<Persoană>> Listă_Membri;

public:
    void Adaugă_carte(const std::string &titlu, const std::string &Autor, const std::string &ISBN);
    void Adaugă_persoană(const std::string &Nume, const int ID);

    bool procesează_împrumut(int ID, const std::string &ISBN);
    bool procesează_returnare(int ID, const std::string &ISBN);

    void afișează_toate_cărțile() const;
    void afișează_toți_membrii() const;

    Carte *găsește_Carte() const;
    Persoană *găsește_Persoană() const;
};

#endif;