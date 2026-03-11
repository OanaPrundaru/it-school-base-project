#include "Carte.h"
#include <iostream>

Carte::Carte(std::string Titlu, std::string Autor, std::string ISBN)
    : Titlu(Titlu), Autor(Autor), ISBN(ISBN), Este_împrumutată(false) {}

std::string Carte::getTitlu() const { return Titlu; }
std::string Carte::getAutor() const { return Autor; }
std::string Carte::getISBN() const { return ISBN; }
bool Carte::statusÎmprumut() const { return Este_împrumutată; }

void Carte::setÎmprumutată(bool status)
{
    Este_împrumutată = status;
}

void Carte::afișareDetalii() const
{
    std::cout << "Titlu: " << Titlu << " |Autor: " << Autor << " |ISBN: "
              << ISBN << " |Status: " << (Este_împrumutată ? " Împrumutată " : " Disponibilă ") << std::endl;
}