#pragma once
#ifndef PUBLIKACJA_H
#define PUBLIKACJA_H
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Publikacja  // klasa abstrakcyjna 
{

protected:
	int id;
	string tekst_tytulu;
	unsigned int rozmiar_czcionki_tytulu;

public:
	static int id_num;
	static const int generate_id() ;

	Publikacja();
	virtual ~Publikacja() { }
	virtual void wyswietl() = 0;
	const int getID() const { return id; }  //  ulomne generowanie pseudoid
	string get_tekst_tytulu() const;
};

class Publikacja_tresc : public Publikacja   // szablon ktory wyglada nastepujaco: tytul top center i tresc ponizej
{
protected:
	string tekst_tresc;
	unsigned int rozmiar_czcionki_tresci;

public:
	Publikacja_tresc(int , string , unsigned int , string , unsigned int);
	void wyswietl() override;
};

class Publikacja_zdjecie : public Publikacja // szablon ktory wyglada nastepujaco: tytul top center, ponizej duze zdjecie oraz pod zdjeciem krotki opis
{
protected:
	string url;
	string tekst_opisu_zdjecia;
	unsigned int rozmiar_czcionki_opisu_zdjecia;


public:
	Publikacja_zdjecie(int , string , unsigned int , string , string , unsigned int );
	void wyswietl() override;

};

class Publikacja_cytat : public Publikacja   // szablon na wspaniale cytaty napisane piekna czcionka
{
protected:
	string tresc_rzewnego_cytatu;
	unsigned int rozmiar_czcionki_rzewnego_cytatu;

public:
	Publikacja_cytat(int , string , unsigned int , string , unsigned int );
	void wyswietl() override;


};

/////////////////////////// FACTORY METHOD /////////////////////////////////


class Wytwornia_Publikacji // klasa abstrakcyjna
{
	

public:
	virtual ~Wytwornia_Publikacji() { }
	virtual Publikacja* stworz() = 0;
};

class Wytwornia_Publikacja_tresc : public Wytwornia_Publikacji
{
public:
	~Wytwornia_Publikacja_tresc() { }
	Publikacja* stworz() override;
};

class Wytwornia_Publikacja_zdjecie : public Wytwornia_Publikacji
{
public:
	~Wytwornia_Publikacja_zdjecie() { }
	Publikacja* stworz() override;
};

class Wytwornia_Publikacja_cytat : public Wytwornia_Publikacji
{
public:
	~Wytwornia_Publikacja_cytat() {}
	Publikacja* stworz() override;
};





#endif