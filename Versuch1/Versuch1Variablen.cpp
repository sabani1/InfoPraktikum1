//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code


    std::cout << "Geben Sie bitte zwei Zahlen ein:"<<std::endl;
    std::cin >> iErste;
    std::cin >> iZweite;

    double dSummeCast = (double) iErste + iZweite;
    double dQuotientCast = (double) iErste / iZweite;

    std::cout << "Die Summe der Zahlen lautet: "<< dSummeCast <<std::endl;
    std::cout << "Der Quotient der Zahlen lautet: " << dQuotientCast <<std::endl;

    return 0;

}
