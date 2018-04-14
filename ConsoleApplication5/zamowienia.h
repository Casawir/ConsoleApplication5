#pragma once
#include <iostream>
#include <string>
using namespace std;



wstring & FormatCena(wstring &text);
template <typename Val> bool Input(wstring const& text, Val& input)  //sprawdza popranosc wprowadzonych danych
{
	while (true)
	{
		if(!text.empty())
			wcout << text;
		if (wcin >> input) return true;
		wcout << L"Nie podano właściwego znaku, wychodzenie z programu ...\n";
		//wcin.clear(); // blad kompilacji przy cin.clear i setlocale
		return false;
	}
}

// zamieniłem string na wstring które obłsuguje polskie znaki
class Pozycja
{
	wstring nazwaTowaru;
	int ileSztuk;
	double cena;

public:
	Pozycja() {};
	Pozycja(wstring nazwaTowaru_, int ileSztuk_, double cena_) : nazwaTowaru(nazwaTowaru_), ileSztuk(ileSztuk_), cena(cena_) {};
	double obliczWartosc() { return ileSztuk * cena; }; // inline, nieskomplikowane dzialanie weldug mnie optymalmniej
	wstring toString();
};

class Zamowienie
{
	Pozycja * pozycje = nullptr;
	int ileDodanych = 0;
	int maksRozmiar;
	int numer_zamowienia;

	public:
		Zamowienie(int numer) : numer_zamowienia(numer), maksRozmiar(10) {};
		Zamowienie(int numer, int maks_rozmiar) : numer_zamowienia(numer), maksRozmiar(maks_rozmiar) {};
		int GetMaxRozmiar() { return maksRozmiar; };  // Getter'y dałem inline, według mnie optymalniej
		int GetRozmiar() { return ileDodanych; };
		int GetNumerZam() { return numer_zamowienia; };
		void dodajPozycje(Pozycja &p);
		double obliczWartosc();
		wstring toString();
		~Zamowienie();

};
