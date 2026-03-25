#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte
{
private:
    std::string Titlu;
    std::string Autor;
    std::string ISBN;
    bool Este_imprumutata;

public:
    Carte(std::string Titlu, std::string Autor, std::string ISBN);

    std::string getTitlu() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool statusImprumut() const;

    void setImprumutata(bool status);
    void afisareDetalii() const;
};

#endif