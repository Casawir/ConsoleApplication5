#pragma once
#include "zamowienia.h"
#include <vector>


class main_menu 
{
	main_menu() {}; // prywatny konstruktor - uniemozliwienie stworzenia instacji tej klasy
	enum menu_zamowienia { DODAJ_ZAM = 1, WYS_ZAM, PRZEJDZ, EXIT_, MENU_zamowienia };
	enum menu { DODAJ_POZ = 1, WYS_WARTOSC, WYSWIETL, EXIT, MENU };
	static void dodaj_pozycje(Zamowienie &nowe_zamowienie);
	static void Main_menu_pozycje(Zamowienie&);
	static Zamowienie& dodaj_zamowienie();



public:
	static void Main_menu_zamowienia();

};