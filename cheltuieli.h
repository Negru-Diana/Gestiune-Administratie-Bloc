#pragma once

//Structura pentru cheltuiala
typedef struct
{
	int nrApartament;
	float suma;
	char tip[30];
}Cheltuiala;

/*
Creeaza o cheltuiala noua

	pre: nrApartament - int >0
		 suma - float >= 0.00
		 tip - cstring (nenul)
	post: returneaza o cheltuiala nou creata
*/
Cheltuiala createCheltuiala(int nrApartament, float suma, char* tip);

/*
Distruge cheltuiala creata

	pre: c - Cheltuiala
	post: elibereaza memoria ocupata de Cheltuiala
*/
void destroyCheltuiala(Cheltuiala* c);


/*
Valideaza Cheltuiala

	pre: c - Cheltuiala
	post: 0 - nrApartament, suma si tip valide
		  1 - nrApartament invalid
		  2 - suma invalida
		  3 - tip invalid
*/
int valideazaCheltuiala(Cheltuiala c);

/*
Functie pentru compararea tipului

	pre: c1, c2 - Cheltuiala
	post: returneaza <0 daca c1<c2
		  returneaza 0 daca c1=c2
		  returneaza >0 daca c1>c2
*/
int CompTip(Cheltuiala c1, Cheltuiala c2);


/*
Functie pentru compararea sumei

	pre: c1, c2 - Cheltuiala
	post: returneaza 1 daca c1>c2
		  returneaza 2 daca c1=c2
		  returneaza 0 daca c1<c2
*/
int CompSuma(Cheltuiala c1, Cheltuiala c2);