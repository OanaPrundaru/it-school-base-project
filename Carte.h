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
    std::string dataLimita = " ";

public:
    Carte(std::string Titlu, std::string Autor, std::string ISBN);

    std::string getTitlu() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool statusImprumut() const;
    
    
   
    void afisareDetalii() const;
    void setDataLimita(std::string data) {dataLimita = data;}
    std::string getDataLimita() const {return dataLimita;}
    void setImprumutata(bool status);
};

#endif