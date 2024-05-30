/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl //fertig
                  << "(2): Datenelement vorne entfernen" << std::endl //fertig
                  << "(3): Datenbank ausgeben" << std::endl //fertig
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben"<<std::endl //fertig
				  << "(5): Datenelement löschen"<<std::endl //fertig
				  << "(6): Datenelement vorne hinzufügen"<<std::endl //fertig
				  << "(7): Datenelement hinten entfernen"<<std::endl //fertig
				  << "(8): Daten aus einer Datei einlesen"<<std::endl
				  << "(9): Daten in eine Datei sichern"<<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        studentenListe[0].ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                	std::vector<Student>::const_iterator it;

                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(it = studentenListe.begin(); it != studentenListe.end(); it++){
                    	std::cout << it->getName()<<", ";
                    	std::cout << it->getMatNr()<<", ";
                    	std::cout << it->getGeburtstag()<<", ";
                    	std::cout << it->getAdresse() << std::endl;
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            //Datenbank rückwärts ausgeben
            case '4':
            	if(!studentenListe.empty())
            	{
            		std::vector<Student>::const_reverse_iterator revIt;

            		std::cout<<"Inhalt der Liste in umgekehrter Reihenfolge: "<<std::endl;
            		for(revIt = studentenListe.rbegin(); revIt != studentenListe.rend(); revIt++){
            			std::cout << revIt->getName() << ", ";
						std::cout << revIt->getMatNr() << ", ";
						std::cout << revIt->getGeburtstag() << ", ";
						std::cout << revIt->getAdresse() << std::endl;
            		}

            	}
            	else
            	{
            		std::cout<<"Die Liste ist leer!\n\n";
            	}
            	break;

            //Element vom Datenbank löschen
            case '5':
            	if(!studentenListe.empty())
            	{
            		unsigned int matNr;
            		int gesucht;
            		std::cout<<"Bitte die Matrikelnummer vom Studenten eingeben, der gelöscht werden soll: "<<std::endl;
            		std::cin>>matNr;

            		for(unsigned int i=0; i<studentenListe.size(); i++){
            			if(studentenListe[i].getMatNr() == matNr)
            			{
            				gesucht = i;
            			}

            			else
            			{
            				gesucht = -1;
            			}
            		}

            		if(gesucht == -1)
            		{
            			std::cout<<"Der gesuchte Student ist nicht in der Liste."<<std::endl;
            		}
            		else
            		{
            			studentenListe.erase(studentenListe.begin()+gesucht);
            		}

            	}
            	else
            	{
            		std::cout<<"Die Liste ist leer!\n\n";
            	}
            	break;

            //Datenelement vorne einfügen
            case '6':
            {
				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
				getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

				std::cout << "Geburtsdatum: ";
				getline(std::cin, geburtstag);

				std::cout << "Adresse: ";
				getline(std::cin, adresse);

				std::cout << "Matrikelnummer: ";
				std::cin >> matNr;
				std::cin.ignore(10, '\n');

				student = Student(matNr, name, geburtstag, adresse);

				studentenListe.insert(studentenListe.begin(), student);
			}
            	break;

            //Datenelement hinten löschen
            case '7':
			{
				if(!studentenListe.empty())
				{
					std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
					studentenListe[studentenListe.size()-1].ausgabe();
					studentenListe.pop_back();
				}
				else
				{
					std::cout << "Die Liste ist leer!\n";
				}
           	}
			break;

			//Daten aus einer Datei lesen
            case '8':
            {
            	char abfrage;
            	std::cout<<"Möchten Sie die bereits vorhandenen Daten in der Liste löschen? (j/n)"<<std::endl;
            	std::cin>>abfrage;

            	if(abfrage == 'j')
            	{
            		std::cout<<"Die alten Daten in der Liste wurden gelöscht."<<std::endl;
					studentenListe.clear();
            	}

            	std::string dateiname;
            	std::cout<<"Bitte den Namen der Datei eingeben, die eingelesen werden soll: "<<std::endl;
            	std::cin>>dateiname;

            	std::cout<<dateiname<<" wird nun eingelesen."<<std::endl;
            	std::ifstream eingabe(dateiname); //D:\Uni\InfoPraktikum1\Versuch06\src/studenten.txt

            	if(!eingabe)
            	{
            		std::cout<<"Fehler beim Öffnen der Datei"<<std::endl;
            		break;
            	}

				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				eingabe >> matNr;

				while(!eingabe.eof())
				{
					eingabe.ignore(1, '\n');

					std::getline(eingabe, name);
					std::getline(eingabe, geburtstag);
					std::getline(eingabe, adresse);

					student = Student(matNr, name, geburtstag, adresse);
					studentenListe.push_back(student);
					eingabe >> matNr;
				}


            }
            break;

            //Daten in eine Datei sichern
            case '9':
            {
            	std::ofstream ausgabe;
				std::string dateiname = "";

				std::cout<<"In welcher Datei sollen die Daten gespeichert werden? (Achtung: Die Datei wird überschrieben.)"<<std::endl;
				std::cin>>dateiname; //D:\Uni\InfoPraktikum1\Versuch06\src/studenten.txt

				ausgabe.open(dateiname);

				for(unsigned int i=0; i<studentenListe.size(); i++)
				{
					ausgabe << studentenListe[i].getMatNr() << std::endl;
					ausgabe << studentenListe[i].getName() << std::endl;
					ausgabe << studentenListe[i].getGeburtstag() << std::endl;
					ausgabe << studentenListe[i].getAdresse() << std::endl;
				}

				ausgabe.close();

            }
            break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
