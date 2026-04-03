#include "Biblioteca.h"
#include "Persoana.h"
#include "Carte.h"
#include <iostream>
#include <ctime>
#include <iomanip>


std::string calculeazaDataLimita(int zileDeImprumut = 14){
    std::time_t t = std::time(nullptr);
    t +=zileDeImprumut * 24 * 60 * 60;
    std::tm* acum = std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(acum, "%d-%m-%Y");
    return ss.str();
};

void Biblioteca::Adauga_carte(const std::string &Titlu, const std::string &Autor, const std::string &ISBN)
{
    Inventar_Carti.push_back(std::make_unique<Carte>(Titlu, Autor, ISBN));
    std::cout << "Cartea '" << Titlu << "' a fost adaugata in inventar.\n";
}

void Biblioteca::adauga_carte_manual(){
    std::string Titlu, Autor, ISBN;
    std::cout << "\n Adaugare carte noua. \n";
    std::cout << "Introduceti ISBN: ";
    std::cin >> ISBN;
    std::cin.ignore();

    std::cout << "Introduceti titlu: ";
    std::getline(std::cin, Titlu);

    std::cout <<"Introduceti autor: ";
    std::getline(std::cin, Autor);

    Inventar_Carti.push_back(std::make_unique <Carte> (Titlu, Autor, ISBN));
    std::cout << "Cartea a fost adaugata cu succes! \n";
}
void Biblioteca::sterge_carte_manual(){
    std::string ISBN_cautat;
    std::cout << "Stergere carte!\n";
    std::cout << "Introduceti ISBN-ul cartii pe care doriti sa o stergeti: ";
    std::cin >> ISBN_cautat;
    bool gasit = false;

    for(auto it = Inventar_Carti.begin(); it != Inventar_Carti.end(); ++it){
        if((*it)->getISBN() == ISBN_cautat){
            Inventar_Carti.erase(it);
            std::cout << " Cartea cu ISBN: " << ISBN_cautat <<" a fost stearsa!\n";
            gasit = true;
            break;
        }
    }
}

void Biblioteca::Adauga_persoana(int ID, const std::string &Nume)
{
    Lista_Membri.push_back(std::make_unique<Persoana>(ID, Nume));
    std::cout << "Persoana '" << Nume << "' (ID: " << ID << ") a fost inregistrata.\n";
}
void Biblioteca::adauga_persoana_manual(){
    std::string Nume;
    int maxID = 0;
    for( const auto& p:Lista_Membri){
        if(p->getID() > maxID);
            maxID = p->getID();
        }
       
    int ID_nou = maxID + 1;

    std::cout << "Inregistrare membru nou! \n";
    std::cout << "ID: " << ID_nou << std::endl;
    std::cout << "Introduceti numele si prenumele: ";
    std::cin.ignore();
    std::getline(std::cin, Nume);

    Lista_Membri.push_back(std::make_unique<Persoana>(ID_nou, Nume));
    std::cout << "Membrul: " << Nume << " a fost inregistrat cu succes!\n";    
}


Carte *Biblioteca::gaseste_Carte(const std::string &ISBN) const
{
    for (auto &Carte : Inventar_Carti)
    {
        if (Carte->getISBN() == ISBN)
            return Carte.get();
    }
    return nullptr;
}

Persoana *Biblioteca::gaseste_Persoana(int ID) const
{
    for (auto &Persoana : Lista_Membri)
    {
        if (Persoana->getID() == ID)
            return Persoana.get();
    }
    return nullptr;
}
bool Biblioteca::proceseaza_imprumut(int ID, const std::string &ISBN)
{
    Persoana *Persoana = gaseste_Persoana(ID);
    Carte *Carte = gaseste_Carte(ISBN);

    if (Persoana != nullptr && Carte != nullptr)
    {
        Carte->setImprumutata(true);
        Persoana->Adauga_carte(Carte);
        return true;
    }
    else
    {
        std::cout << "Eroare: Cartea este deja imprumutata de altcineva.\n";
    }
    return false;
}

void Biblioteca::afiseaza_toate_cartile() const
{
    std::cout << "\n--- Listă cărți--- \n";
    for (const auto& c : Inventar_Carti)
    {
        std::cout << "ISBN: " << c->getISBN() << "|Titlu: " << c->getTitlu()
        <<"|Autor: "<< c->getAutor() << "|Status: " << (c->statusImprumut()? 
        "Imprumutata" : "Disponibila") << std::endl;
        c->afisareDetalii();
    }
}

void Biblioteca::afiseaza_toti_membrii() const
{
    std::cout << "\n--- LISTA MEMBRI ---\n";
    for (const auto &p : Lista_Membri)
    {   
        std::cout << "ID: " <<p->getID() << "|Nume: "<< p->getNume() << std::endl;
        p->afisare_Activitate();
    }
}

void Biblioteca::incarcaCarti(const std::string &numeFisier)
{
    std::ifstream file(numeFisier);
    if (!file.is_open())
    {
        std::cout << "Eroare: Nu s-a putut deschide fisierul " << numeFisier << std::endl;
        return;
    }

    std::string linie;
    while (std::getline(file, linie))
    {
        std::stringstream ss(linie);
        std::string ISBN, titlu, autor, status;

        if (std::getline(ss, ISBN, ',') &&
            std::getline(ss, titlu, ',') &&
            std::getline(ss, autor,',') &&
            std::getline(ss, status))
        {
        
            try
            {
               Inventar_Carti.push_back(std::make_unique<Carte>(titlu, autor, ISBN));

                if (status == "1")
                {
                    Inventar_Carti.back()->setImprumutata(true);
                }
            }
            catch (...)
            {
                continue;
            }
        }
    }
    file.close();
    std::cout << "Carti incarcate cu succes!" << std::endl;
}

void Biblioteca::incarcaMembri(const std::string &numeFisier)
{
    std::ifstream file(numeFisier);
    if (!file.is_open())
    {
        std::cout << "Eroare: Nu s-a putut deschide fisierul " << numeFisier << std::endl;
        return;
    }

    std::string linie;
    while (std::getline(file, linie))
    {
        std::stringstream ss(linie);
        std::string idStr, Nume;
        
        if (std::getline(ss, idStr, ',') && std::getline(ss, Nume))
            {
                try
                {
                    int ID = std::stoi(idStr);
                    this->Adauga_persoana(ID, Nume);
                }
                catch (...)
                {
                    continue;
                }
            }
        }
    file.close();
    std::cout << "Membri incarcati: " << Lista_Membri.size() << std::endl;

}

void Biblioteca::Imprumuta_carte(int idPersoana, const std::string &isbnCarte)
{
    Persoana *persoanaGasita = nullptr;
    Carte *carteGasita = nullptr;

    for (auto &p : Lista_Membri)
    {
        if (p->getID() == idPersoana)
        {
            persoanaGasita = p.get();
            break;
        }
    }

    for (auto &c : Inventar_Carti){
        if (c->getISBN() == isbnCarte)
        {
            carteGasita = c.get();
            break;
        }
    }

    if (persoanaGasita && carteGasita)
    {
        if (!carteGasita->statusImprumut())
        {
            carteGasita->setImprumutata(true);
            persoanaGasita->Adauga_carte(carteGasita);
            std::string dataScadenta = calculeazaDataLimita(14);
            carteGasita->setDataLimita(dataScadenta);
            std::cout << "SUCCES!" << std::endl;
            std::cout << "Membrul: " << idPersoana << " a imprumutat cartea: " << carteGasita->getTitlu() << std::endl;
            std::cout << "Cartea trebuie returnata pana la data de: \n" << carteGasita->getDataLimita() << std::endl;
        }
        else
        {
            std::cout << " Cartea este deja imprumutata! " << std::endl;
        }
    }
    else
    {
        std::cout << "ID Persoana sau ISBN incorect. " << std::endl;
    }
}

void Biblioteca::returneaza_carte(const std::string &numeFisier)
{
    std::string isbn_carte;
    std::cout << "Introduceti ISBN-UL cartii de returnat : \n";
    std::cin >> isbn_carte;

    bool gasit = false;
    for (auto &c : Inventar_Carti)
    {
        if (c->getISBN() == isbn_carte)
        {
           gasit = true;
            c->setImprumutata(false);
            std::cout << "Cartea a fost returnata! " << std::endl;
            break;
        }
    }
        if(gasit){
            salveaza_carti(numeFisier);
    }
}

void Biblioteca::salveaza_carti(const std::string &numeFisier)
{
    std::ofstream f(numeFisier);
    if (f.is_open())
    {
        for (auto &c : Inventar_Carti)
        {
            f << c->getISBN() << "," << c->getTitlu() << "," << c->getAutor() << "," << (c->statusImprumut() ? "1" : "0") << "\n";
        }
        f.close();
    }
}

void Biblioteca::salveaza_membri(const std::string &numeFisier)
{
    std::ofstream f(numeFisier);
    if (f.is_open())
    {
        for (auto &p : Lista_Membri)
        {
            f << p->getID() << "," << p->getNume() << "\n";
        }
        f.close();
    }
}

void Biblioteca::afiseaza_carti_disponibile(const std::string &numeFisier){
    std::cout << "\n Cartile disponibile pentru imprumut sunt: \n";
    bool gasit = false;

    for(auto& c:Inventar_Carti){
        if(c->statusImprumut() == false){
            std::cout << "ISBN: " << c->getISBN() << "| Titlu: " << c->getTitlu() << " |Autor: " 
            << c->getAutor() << " |Data limita: " << c->getDataLimita() << std::endl;
            gasit = true;
        }
    }
    if(!gasit){
        std::cout << " Ne pare rau, nu avem carti disponibile!" << std::endl;
    }
}
