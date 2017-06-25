#include <iostream>
#include <string>
#include "Tablica.h"
#include <algorithm>

int main()
{
	
	Tablica t("nazwa",123);


	t.dodaj_publikacje("tresc");
	cout << endl;	cout << endl;

	t.dodaj_publikacje("zdjecie");
	cout << endl;	cout << endl;

	t.dodaj_publikacje("cytat");
	cout << endl;	cout << endl;

	t.wyswietl_tablice();

	t.wyswietl_id();
	t.usun_publikacje(1000);

	t.wyswietl_tablice();

	cout << "Non scholae sed vitae discimus" << endl;
	


	
	
		return 0;

}

/*

char w = 0;
cout << "Podaj co chcesz stworzyc: " << endl;
cout << "1. Publikacja_tresc \"t\" " << endl;
cout << "2. Publikacja_zdjecie \"z\" " << endl;
cout << "3. Publikacja_cytat \"c\" " << endl;

*/

/*

cin.get(w);

switch (w)
{
case 't':
Wytwornia_Publikacji* tworca_t;
tworca_t = new Wytwornia_Publikacja_tresc;

Publikacja * publikacja_t;
publikacja_t = tworca_t->stworz();
t.Publikacje.push_back(publikacja_t);

delete tworca_t;

break;
case 'z':
Wytwornia_Publikacji* tworca_z;
tworca_z = new Wytwornia_Publikacja_zdjecie;

Publikacja * publikacja_z;
publikacja_z = tworca_z->stworz();
t.Publikacje.push_back(publikacja_z);

delete tworca_z;

break;

case 'c':
Wytwornia_Publikacji* tworca_c;
tworca_c = new Wytwornia_Publikacja_cytat;

Publikacja * publikacja_c;
publikacja_c = tworca_c->stworz();
t.Publikacje.push_back(publikacja_c);

delete tworca_c;

break;
default:
cout << "zly wybor";
break;
}
t.Publikacje[0]->wyswietl();


for (vector<Publikacja*>::iterator it = t.Publikacje.begin(); it != t.Publikacje.end(); ++it)
delete *it;


	//map<string, Wytwornia_Publikacji*> Lista_Wytworcow;

	//Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("tresc", new Wytwornia_Publikacja_tresc));
	//Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("zdjecie", new Wytwornia_Publikacja_zdjecie));
	//Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("cytat", new Wytwornia_Publikacja_paulo_coehlo));  

*/