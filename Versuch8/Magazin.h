/*
 * Magazin.h
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin: public Medium
{
public:
	/**
	 * @brief Konstruktor
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

	/**
	 * @brief Destruktor
	 */
	virtual ~Magazin();

	/**
	 * @brief Ausgabefunktion
	 */
	void ausgabe() const;

	/**
	 * @brief Ausleihen-Funktion
	 */
	bool ausleihen(Person person, Datum ausleihdatum);

private:
	Datum datumAusgabe;
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
