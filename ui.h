#pragma once
#include "MyList.h"
#include "cheltuieli.h" 

#include<stdio.h>

/*
Coordoneaza aplicatia

	pre: true
	post: coordoneaza aplicatia
*/
void run();


/*
Afisarea meniului

	pre: true
	post: se afiseaza meniul
*/
void meniu();


/*
Citeste optiune meniu

	pre: true
	post: returneaza optiunea aleasa din meniu
*/
int optiuneMeniu();

/*
Mesaj iesire program

	pre: true
	post: mesaj iesire program
*/
void mesajIesireProgram();


/*
Citeste numar Apartament

	pre: true
	post: returneaza numar apartament
*/
int readNrApartament();


/*
Citeste suma

	pre : true
	post : returneaza suma
*/
float readSuma();


/*
Citeste tip

	pre : true
	post : returneaza tip
*/
void readTip(char* buffer);


/*
Mesaj date cheltuiala invalide

	pre: true
	post: mesaj date cheltuiala invalide
*/
void mesajDateCheltuialaInvalide();


/*
Mesaj date cheltuiala adaugate

	pre: true
	post: mesaj date cheltuiala adaugate
*/
void mesajDateCheltuialaAdaugate();

/*
Afiseaza cheltuiala

	pre: nrApartament - int > 0
		 suma - float >= 0.00
		 tip - cstring nenul
	post: afiseaza cheltuiala
*/
void afiseazaCheltuiala(int nrApartament, float suma, char* tip);


/*
Mesaj nu exista cheltuieli

	pre: true
	post: mesaj nu exista cheltuieli
*/
void mesajCheltuieliInexistente();

/*
Mesaj cheltuiala existenta

	pre: true
	post: mesaj cheltuiala existenta
*/
void mesajExistaCheltuiala();

/*
Mesaj cheltuiala inexistenta

	pre: true
	post: mesaj cheltuiala inexistenta
*/
void mesajCheltuialaInexistenta();

/*
Mesaj cheltuiala modificata

	pre: true
	post: mesaj cheltuiala modifiicata
*/
void mesajCheltuialaModificata();

/*
Mesaj optiune meniu invalida

	pre: true
	post: mesaj optiune meniu invalida
*/
void mesajOptiuneMeniuInvalida();

/*
Mesaj cheltuiala stearsa

	pre: true
	post: mesaj cheltuiala stearsa
*/
void mesajCheltuialaStearsa();

/*
Citeste tip filtrare (optiune 4)

	pre: true
	post: returneaza tip filtrare
*/
int readTipFiltrare();

/*
1. Adauga cheltuiala pentru un apartament

	pre: list - lista cu elemente
	post: coordoneaza adaugarea cheltuielii pentru un apartament
*/
void optiune1(MyList* list);

/*
2. Modificarea unei cheltuieli existente (tipul, suma)

	pre: list - lista cu elemente
	post: coordoneaza modificarea unei cheltuieli existente (tipul, suma)
*/
void optiune2(MyList* list);

/*
3. Sterge cheltuiala

	pre: list - lista cu elemente
	post: coordoneaza stergerea unei cheltuieli
*/
void optiune3(MyList* list);


/*
4. Vizualizare lista de cheltuieli filtrat dupa o proprietate(suma, tipul, apartament)

	pre: list - lista cu elemente
	post: coordoneaza vizualizarea listei de cheltuieli filtrat dupa o proprietate (suma, tipul, apartament)
*/
void optiune4(MyList* list);


/*
5. Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)

	pre: list - lista cu elemente
	post: coordoneaza vizualizarea listei de cheltuieli ordonata dupa suma sau tip (crescator/descrescator)
*/
void optiune5(MyList* list);

/*
6. Vizualizare lista de cheltuieli

	pre: list - lista cu elemente
	post: coordoneaza afisarea listei de cheltuieli
*/
void optiune6(MyList* list);


/*
Verifica daca exista cheltuiala

	pre: list - lista cu elemente
		 c - Cheltuiala
	post: returneaza 1 daca cheltuiala exista deja
		  returneaza 0 in caz contrar
*/
int existaCheltuiala(MyList* list, Cheltuiala c);

/*
Citeste tip filtrare (optiune 4)

	pre: true
	post: returneaza tip sortare
*/
int readTipSortare();