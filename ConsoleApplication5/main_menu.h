#pragma once
#include "zamowienia.h"


class main_menu 
{
	main_menu() {}; // prywatny konstruktor - uniemozliwienie stworzenia instacji tej klasy
	enum menu { DODAJ_POZ = 1, WYS_WARTOSC, WYSWIETL, EXIT, MENU };
	void static dodaj_pozycje(Zamowienie *nowe_zamowienie);


public:
	static void Main_menu();

};