/*
 * Magazin.cpp
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium(initTitel)
, datumAusgabe(initDatumAusgabe)
, sparte(initSparte)
{
}

Magazin::~Magazin() {

}

void Magazin::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"Ausgabe: "<<datumAusgabe<<std::endl;
	std::cout<<"Sparte: "<<sparte<<std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	if((ausleihdatum - datumAusgabe) > 1) //datumAusgabe muss mehr als 1 Monat vor dem Ausleihen sein
	{
		Medium::ausleihen(person, ausleihdatum);
		return true; //Ausleihen erfolgreich
	}
	else
	{
		std::cout<<"Dieses Magazin ist die neueste Ausgabe und darf erst nächsten Monat ausgeliehen werden."<<std::endl;
		return false; //Ausleihen nicht erfolgreich
	}
}
