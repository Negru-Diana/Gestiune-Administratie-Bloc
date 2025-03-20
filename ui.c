#include "ui.h"
#include "MyList.h"
#include "service.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  


/*
Coordoneaza aplicatia

	pre: true
	post: coordoneaza aplicatia
*/
void run()
{
	MyList* l = createEmpty();

	//addCheltuiala(l, 1, 230, "apa");
	//addCheltuiala(l, 1, 130, "a");
	//addCheltuiala(l, 1, 137, "curent");
	//addCheltuiala(l, 2, 130, "gaz");
	//addCheltuiala(l, 2, 231, "apa");
	//addCheltuiala(l, 3, 2, "gaz");

	bool continua = true;

	while (continua == true)
	{
		meniu();
		int optiune = optiuneMeniu();
		 
		if (optiune == 0)  // 0. Iesire program
		{
			mesajIesireProgram();
			continua = false;
			destroy(l); 
			return;
		}

		if (optiune == 1)  // 1. Adauga cheltuiala pentru un apartament
		{
			optiune1(l);
			continue;
		}

		if (optiune == 2)  // 2. Modificarea unei cheltuieli existente (tipul, suma)
		{
			optiune2(l);
			continue;
		}

		if (optiune == 3)  // 3. Sterge cheltuiala
		{
			optiune3(l);
			continue;
		}

		if (optiune == 4)  // 4. Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)
		{
			optiune4(l);
			continue;
		}

		if (optiune == 5)  // 5. Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)
		{
			optiune5(l);
			continue;
		}

		if (optiune == 6)  // 6. Vizualizare lista de cheltuieli
		{
			optiune6(l);
			continue;
		}

		mesajOptiuneMeniuInvalida();
	}

	destroy(l);
}

void clearInputBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		// Do nothing, just discard characters
	}
}


void optiune1(MyList* list)
{
	int nrApartament = readNrApartament();
	clearInputBuffer();
	float suma = readSuma();
	clearInputBuffer();
	char tip[30];
	readTip(tip);
	clearInputBuffer();

	int rezultat = addCheltuiala(list, nrApartament, suma, tip);
	if (rezultat == 1)
	{
		mesajDateCheltuialaInvalide();
	}

	if (rezultat == 2)
	{
		mesajExistaCheltuiala();
	}

	if (rezultat == 0)
	{
		mesajDateCheltuialaAdaugate();
	}
}


void optiune2(MyList* list)
{
	int nrApartament = readNrApartament();
	clearInputBuffer();
	char tip[30];
	readTip(tip);
	clearInputBuffer();

	Cheltuiala c = createCheltuiala(nrApartament, 0.00, tip);
	int index = existaCheltuiala(list, c);
	if (index == -1)
	{
		mesajCheltuialaInexistenta();
		return;
	}

	readTip(tip);
	float suma = readSuma();

	c = createCheltuiala(nrApartament, suma, tip);
	if (valideazaCheltuiala(c) != 0)
	{
		mesajDateCheltuialaInvalide();
		return;
	}

	modificaElementLista(list, c, index);
	mesajCheltuialaModificata();
	destroyCheltuiala(&c);
}



void optiune3(MyList* list)
{
	int nrApartament = readNrApartament();
	clearInputBuffer();
	char tip[30];
	readTip(tip);
	clearInputBuffer();

	Cheltuiala c = createCheltuiala(nrApartament, 0.00, tip);
	int index = existaCheltuiala(list, c);
	if (index == -1)
	{
		mesajCheltuialaInexistenta();
		return;
	}

	stergeElementLista(list,index);

	mesajCheltuialaStearsa();
	destroyCheltuiala(&c); 
}



void optiune4(MyList* list)
{
	int tipf = readTipFiltrare();
	clearInputBuffer();

	if (tipf < 1 || tipf > 3)
	{
		printf("\nOptiunea de filtrare este invalida!\n");
		return;
	}

	if (list->lungime == 0)
	{
		printf("\nNu exista cheltuieli de afisat!\n");
		return;
	}

	if (tipf == 1)  //filtrare dupa numar apartament
	{
		int nrApartament = readNrApartament();
		clearInputBuffer();

		if (nrApartament < 0)
		{
			printf("\nNumarul apartamentului dupa care doriti sa filtrati este invalid!\n");
			return;
		}

		MyList* listaNrApartament = filtrareDupaNumarApartament(list, nrApartament);

		if (listaNrApartament->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
		}
		else
		{
			for (int i = 0; i < listaNrApartament->lungime; i++)
			{
				Cheltuiala c = listaNrApartament->elem[i];
				afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
			}
		}

		destroy(listaNrApartament);
	}

	if (tipf == 2)  //filtrare dupa suma
	{
		float sumaMinim;
		printf("suma minima: ");
		scanf_s("%f", &sumaMinim);
		clearInputBuffer();

		float sumaMaxim;
		printf("\nsuma maxima: ");
		scanf_s("%f", &sumaMaxim);
		clearInputBuffer();

		if (sumaMinim < 0 || sumaMaxim < 0)
		{
			printf("\nIntervalul de sume dupa care doriti sa filtrati este invalid!\n");
			return;
		}

		MyList* listaSuma = filtrareDupaSuma(list, sumaMinim, sumaMaxim);

		if (listaSuma->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
		}
		else
		{
			for (int i = 0; i < listaSuma->lungime; i++)
			{
				Cheltuiala c = listaSuma->elem[i];
				afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
			}
		}
		destroy(listaSuma);
	}

	if (tipf == 3)  //filtrare dupa tip
	{
		char tip[30];
		readTip(tip);
		clearInputBuffer();

		if (strcmp(tip, "") == 0)
		{
			printf("\nTipul dupa care doriti sa filtrati este invalid!\n");
			return;
		}

		MyList* listaTip = filtrareDupaTip(list, tip);

		if (listaTip->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
		}
		else
		{
			for (int i = 0; i < listaTip->lungime; i++)
			{
				Cheltuiala c = listaTip->elem[i];
				afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
			}
		}
		destroy(listaTip);
	}
}


void optiune5(MyList* list)
{
	if (list->lungime == 0)
	{
		printf("\nNu exista cheltuieli de afisat!\n");
		return;
	}

	int tips = readTipSortare();
	clearInputBuffer();

	if (tips < 1 || tips > 2)
	{
		printf("\nOptiunea de sortare este invalida!\n");
		return;
	}

	if (tips == 1)
	{
		MyList* listaSortata = sortareCheltuieli(list, 1, CompSuma, CompTip);
		for (int i = 0; i < listaSortata->lungime; i++)
		{
			Cheltuiala c = listaSortata->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
		destroy(listaSortata);
	}

	if (tips == 2)
	{
		MyList* listaSortata = sortareCheltuieli(list, 0, CompSuma, CompTip);
		for (int i = 0; i < listaSortata->lungime; i++)
		{
			Cheltuiala c = listaSortata->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
		destroy(listaSortata);
	}
}

/*
void optiune5_1(MyList* list)
{
	if (list->lungime == 0)
	{
		printf("\nNu exista cheltuieli de afisat!\n");
		return;
	}

	int tips = readTipSortare();
	clearInputBuffer();

	if (tips < 1 || tips>4)
	{
		printf("\nOptiunea de sortare este invalida!\n");
	}

	if (tips == 1)  //sortare suma crescator
	{
		MyList* listaSortataCrescatorSuma = SortareSumaCrescator(list);

		if (listaSortataCrescatorSuma->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
			return;
		}

		for (int i = 0; i < listaSortataCrescatorSuma->lungime; i++)
		{
			Cheltuiala c = listaSortataCrescatorSuma->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
	}

	if (tips == 2)  //sortare suma descrescator
	{

		MyList* listaSortataDescrescatorSuma = SortareSumaDesrescator(list);

		if (listaSortataDescrescatorSuma->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
			return;
		}

		for (int i = 0; i < listaSortataDescrescatorSuma->lungime; i++)
		{
			Cheltuiala c = listaSortataDescrescatorSuma->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
	}

	if (tips == 3)  //sortare tip crescator
	{

		MyList* listaSortataCrescatorTip = SortareTipCrescator(list);

		if (listaSortataCrescatorTip->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
			return;
		}

		for (int i = 0; i < listaSortataCrescatorTip->lungime; i++)
		{
			Cheltuiala c = listaSortataCrescatorTip->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
	}

	if (tips == 4) //sortare tip descrescator
	{

		MyList* listaSortataDesrescatorTip = SortareTipDescrescator(list);

		if (listaSortataDesrescatorTip->lungime == 0)
		{
			printf("\nNu exista cheltuieli de afisat!\n");
			return;
		}

		for (int i = 0; i < listaSortataDesrescatorTip->lungime; i++)
		{
			Cheltuiala c = listaSortataDesrescatorTip->elem[i];
			afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
		}
	}
	
}
*/



void optiune6(MyList* list)
{
	if (size(list) == 0)
	{
		mesajCheltuieliInexistente();
		return;
	}

	for (int i = 0; i < size(list); i++)
	{
		Cheltuiala c = get(list, i);
		afiseazaCheltuiala(c.nrApartament, c.suma, c.tip);
	}
}


void meniu()
{
	printf("\nMeniu: \n");
	printf("0. Iesire program\n");
	printf("1. Adauga cheltuiala pentru un apartament\n");
	printf("2. Modificarea unei cheltuieli existente (tipul, suma)\n");
	printf("3. Sterge cheltuiala\n");
	printf("4. Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)\n");
	printf("5. Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");
	printf("6. Vizualizare lista de cheltuieli\n");
}



int optiuneMeniu()
{
	printf("\noptiune: ");
	int optiune;
	scanf_s("%d", &optiune);
	return optiune;
}



void mesajIesireProgram()
{
	printf("\nLa revedere!\n");
}




int readNrApartament()
{
	printf("\nnumar apartament: ");
	int nrApartament;
	scanf_s("%d", &nrApartament);

	return nrApartament;
}



float readSuma()
{
	printf("suma: ");
	float suma;
	scanf_s("%f", &suma);

	return suma;
}



void readTip(char* buffer)
{
	printf("tip: ");
	scanf_s("%s", buffer, 30);
}



void mesajDateCheltuialaInvalide()
{
	printf("\nDatele introduse sunt invalide! (numar apartament > 0, suma >= 0.00, tip - trebuie scris un tip de cheltuiala)\n");
}



void mesajDateCheltuialaAdaugate()
{
	printf("\nDatele au fost adaugate!\n");
}



void afiseazaCheltuiala(int nrApartament, float suma, char* tip)
{
	printf("numar apartament: %d; suma: %.2f lei; tip: %s\n", nrApartament, suma, tip);
}



void mesajCheltuieliInexistente()
{
	printf("\nNu exista cheltuieli de afisat!\n");
}



void mesajExistaCheltuiala()
{
	printf("\nCheltuiala exista deja!\n");
}



void mesajCheltuialaInexistenta()
{
	printf("\nCheltuiala nu exista!\n");
}


void mesajCheltuialaModificata()
{
	printf("\nCheltuiala a fost modificata!\n");
}



void mesajOptiuneMeniuInvalida()
{
	printf("\nOptiunea aleasa din meniu este invalida!\n");
}


void mesajCheltuialaStearsa()
{
	printf("\nCheltuiala a fost stearsa!\n");
}



int readTipFiltrare()
{
	printf("\nTip filtrare (1 - numar apartament, 2 - suma, 3 - tip): ");
	int tipf;
	scanf_s("%d", &tipf);

	return tipf;
}



int readTipSortare()
{
	printf("\nTip sortare (1 - crescator, 2 - descrescator): ");
	int tipf;
	scanf_s("%d", &tipf);

	return tipf;
}
/*
int readTipSortare_1()
{
	printf("\nTip sortare (1 - suma crescator, 2 - suma descrescator, 3 - tip crescator, 4 - tip descrescator): ");
	int tipf;
	scanf_s("%d", &tipf);

	return tipf;
}
*/