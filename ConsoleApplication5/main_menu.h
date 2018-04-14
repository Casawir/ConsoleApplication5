#pragma once
#include "zamowienia.h"
#include <vector>


class main_menu 
{
	main_menu() { Main_menu_zamowienia(); }; // prywatny konstruktor - uniemozliwienie stworzenia instacji tej klasy


	enum menu_zamowienia { DODAJ_ZAM = 1, WYS_ZAM, PRZEJDZ, USUN, EXIT_, MENU_zamowienia };
	enum menu { DODAJ_POZ = 1, WYS_WARTOSC, WYSWIETL, EXIT, MENU };
	vector<Zamowienie*> zamowienia;

	void Main_menu_zamowienia();
	void dodaj_pozycje(Zamowienie &nowe_zamowienie);
	void Main_menu_pozycje(Zamowienie&);
	Zamowienie* dodaj_zamowienie();



public:
	static main_menu& Getmain_menu() { main_menu Main_menu; return Main_menu; };

};