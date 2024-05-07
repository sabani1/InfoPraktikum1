//============================================================================
// Name        : Versuch1Variablen2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

int main() {

	std::string sVorname;
	std:: string sNachname;

	std::cout <<"Geben Sie Ihren Vornamen ein: "<<std::endl;
	std::cin>> sVorname;
	std::cout <<"Geben Sie Ihren Nachnamen ein: "<<std::endl;
	std::cin>> sNachname;

	std::string sVornameName = sVorname + ' ' + sNachname;
	std::string sNameVorname = sNachname + ' ' + sVorname;

	std::cout <<sVornameName<<std::endl;
	std::cout <<sNameVorname<<std::endl;

	{
			int iFeld[2] = {1, 2};
			std::cout<<iFeld[0]<<iFeld[1]<<std::endl;
		}

		{
			char spielfeld[2][3] = {
					{'1', '2', '3'},
					{'4', '5', '6'}
			};

			std::cout<<spielfeld[0][0]<<" "<<spielfeld[0][1]<<" "<<spielfeld[0][2]<<std::endl;
			std::cout<<spielfeld[1][0]<<" "<<spielfeld[1][1]<<" "<<spielfeld[1][2]<<std::endl;
		}

		{
			const int iZweite = 1;
			std::cout<<iZweite<<std::endl;
		}
		const int iZweite = 1;
		std::cout<<iZweite<<std::endl;

		int iName1 = (int)sVorname[0];
		int iName2 = (int)sVorname[1];

		std::cout<<"Die ersten beiden Buchstaben des Vornamens als ASCII-Wert: "<< iName1 << " " << iName2 <<std::endl;

		int position1 = iName1 % 32;
		int position2 = iName2 % 32;

		std::cout<<"Die Position der ersten Buchstabe im Alphabet ist: "<< position1 <<std::endl;
		std::cout<<"Die Position der zweiten Buchstabe im Alphabet ist: " << position2 <<std::endl;

	return 0;
}
