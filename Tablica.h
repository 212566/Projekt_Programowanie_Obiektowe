#pragma once
#ifndef TABLICA_H
#define TABLICA_H

#include "Publikacja.h"
#include <string>
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Tablica
{
protected:
	string nazwa;
	int id;
	map<int, Publikacja*> Publikacje;
	map<string, Wytwornia_Publikacji*> Lista_Wytworcow;


public:
	Tablica();
	Tablica(string _nazwa, int _id);
	~Tablica();
	void dodaj_publikacje(string p);
	void usun_publikacje(int id);
	void wyswietl_tablice() ;  // Wyswietla wszystkie publikacje danej tablicy
	void wyswietl_publikacje(int id); // Wyswietla pojedyncza publikacje z tablicy o podanym id
	void wyswietl_id();
};




#endif