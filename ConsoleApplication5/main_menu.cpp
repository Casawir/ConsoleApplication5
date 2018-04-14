#include "stdafx.h"
#include "main_menu.h"


void main_menu::Main_menu_zamowienia()
{
	menu_zamowienia menu_list = MENU_zamowienia;
	unsigned int input = 0;

	wcout << L"Witaj w programie do obs�ugi zamowie�" << endl;

	while (menu_list != EXIT_)
	{
		cout << "Menu:" << endl;
		wcout << to_wstring(DODAJ_ZAM) + L". Dodaj zam�wienie" << endl;
		wcout << to_wstring(WYS_ZAM) + L". Wy�wietl zam�wienia" << endl;
		wcout << to_wstring(PRZEJDZ) + L". Przejd� do zam�wienia" << endl;
		wcout << to_wstring(USUN) + L". Usu� zam�wienie" << endl;
		wcout << to_wstring(EXIT_) + L". Wyjd�" << endl;


		if (!Input(L"", input))
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
			if (zamowienia.empty())
				wcout << L"Brak zam�wie�\n";
			else
			{
				for (auto *i : zamowienia)
				{
					cout << i->GetNumerZam() << endl;
				}
			}

			break;
		}
		case PRZEJDZ:
		{
			if (zamowienia.size() == 0)
				wcout << L"Brak zam�wie�\n";
			else
			{
				if (!Input(L"Podaj numer zam�wienia\n", input))
					return;

				for (auto *i : zamowienia)
				{
					if(i->GetNumerZam() == input)
					{
						Main_menu_pozycje(*(zamowienia[input - 100000]));
						break;
					}
					else if (i == zamowienia.back() && i->GetNumerZam() != input) // tutaj wazna kolejnosc !!!!
						wcout << L"Brak zam�wienia o podanym numerze\n";
				}
			}
			break;
		}
		case USUN:
		{
			if (zamowienia.size() == 0)
				wcout << L"Brak zam�wie�\n";
			else
			{
				if (!Input(L"Podaj numer zam�wienia\n", input))
					return;

				int temp = 0;
				for (auto *i : zamowienia)
				{
					if (i->GetNumerZam() == input)
					{
						delete i;
						zamowienia.erase(zamowienia.begin() + temp);
						break;
					}
					else if (i == zamowienia.back() && i->GetNumerZam() != input) // tutaj wazna kolejnosc !!!!
						wcout << L"Brak zam�wienia o podanym numerze\n";

					temp++;

				}
			}
			break;
		}
		case EXIT_:
			menu_list = EXIT_;
			break;
		}
	}
}



Zamowienie* main_menu::dodaj_zamowienie()
{
	short unsigned int input = 0;


	if (!Input(L"Podaj ilo�� pozycji nowego zam�wienia( 0 - warto�� domy�lna)\n", input))
		return new Zamowienie(input);

	int id = 0;

	zamowienia.empty() ? id = 100000 : id = zamowienia.back()->GetNumerZam() + 1;

	if (input != 0)
		return new Zamowienie(id, input);
	else
		return new Zamowienie(id);
}


void main_menu::Main_menu_pozycje(Zamowienie& nowe_zamowienie)
{
	menu menu_list = MENU;
	short unsigned int input = 0;


	while (menu_list != EXIT)
	{

		cout << "Menu pozycji:" << endl;
		wcout << to_wstring(DODAJ_POZ) + L". Dodaj pozycje" << endl;
		wcout << to_wstring(WYS_WARTOSC) + L". Wy�wietl Warto�� zam�wienia" << endl;
		wcout << to_wstring(WYSWIETL) + L". Wy�wietl wszystkie pozycje zam�wienia" << endl;
		wcout << to_wstring(EXIT) + L". Cofnij" << endl;


		if (!Input(L"", input))
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
}