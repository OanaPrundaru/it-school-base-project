#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte
{
private:
    std::string Titlu;
    std::string Autor;
    std::string ISBN;
    bool Este_împrumutată;

public:
    Carte(std::string Titlu, std::string Autor, std::string ISBN);

    std::string getTitlu() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool statusÎmprumut() const;

    void setÎmprumutată(bool status);
    void afișareDetalii() const;
};

#endif