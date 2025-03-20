#include "service.h"
#include "MyList.h"
#include "ui.h"
#include "cheltuieli.h"

#include<stdio.h>
#include<string.h>



int existaCheltuiala(MyList* list, Cheltuiala c)
{
	for (int i = 0; i < size(list); i++)
	{
		Cheltuiala c2 = get(list, i);
		if (c.nrApartament == c2.nrApartament && strcmp(c.tip, c2.tip) == 0)
		{
			return i;
		}
	}

	return -1;
}



int addCheltuiala(MyList* list, int nrApartament, float suma, char* tip)
{
	Cheltuiala c = createCheltuiala(nrApartament, suma, tip);
	if (valideazaCheltuiala(c) != 0)
	{
		destroyCheltuiala(&c);
		return 1;
	}

	if (existaCheltuiala(list, c) > -1)
	{
		destroyCheltuiala(&c);
		return 2;
	}

	add(list, c);
	return 0;
}



MyList* filtrareDupaNumarApartament(MyList* list, int nrApartament)
{
	MyList* filtrare = createEmpty();
	for (int i = 0; i < size(list); i++)
	{
		Cheltuiala c = get(list, i);
		if (c.nrApartament == nrApartament)
		{
			add(filtrare, c);
		}
	}

	return filtrare;
}



MyList* filtrareDupaTip(MyList* list, char* tip)
{
	MyList* filtrare = createEmpty();
	for (int i = 0; i < size(list); i++)
	{
		Cheltuiala c = get(list, i);
		if (strcmp(c.tip, tip) == 0)
		{
			add(filtrare, c);
		}
	}

	return filtrare;
}



MyList* filtrareDupaSuma(MyList* list, float sumaMinim, float sumaMaxim)
{
	MyList* filtrare = createEmpty();
	for (int i = 0; i < size(list); i++)
	{
		Cheltuiala c = get(list, i);
		if (c.suma >= sumaMinim && c.suma <= sumaMaxim)
		{
			add(filtrare, c);
		}
	}

	return filtrare;
}



MyList* SortareSumaCrescator(MyList* list)
{
	MyList* listaSortata = copyList(list);

	for (int i = 0; i < size(listaSortata) - 1; i++)
	{
		for (int j = i + 1; j < size(listaSortata); j++)
		{
			if (get(listaSortata, i).suma > get(listaSortata, j).suma)
			{
				ElemType temp = get(listaSortata, i);
				modificaElementLista(listaSortata, get(listaSortata, j), i);
				modificaElementLista(listaSortata, temp, j);
			}
		}
	}

	return listaSortata;
}



MyList* SortareSumaDesrescator(MyList* list)
{
	MyList* listaSortata = copyList(list);

	for (int i = 0; i < size(listaSortata) - 1; i++)
	{
		for (int j = i + 1; j < size(listaSortata); j++)
		{
			if (get(listaSortata, i).suma < get(listaSortata, j).suma)
			{
				ElemType temp = get(listaSortata, i);
				modificaElementLista(listaSortata, get(listaSortata, j), i);
				modificaElementLista(listaSortata, temp, j);
			}
		}
	}

	return listaSortata;
}


MyList* SortareTipCrescator(MyList* list)
{
	MyList* listaSortata = copyList(list);

	for (int i = 0; i < size(listaSortata) - 1; i++)
	{
		for (int j = i + 1; j < size(listaSortata); j++)
		{

			if (strcmp(get(listaSortata, i).tip, get(listaSortata, j).tip) > 0)
			{

				ElemType temp = get(listaSortata, i);
				modificaElementLista(listaSortata, get(listaSortata, j), i);
				modificaElementLista(listaSortata, temp, j);
			}

		}
	}

	return listaSortata;
}



MyList* SortareTipDescrescator(MyList* list)
{
	MyList* listaSortata = copyList(list);

	for (int i = 0; i < size(listaSortata) - 1; i++)
	{
		for (int j = i + 1; j < size(listaSortata); j++)
		{

			if (strcmp(get(listaSortata, i).tip, get(listaSortata, j).tip) < 0)
			{

				ElemType temp = get(listaSortata, i);
				modificaElementLista(listaSortata, get(listaSortata, j), i);
				modificaElementLista(listaSortata, temp, j);
			}
		}
	}

	return listaSortata;
}


MyList* sortareCheltuieli(MyList* lista, int crescator, sorteaza cmp1, sorteaza cmp2)
{
	MyList* list = copyList(lista);

	for (int i = 0; i < size(list) - 1; i++)
	{
		for (int j = i + 1; j < size(list); j++)
		{
			int cmpRezultat;
			if (crescator == 1)
			{
				cmpRezultat = cmp1(get(list, i), get(list, j));
				if (cmpRezultat == 1 || (cmpRezultat == 2 && cmp2(get(list, i), get(list, j)) == 1))
				{
					ElemType temp = get(list, i);
					modificaElementLista(list, get(list, j), i);
					modificaElementLista(list, temp, j);
				}
			}
			else
			{
				cmpRezultat = cmp1(get(list, i), get(list, j));
				if (cmpRezultat == 0 || (cmpRezultat == 2 && cmp2(get(list, i), get(list, j)) == 1))
				{
					ElemType temp = get(list, i);
					modificaElementLista(list, get(list, j), i);
					modificaElementLista(list, temp, j);
				}
			}
		}
	}
	return list;
}
