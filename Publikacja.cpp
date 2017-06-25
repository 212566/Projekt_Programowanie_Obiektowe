#include "Publikacja.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


int Publikacja::id_num = 1000; // do ulomnego generowania pseudoid


const int Publikacja::generate_id()
{
	const int i = id_num;
	id_num--;

	return i;
}

string Publikacja::get_tekst_tytulu() const
{
	return tekst_tytulu;
}

Publikacja::Publikacja()
{
	id = 0;
	tekst_tytulu = "DOMYSLNY";
	rozmiar_czcionki_tytulu = 10;
}



void Publikacja_tresc::wyswietl()
{
	
	cout << "################################################################################";
	cout << "ID publikacji:" << id;
	cout << endl;
	cout << endl;
	cout << "                                 " << tekst_tytulu << endl;
	cout << endl;
	cout << endl;

	cout << tekst_tresc << endl;

	cout << endl;
	cout << "################################################################################";
	cout << endl;
	

}

void Publikacja_zdjecie::wyswietl()
{
	
	cout << "################################################################################";
	cout << "ID publikacji:" << id;
	cout << endl;
	cout << endl;
	cout << "                                 " << tekst_tytulu << endl;
	cout << endl;
	cout << endl;

	cout << tekst_opisu_zdjecia << endl;

	cout << endl;
	cout << "################################################################################";
	cout << endl;

}

void Publikacja_cytat::wyswietl()
{
	
	cout << "################################################################################";
	cout << "ID publikacji:" << id;
	cout << endl;
	cout << endl;
	cout << "                                 " << tekst_tytulu << endl;
	cout << endl;
	cout << endl;

	cout << tresc_rzewnego_cytatu << endl;

	cout << endl;
	cout << "################################################################################";

	cout << endl;
	
}


Publikacja_tresc::Publikacja_tresc(int _id, string _tekst_tytulu, unsigned int _rozmiar_czcionki_tytulu, string _tekst_tresc, unsigned int _rozmiar_czcionki_tresci) 
	
{
	id = _id;
	tekst_tytulu = _tekst_tytulu;
	rozmiar_czcionki_tytulu = _rozmiar_czcionki_tytulu;
	tekst_tresc = _tekst_tresc;
	rozmiar_czcionki_tresci = _rozmiar_czcionki_tresci;
}





Publikacja_zdjecie::Publikacja_zdjecie(int _id, string _tekst_tytulu, unsigned int _rozmiar_czcionki_tytulu, string _url, string _tekst_opisu_zdjecia, unsigned int _rozmiar_czcionki_opisu_zdjecia) 
	
{
	id = _id;
	tekst_tytulu = _tekst_tytulu;
	rozmiar_czcionki_tytulu = _rozmiar_czcionki_tytulu;
	url = _url;
	tekst_opisu_zdjecia = _tekst_opisu_zdjecia;
	rozmiar_czcionki_opisu_zdjecia = _rozmiar_czcionki_opisu_zdjecia;
}




Publikacja_cytat::Publikacja_cytat(int _id, string _tekst_tytulu, unsigned int _rozmiar_czcionki_tytulu, string _tresc_rzewnego_cytatu, unsigned int _rozmiar_czcionki_rzewnego_cytatu)
	
{
	id = _id;
	tekst_tytulu = _tekst_tytulu;
	rozmiar_czcionki_tytulu = _rozmiar_czcionki_tytulu;
	tresc_rzewnego_cytatu = _tresc_rzewnego_cytatu;
	rozmiar_czcionki_rzewnego_cytatu = _rozmiar_czcionki_rzewnego_cytatu;

}





/////////////////// factory /////////////////////

Publikacja* Wytwornia_Publikacja_tresc::stworz()
{
	int id = Publikacja::generate_id();
	char tekst_tytulu [50];
	unsigned int rozmiar_czcionki_tytulu;
	char tekst_tresc [500];
	unsigned int rozmiar_czcionki_tresci;

	cout << "                 -- Wybrales publikacje z tytulem i trescia --";
	

	cout << endl;
	cout << "Podaj tytul: ";
	cin.get(tekst_tytulu, 50, '\n');
	cin.get();

	cout << endl;

	cout << "Podaj rozmiar czcionki tytulu: ";
	cin >> rozmiar_czcionki_tytulu;
	cin.get();

	cout << endl;
	cout << "Podaj tresc tekstu ( # konczy wpisywanie tresci ) : ";
	cin.get(tekst_tresc, 500, char(35));
	cin.get();

	cout << endl;
	cout << "Podaj rozmiar czcionki tekstu: ";
	cin >> rozmiar_czcionki_tresci;
	cin.get();
	cout << endl;


	return new Publikacja_tresc(id, tekst_tytulu, rozmiar_czcionki_tytulu, tekst_tresc, rozmiar_czcionki_tresci);
}


Publikacja* Wytwornia_Publikacja_zdjecie::stworz()
{
	int id = Publikacja::generate_id();
	char tekst_tytulu [50];
	unsigned int rozmiar_czcionki_tytulu;
	char tekst_opisu_zdjecia [100];
	unsigned int rozmiar_czcionki_opisu_zdjecia;
	char url [50];
	cout << "    -- Wybrales publikacje z tytulem, zdjeciem i krotkim opisem zdjecia --";


	cout << endl;
	cout << "Podaj tytul: ";
	cin.get(tekst_tytulu, 50, '\n');
	cin.get();

	cout << endl;

	cout << "Podaj rozmiar czcionki tytulu: ";
	cin >> rozmiar_czcionki_tytulu;
	cin.get();

	cout << endl;
	cout << "Podaj tresc tekstu ( # konczy wpisywanie tresci ) : ";
	cin.get(tekst_opisu_zdjecia, 100, char(35));
	cin.get();

	cout << endl;
	cout << "Podaj rozmiar czcionki tekstu: ";
	cin >> rozmiar_czcionki_opisu_zdjecia;
	cin.get();
	cout << endl;

	cout << "podaj url: ";
	cin.get(url, 50, '\n');
	cin.get();
	cout << endl;

	return new Publikacja_zdjecie(id, tekst_tytulu, rozmiar_czcionki_tytulu, url, tekst_opisu_zdjecia, rozmiar_czcionki_opisu_zdjecia);
}


Publikacja* Wytwornia_Publikacja_cytat::stworz()
{
	int id = Publikacja::generate_id();
	char tekst_tytulu [50];
	unsigned int rozmiar_czcionki_tytulu;
	char tresc_rzewnego_cytatu [100];
	unsigned int rozmiar_czcionki_rzewnego_cytatu;



	cout << "                   -- Wybrales publikacje z tytulem i cytatem --";


	cout << endl;
	cout << "Podaj tytul: ";
	cin.get(tekst_tytulu, 50, '\n');
	cin.get();

	cout << endl;

	cout << "Podaj rozmiar czcionki tytulu: ";
	cin >> rozmiar_czcionki_tytulu;
	cin.get();

	cout << endl;
	cout << "Podaj tresc cytatu ( # konczy wpisywanie tresci ) : ";
	cin.get(tresc_rzewnego_cytatu, 500, char(35));
	cin.get();

	cout << endl;
	cout << "Podaj rozmiar czcionki cytatu: ";
	cin >> rozmiar_czcionki_rzewnego_cytatu;
	cin.get();
	cout << endl;

	return new Publikacja_cytat(id, tekst_tytulu, rozmiar_czcionki_tytulu, tresc_rzewnego_cytatu, rozmiar_czcionki_rzewnego_cytatu);
}

