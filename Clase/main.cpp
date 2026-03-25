#include <iostream>
#include "math_utils.h"

int main()
{
    Biblioteca b;
    b.incarcaCarti("carti.csv");
    b.incarcaMembri("membri.csv");
    b.afiseazaToateCartile();

    return 0;
}