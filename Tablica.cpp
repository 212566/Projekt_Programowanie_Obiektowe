#include "Tablica.h"


Tablica::Tablica(string _nazwa="DOMYŒLNA", int _id=0)
{
	nazwa = _nazwa;
	id = _id;
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("tresc", new Wytwornia_Publikacja_tresc));
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("zdjecie", new Wytwornia_Publikacja_zdjecie));
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("cytat", new Wytwornia_Publikacja_cytat));
}
Tablica::Tablica()
{
	nazwa = "DOMYŒLNA";
	id = 0;
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("tresc", new Wytwornia_Publikacja_tresc));
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("zdjecie", new Wytwornia_Publikacja_zdjecie));
	Lista_Wytworcow.insert(pair<string, Wytwornia_Publikacji*>("cytat", new Wytwornia_Publikacja_cytat));


}
///////////////////////////  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tablica::~Tablica()
{
	Lista_Wytworcow.clear();
	Publikacje.clear();

	/*
	for (map<const int, Publikacja*>::iterator it = Publikacje.begin(); it != Publikacje.end(); ++it)
	{
			delete it->second;
			Publikacje.erase(it);
	}

	for (map<string, Wytwornia_Publikacji*>::iterator it = Lista_Wytworcow.begin(); it != Lista_Wytworcow.end(); ++it)
	{
			delete it->second;
			Lista_Wytworcow.erase(it);
	}
	
	*/
	/*
	map<string, Wytwornia_Publikacji*>::iterator it;
	it = Lista_Wytworcow.find("tresc");
	Lista_Wytworcow.erase(it);

	it = Lista_Wytworcow.find("zdjecie");
	Lista_Wytworcow.erase(it);

	it = Lista_Wytworcow.find("cytat");
	Lista_Wytworcow.erase(it);

	*/


	/*
	for (vector<Publikacja*>::iterator it = Publikacje.begin(); it != Publikacje.end(); ++it)
		delete *it;
	Publikacje.clear();

	Lista_Wytworcow.clear();
	*/

	/* https://stackoverflow.com/questions/4600567/how-can-i-delete-elements-of-a-stdmap-with-an-iterator

	std::map<string, Wytwornia_Publikacji*>::iterator itr = Lista_Wytworcow.begin();
	while (itr != Lista_Wytworcow.end())
	{
		if (ShouldDelete(*it)) {
			itr = Lista_Wytworcow.erase(it);
		}
		else {
			++itr;
		}

	}
	*/
}



void Tablica::dodaj_publikacje(string p)
{
	map<string, Wytwornia_Publikacji*>::iterator iter = Lista_Wytworcow.find(p);

	Publikacja* pub = iter->second->stworz();

	const int id = pub->getID();
	Publikacje.insert(pair<const int, Publikacja*>(id, pub));

}


void Tablica::usun_publikacje(int id)
{
	map<const int, Publikacja*>::iterator it = Publikacje.find(id);

	if (it != Publikacje.end())
	Publikacje.erase(it);

	
}

void Tablica::wyswietl_tablice()
{
	for (map<const int, Publikacja*>::iterator it = Publikacje.begin(); it != Publikacje.end(); ++it)
	{
		it->second->wyswietl();

	}
}

void Tablica::wyswietl_publikacje(int id ) // chcialem aby ta metoda byla const ale iterator na to nie pozwalal
{
	map<const int, Publikacja*>::iterator it;
	it = Publikacje.find(id);
	if (it != Publikacje.end())
		it->second->wyswietl();


}

void Tablica::wyswietl_id()
{
	cout << "Tytul" << "     " << "ID" << endl << endl;

	for (map<const int, Publikacja*>::iterator it = Publikacje.begin(); it != Publikacje.end(); ++it)
	{
		cout << it->second->get_tekst_tytulu()<< "  " << it->second->getID() << endl;
	}

	
}
