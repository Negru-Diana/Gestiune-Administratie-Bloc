#pragma once
#include "cheltuieli.h"

typedef Cheltuiala ElemType;

// Structura MyList cu vector dinamic
typedef struct {
	ElemType* elem;
	int lungime;
	int capacitate;
} MyList;


/*
Creeaza o lista vida/goala

	pre: true
	post: creeaza o lista vida/goala
*/
MyList* createEmpty();


/*
Distruge lista

	pre: l - lista cu elemente
	post: distruge lista
*/
void destroy(MyList* l);


/*
Ia un element din lista

	pre: l - lista cu elemente
		 pozitie - pozitia elementului (trebuie sa fie valida)
	post: returneaza elementul de pe pozitia data din lista (l)
*/
ElemType get(MyList* l, int pozitie);


/*
Numarul de elemente din lista

	pre: l - lista cu elemente
	post: returneaza numarul de elemente din lista
*/
int size(MyList* l);


/*
Adauga o cheltuiala in lista

	pre: l - lista cu elemente
		 c - Cheltuiala
	post: adauga cheltuiala (c) la sfarsitul listei
*/
void add(MyList* l, ElemType c);


/*
Face o copie a listei

	pre: l - lista cu elemente
	post: returneaza MyList care contine aceleasi elemente ca si lista (l)
*/
MyList* copyList(MyList* l);


/*
Face o copie a listei (pointer)

	pre: l - lista cu elemente
	post: returneaza MyList care contine aceleasi elemente ca si lista (l)
*/
//MyList* copieLista(MyList* l);


/*
Modifica elementul de pe o pozitie data

	pre: l - lista cu elemente
		 c - Cheltuiala
		 index - pozitia din lista care trebuie modificata
	post: modifica elementul de pe pozitia index
*/
void modificaElementLista(MyList* l, ElemType c, int index);


/*
Sterge elementul de pe o pozitie data

	pre: l - lista cu elemente
		 c - Cheltuiala
		 index - pozitia din lista care trebuie stearsa
	post: sterge elementul de pe o pozitia index si scade lungimea listei cu 1
*/
void stergeElementLista(MyList* l, int index);