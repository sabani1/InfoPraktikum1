/*
 * Buch.cpp
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#include "Buch.h"

//Konstruktor
Buch::Buch(std::string initTitel, std::string initAutor)
: Medium(initTitel)
, autor(initAutor)
{
}

Buch::~Buch()
{

}

void Buch::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"Autor: "<<autor<<std::endl;
}

