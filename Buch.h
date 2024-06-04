/*
 * Buch.h
 *
 *  Created on: 04.06.2024
 *      Author: SABINA
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium
{
public:
	/**
	 * @brief Konstruktor der Klasse Buch
	 *
	 * @param std::string initTitel Titel des Buchs
	 * @param std::string initAutor Autor des Buchs
	 */
	Buch(std::string initTitel, std::string initAutor);

	/**
	 * @brief virtueller Destruktor
	 */
	virtual ~Buch();

	/**
	 * @brief Ausgabefunktion
	 */
	void ausgabe() const;

private:
	std::string autor;
};

#endif /* BUCH_H_ */
