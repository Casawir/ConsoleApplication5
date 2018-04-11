#include "stdafx.h"
#include "main_menu.h"


void main_menu::Main_menu()
{
	menu menu_list = MENU;
	short unsigned int input = 0;
	Zamowienie * nowe_zamowienie;

	if(!Input(L"Witaj w programie do obs�ugi zamowie�, prosz� poda� ilo�� pozycji nowego zam�wienia( 0 - warto�� domy�lna) \n", input))
		return;

	if (input != 0)
		nowe_zamowienie = new Zamowienie(input);
	else
		nowe_zamowienie = new Zamowienie;



	while (menu_list != EXIT)
	{
		cout << "Menu:" << endl;
		if (!Input(L"1. Dodaj pozycje\n2. Wy�wietl Warto�� zam�wienia\n3. Wy�wietl wszystkie pozycje zam�wienia\n4.Wyj�cie\n", input))
			return;

		cout << endl;
		switch (input)
		{
		case DODAJ_POZ:
		{
			dodaj_pozycje(nowe_zamowienie);
			break;
		}
		case WYS_WARTOSC:
		{			
			wstring temp = to_wstring(nowe_zamowienie->obliczWartosc());
			wcout << FormatCena(temp) << L" z�\n\n";
			break;
		}
		case WYSWIETL:
			wcout << nowe_zamowienie->toString();
			break;
		case EXIT:
			menu_list = EXIT;
			break;
		}
	}

}

void main_menu::dodaj_pozycje(Zamowienie *nowe_zamowienie)
{
	if (nowe_zamowienie->GetRozmiar() < nowe_zamowienie->GetMaxRozmiar())
	{
		wstring nazwa;
		int sztuki = 0;
		double cena = 0;

		if (!Input(L"Podaj nazwe\n", nazwa))
			return;

		if (!Input(L"Podaj ilo�� sztuk\n", sztuki))
			return;

		if (!Input(L"Podaj cen�\n", cena))
			return;

		Pozycja * nowa_pozycja = new Pozycja(nazwa, sztuki, cena);
		nowe_zamowienie->dodajPozycje(*nowa_pozycja);
	}
	else
	{
		wcout << L"Przekroczono zakres ilo�ci pozycji!\n\n";
	}
	//	}
}