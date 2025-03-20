#pragma once

#include "MyList.h"
#include "cheltuieli.h"
#include "service.h"
typedef Cheltuiala ElemType;


typedef int(*sorteaza)(ElemType c1, ElemType c2);


/*
Sortare cheltuieli crescator/descrescator dupa suma, iar daca sumele sunt egale, le pune in ordine lexicografica dupa tip

	pre: lista - MyList (lista cu elemente)
		 crescator: 0 - sortare descrescatoare, 1 - sortare crescatoare
		 cmp1 - functia de comparare CompSuma
		 cmp2 - functia de comparare CompTip
	post: returneaza lista sortata
*/
MyList* sortareCheltuieli(MyList* lista, int crescator, sorteaza cmp1, sorteaza cmp2);


/*
Verifica daca exista cheltuiala

	pre: list - lista cu elemente
		 c - Cheltuiala
	post: returneaza index cheltuiala daca cheltuiala exista deja
		  returneaza -1 in caz contrar
*/
int existaCheltuiala(MyList* list, Cheltuiala c);

/*
Adauga cheltuiala la lista

	pre: list - lista cu elemente
		 nrApartament - int > 0
		 suma - float >= 0.00
		 tip - cstring nenul
	post: returneaza 1 daca cheltuiala este invalida
		  returneaza 2 daca cheltuiala este existenta
		  returneaza 0 daca cheltuiala este valida, unica si a putut fi adaugata in lista
*/
int addCheltuiala(MyList* list, int nrApartament, float suma, char* tip);


/*
Filtrarea listei de elemente dupa numarul apartamentului

	pre: list - lista cu elemente
		 nrApartament - int >0
	post: retuneaza lista de elemente filtrara dupa numarul apartamentului
*/
MyList* filtrareDupaNumarApartament(MyList* list, int nrApartament);

/*
Filtrarea listei de elemente dupa tip

	pre: list - lista cu elemente
		 tip - cstring nenul
	post: retuneaza lista de elemente filtrara dupa tip
*/
MyList* filtrareDupaTip(MyList* list, char* tip);


/*
Filtrarea listei de elemente dupa un interval de sume

	pre: list - lista cu elemente
		 sumaMinim - float >= 0.00
		 sumaMaxim - float >= 0.00
	post: retuneaza lista de elemente filtrara dupa intervalul de sume
*/
MyList* filtrareDupaSuma(MyList* list, float sumaMinim, float sumaMaxim);


/*
Sortarea listei de elemente dupa suma, crescator

	pre: list - lista cu elemente
	post: retuneaza lista de elemente sortata dupa suma, crescator
*/
MyList* SortareSumaCrescator(MyList* list);


/*
Sortarea listei de elemente dupa suma, descrescator

	pre: list - lista cu elemente
	post: retuneaza lista de elemente sortata dupa suma, descrescator
*/
MyList* SortareSumaDesrescator(MyList* list);


/*
Sortarea listei de elemente dupa tip, crescator

	pre: list - lista cu elemente
	post: retuneaza lista de elemente sortata dupa tip, crescator
*/
MyList* SortareTipCrescator(MyList* list); 


/*
Sortarea listei de elemente dupa tip, descrescator

	pre: list - lista cu elemente
	post: retuneaza lista de elemente sortata dupa tip, descrescator
*/
MyList* SortareTipDescrescator(MyList* list);

