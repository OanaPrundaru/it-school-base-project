#include "Carte.h"
#include <iostream>

Carte::Carte(std::string Titlu, std::string Autor, std::string ISBN)
    : Titlu(Titlu), Autor(Autor), ISBN(ISBN), Este_imprumutata(false) {}

std::string Carte::getTitlu() const { return Titlu; }
std::string Carte::getAutor() const { return Autor; }
std::string Carte::getISBN() const { return ISBN; }
bool Carte::statusImprumut() const { return Este_imprumutata; }

void Carte::setImprumutata(bool status)
{
    Este_imprumutata = status;
        if(!status) {
            dataLimita = " ";
        }
}

void Carte::afisareDetalii() const
{
    std::cout << " |ISBN: "<< ISBN<< " |Titlu: " << Titlu << " |Autor: " << Autor  << " |Status: " 
    << (Este_imprumutata ? " Împrumutată " : " Disponibilă ") << std::endl;
    if(Este_imprumutata){
        std::cout << "De catre: " << numePersoana << "|Data scadenta: " << dataLimita << std::endl;
    }
}