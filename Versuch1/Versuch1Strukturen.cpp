/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{

	struct Person{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

	Person nBenutzer;

	std::cout<<"Geben Sie Ihren Vornamen ein: "<<std::endl;
	std::cin>>nBenutzer.sVorname;
	std::cout<<"Geben Sie Ihren Nachnamen ein: "<<std::endl;
	std::cin>>nBenutzer.sNachname;
	std::cout<<"Geben Sie Ihr Geburtsjahr ein: "<<std::endl;
	std::cin>>nBenutzer.iGeburtsjahr;
	std::cout<<"Geben Sie Ihren Alter ein: "<<std::endl;
	std::cin>>nBenutzer.iAlter;

	std::cout<<"Benutzerinformationen:\n"<<"Vorname: "<<nBenutzer.sVorname<<std::endl;
	std::cout<<"Nachname: "<<nBenutzer.sNachname<<std::endl;
	std::cout<<"Geburtsjahr: "<<nBenutzer.iGeburtsjahr<<std::endl;
	std::cout<<"Alter: "<<nBenutzer.iAlter<<"\n"<<std::endl;

	Person nKopieEinzeln;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	std::cout<<"nKopieEinzeln:\n"<<"Vorname: "<<nKopieEinzeln.sVorname<<std::endl;
	std::cout<<"Nachname: "<<nKopieEinzeln.sNachname<<std::endl;
	std::cout<<"Geburtsjahr: "<<nKopieEinzeln.iGeburtsjahr<<std::endl;
	std::cout<<"Alter: "<<nKopieEinzeln.iAlter<<"\n"<<std::endl;

	Person nKopieGesamt;
	nKopieGesamt = nBenutzer;

	std::cout<<"nKopieGesamt:\n"<<"Vorname: "<<nKopieGesamt.sVorname<<std::endl;
	std::cout<<"Nachname: "<<nKopieGesamt.sNachname<<std::endl;
	std::cout<<"Geburtsjahr: "<<nKopieGesamt.iGeburtsjahr<<std::endl;
	std::cout<<"Alter: "<<nKopieGesamt.iAlter<<std::endl;

    return 0;

}
