#include "cheltuieli.h"
#include "MyList.h"

#include<stdio.h>
#include<string.h>
#include<assert.h>

int CompTip(Cheltuiala c1, Cheltuiala c2) 
{
	return strcmp(c1.tip, c2.tip);
}

int CompSuma(Cheltuiala c1, Cheltuiala c2) 
{
	if (c1.suma > c2.suma) {
		return 1;
	}
	if (c1.suma == c2.suma)
	{
		return 2;
	}
	return 0;
}


Cheltuiala createCheltuiala(int nrApartament, float suma, char* tip)
{
	Cheltuiala c;
	c.nrApartament = nrApartament;
	c.suma = suma;
	strcpy_s(c.tip, sizeof(c.tip)-1, tip);    // in c.tip se copiaza tip (se aloca dimensiunea de care are nevoie tip --> char)
	c.tip[sizeof(c.tip) - 1] = '\0';

	return c;
}


void destroyCheltuiala(Cheltuiala* c)
{
	c->nrApartament = -1;
	c->suma = -1.00;
	c->tip[0] = '\0';
}



int valideazaCheltuiala(Cheltuiala c)
{
	if (c.nrApartament < 0)
	{
		return 1;  // nrApartament invalid
	}

	if (c.suma < 0.00)
	{
		return 2;  // suma invalida
	}

	if (strlen(c.tip) == 0)
	{
		return 3;  // tip invalid
	}

	return 0;  // nrApartament, suma si tip valide
}