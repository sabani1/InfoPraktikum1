//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
* @brief Hinzufuegen eines neues Listenelements am Anfang der Liste
*
*@param pData Zeiger auf ein Objekt der Klasse Student
*@return void
*/
void Liste::pushFront(Student pData)
{
	ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

	if(front == nullptr)  //Liste leer?
	{
		front = neuesElement;
		back = neuesElement;
	}
	else
	{
		front->setPrev(neuesElement);
		neuesElement->setPrev(nullptr);
		neuesElement->setNext(front);
		front = neuesElement;
	}
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
	neuesElement->setPrev(back);
	neuesElement->setNext(nullptr);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Entfernen eines Listenelements am Ende der Liste
 *
 * @return void
 */
void Liste::popBack()
{
	ListenElement* cursor = back;

	if (back == front)   // Liste enthält nur ein Listenelement
	{
		delete back;
		front = nullptr;
		back = nullptr;
	}
	else
	{
		back = back->getPrev();
		back->setNext(nullptr);
		delete cursor;

	}
}

/**
 * @brief Entfernen eines Listenelements
 * @param element Zeiger auf gegebene Listenelement, das gelöscht werden soll
 *
 * @return void
 */
void Liste::popElement(ListenElement* element)
{
	ListenElement* cursor = element;

	cursor->getNext()->setPrev(cursor->getPrev());
	cursor->getPrev()->setNext(cursor->getNext());
	delete cursor;
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurück
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataBack()
{
	return back->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letztes bis zum ersten Element
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor!= nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}

/**
 * @brief Funktion, die ein Listenelement sucht, die die gleiche Matrikelnummer hat wie die eingegebene
 * @param matrikel Matrikelnummer, die gesucht werden soll
 *
 * @return Zeiger auf dem Element, das gleiche Matrikelnummer hat, wenn diese gefunden wurde. Falls nicht, wird ein Nullpointer zurückgegeben
 */
ListenElement* Liste::sucheMatNr(unsigned int matrikel)
{
	ListenElement* cursor = front;

	while (cursor!= nullptr)
	{
		unsigned int matrikel2 = cursor->getData().getMatNr();
		if(matrikel == matrikel2)
		{
			return cursor;
		}

		cursor = cursor->getNext();
	}

	return nullptr;
}
