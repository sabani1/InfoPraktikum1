/*
 * DVD.h
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium {
public:
	/**
	 * @brief Konstruktor
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	/**
	 * @brief Destruktor
	 */
	virtual ~DVD();

	/**
	 * @brief Ausgabefunktion
	 */
	void ausgabe() const;

	/**
	 * @brief Ausleihen-Funktion
	 */
	bool ausleihen(Person person, Datum ausleihdatum);

private:
	int altersfreigabe;
	std::string genre;
};

#endif /* DVD_H_ */
