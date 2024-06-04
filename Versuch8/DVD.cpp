/*
 * DVD.cpp
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel)
, altersfreigabe(initAltersfreigabe)
, genre(initGenre)
{
}

DVD::~DVD()
{
}

void DVD::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"FSK: ab "<<altersfreigabe<<" Jahre"<<std::endl;
	std::cout<<"Genre: "<<genre<<std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	std::cout<<person.getGeburtsdatum()<<std::endl;
	if(ausleihdatum - person.getGeburtsdatum() >= altersfreigabe*12)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true; //Ausleihen erfolgreich
	}
	else
	{
		std::cout<<"Die Person ist zu jung, um die DVD auszuleihen."<<std::endl;
		return false; //Ausleihen nicht erfolgreich
	}
}
