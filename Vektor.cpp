//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define PI 3.14159265359

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout<<std::fixed<<std::setprecision(4)<< "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Funktion, die die Länge des Vektors ausrechnet
 * @return Länge als double
 */
double Vektor::laenge() const
{
	double laenge = sqrt(((x*x)+(y*y)+(z*z)));
	return laenge;

}

/**
 * @brief Funktion, die die Differenz von zwei Vektoren ausrechnet
 * @return Der x-, y- und z-Wert des entstandenen Vektors
 *
 * @param input Zweiter Vektor, mit dem der erste zusammengerechnet werden soll
 */
Vektor Vektor::sub(const Vektor& input) const
{
	Vektor ergebnis = Vektor(x - input.x, y - input.y, z - input.z);

	return ergebnis;
}

/**
 * @brief Funktion, die das Skalarprodukt von zwei Vektoren ausrechnet
 * @return Skalarprodukt als double
 *
 * @param input Zweiter Vektor, mit dem der erste zusammengerechnet werden soll
 */
double Vektor::skalarProd(const Vektor& input) const
{
	double ergebnis = x*input.x + y*input.y + z*input.z;
	std::cout<<"Skalarprodukt von vector1 und vector2: "<<ergebnis<<std::endl<<std::endl;

	return ergebnis;
}

/**
 * @brief Funktion, die den Winkel zwischen zwei Vektoren ausrechnet
 * @return Winkel als double
 *
 * @param input Zweiter Vektor, der den ersten schneidet
 */
double Vektor::winkel(const Vektor& input) const
{
	double ergebnis = 180*acos((x*input.x + y*input.y + z*input.z)/(sqrt(x*x+y*y+z*z)*(sqrt(input.x*input.x+input.y*input.y+input.z*input.z))))/PI;
	return ergebnis;
}

/**
 * @brief Funktion, die den Vektor um rad-Wert um die z-Achse rotiert
 *
 * @param rad Winkel in Radian, um den der Vektor gedreht werden soll
 */
void Vektor::rotiereUmZ(const double rad)
{
	double tmpx = x*cos(rad) - y*sin(rad);
	double tmpy = x*sin(rad) + y*cos(rad);

	x = tmpx;
	y= tmpy;

}
