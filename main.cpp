//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
//alle Größen als Makros definiert
#define PI 3.14159265359
#define ERDRADIUS 6371000
#define PLATTFORM 555.7
#define MENSCH 1.7

int main()
{

	//erste Aufgabe ab hier

    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    vector1.laenge();
    vector2.laenge();
    std::cout<<std::endl;

    std::cout<<"Differenz von vector1 und vector2:"<<std::endl;
    Vektor vector3 = vector1.sub(vector2);
    vector3.ausgabe();

    vector1.skalarProd(vector2);

    vector1.winkel(vector2);

    std::cout<<"vector1 rotiert um die z-Achse ergibt:"<<std::endl;
    vector1.rotiereUmZ(PI);
    vector1.ausgabe();
    std::cout<<"vector2 rotiert um die z-Achse ergibt:"<<std::endl;
    vector2.rotiereUmZ(PI);
    vector2.ausgabe();


    //zweite Aufgabe ab hier
    double beta, sichtweite;
    int schritte = 0;
    Vektor erde(0, ERDRADIUS, 0);
    Vektor menschplattform(0,(PLATTFORM+MENSCH+ERDRADIUS), 0);
    Vektor sichtlinie = erde.sub(menschplattform); //Sichtlinie ergibt sich aus Differenz zwischen Erdradiusvektor und Vektor, wo der Mensch auf dem Plattform steht

    while(sichtlinie.winkel(erde) >= 90)
    {
    	erde.rotiereUmZ(0.00000001);
    	sichtlinie = erde.sub(menschplattform);
    	schritte++;
    }

    beta = menschplattform.winkel(erde);
    sichtweite = sichtlinie.laenge();

    std::cout<<"Sie können "<<sichtweite/1000<<" Km weit sehen."<<std::endl;
    std::cout<<"Sie sind "<<PLATTFORM + MENSCH<<" Meter hoch."<<std::endl;
    std::cout<<"Der Winkel beträgt "<<beta<<" Grad."<<std::endl;
    std::cout<<"Anzahl Schritte: "<<schritte<<std::endl;

    return 0;

}
