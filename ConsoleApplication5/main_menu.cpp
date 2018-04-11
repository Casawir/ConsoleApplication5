#include "stdafx.h"
#include "main_menu.h"


void main_menu::Main_menu_zamowienia()
{
	menu_zamowienia menu_list = MENU_zamowienia;
	short unsigned int input = 0;
	vector<Zamowienie&> zamowienia;
	Zamowienie * nowe_zamowienie;

	wcout << L"Witaj w programie do obs�ugi zamowie�" << endl;

	while (menu_list != EXIT_)
	{
		cout << "Menu:" << endl;
		if (!Input(L"1.Dodaj zam�wienie\n2.Wy�wietl zam�wienia\n3.Przejd� do zam�wienia\n4.Wyj�cie\n", input))
			return;

		switch (input)
		{
		case DODAJ_ZAM:
		{
			zamowienia.push_back(dodaj_zamowienie());
			break;
		}
		case WYS_ZAM:
		{
			for (auto i : zamowienia) // c++ for loop
			{
				cout << i.nazwa << endl;
			}
			break;
		}
		case PRZEJDZ:
		{
			if (zamowienia.size() == 0)
				wcout << L"Brak zam�wie�";
			else
			{
				if (!Input(L"Podaj numer zam�wienia", input))
					return;

				if (input >= zamowienia.size())
					wcout << L"Brak zam�wienia o podanym numerze";

				Main_menu_pozycje(zamowienia[input-1]);
			}
			break;
		}

		case EXIT_:
			menu_list = EXIT_;
			break;
		}
	}
}



Zamowienie& main_menu::dodaj_zamowienie()
{
	short unsigned int input = 0;


	if (!Input(L"Podaj ilo�� pozycji nowego zam�wienia( 0 - warto�� domy�lna)", input))
		return *(new Zamowienie(input));


	if (input != 0)
		return *(new Zamowienie(input));
	else
		return *(new Zamowienie);


}


void main_menu::Main_menu_pozycje(Zamowienie& nowe_zamowienie)
{
	menu menu_list = MENU;
	short unsigned int input = 0;


	while (menu_list != EXIT)
	{
		cout << "Menu pozycji:" << endl;
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
			wstring temp = to_wstring(nowe_zamowienie.obliczWartosc());
			wcout << FormatCena(temp) << L" z�\n\n";
			break;
		}
		case WYSWIETL:
			wcout << nowe_zamowienie.toString();
			break;
		case EXIT:
			menu_list = EXIT;
			break;
		}
	}

}


void main_menu::dodaj_pozycje(Zamowienie &nowe_zamowienie)
{
	if (nowe_zamowienie.GetRozmiar() < nowe_zamowienie.GetMaxRozmiar())
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
		nowe_zamowienie.dodajPozycje(*nowa_pozycja);
	}
	else
	{
		wcout << L"Przekroczono zakres ilo�ci pozycji!\n\n";
	}
	//	}
}