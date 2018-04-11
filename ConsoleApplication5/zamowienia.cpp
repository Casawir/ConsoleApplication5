#include "stdafx.h"
#include "zamowienia.h"
#include "main_menu.h"


wstring Pozycja::toString()
{
	wstring s_cena_all =  to_wstring(cena*ileSztuk).substr(0, 9); // substr - zakres ilości znaków podanych w zadaniu
	wstring s_cena = to_wstring(cena).substr(0, 9);

	FormatCena(s_cena_all); FormatCena(s_cena);  // usuniecie niepotrzebnych zer(i przecinkow) po skonwertowaniu liczb na string

	return nazwaTowaru.substr(0,19) + L"\t" + s_cena + L" zł\t" + to_wstring(ileSztuk).substr(0, 3) + L" szt.\t" + s_cena_all + L" zł\n";
}






void Zamowienie::dodajPozycje(Pozycja &p)
{
	if (ileDodanych >= maksRozmiar)
	{
		cout << "Przekroczono zakres ilosci pozycji!\n\n";
		return;
	}

		
	if (pozycje == nullptr) //jesli nie istnieje tablica z pozycjami to tworzymy nowa
	{
		pozycje = new Pozycja[maksRozmiar];
		//cout << "Pomyslnie stworzono tablice pozycji\n\n";
	}

	//cout << "Pomyslnie dodano pozycje\n\n";
	pozycje[ileDodanych] = p;
	ileDodanych += 1;

}

double Zamowienie::obliczWartosc()
{
	if (pozycje == nullptr) // jesli nie istnieje tablica to nie mozemy jej wyswietlic
	{
		cout << "Brakuje pozycji w zamowieniu\n\n";
		return 0;
	}
	else
	{
		double wartosc = 0;
		for (int i = 0; i < ileDodanych; i++)
		{
			wartosc += pozycje[i].obliczWartosc();
		}
		return wartosc;
	}


}

wstring Zamowienie::toString()
{
	wstring spis;
	for (int i = 0; i < ileDodanych; i++) 
	{
		spis = spis + to_wstring(i + 1) + L".\t" + pozycje[i].toString();
	}
	wstring temp = (to_wstring(obliczWartosc()));
	spis = spis + L"Wartość Zamówienia: " + FormatCena(temp) + L" zł\n\n";
	return spis;
}

Zamowienie::~Zamowienie()
{
	delete[] pozycje;
	pozycje = nullptr;
}


wstring& FormatCena(wstring &text) //funkcja formatujaca cene, poniewaz funkcja toString zwraca string a żeby go zwrócić musialem przekonsertowac cene i 
							   //ilosc na string, przez co ceny pokazywaly nie potrzebne zera po przecinku, nie potraflem znalesc innego rozwiazania
{
	text.erase(text.find_last_not_of('0') + 1);
	text.erase(text.find_last_not_of(',') + 1);

	return text;

}



int main()
{
	setlocale(LC_ALL, "polish"); // umożliwienie wyświetlania polskich znaków w konsoli
	main_menu::Main_menu_zamowienia();
    return 0;
}

