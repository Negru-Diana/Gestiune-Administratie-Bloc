#include <stdlib.h> // Pentru a folosi functiile malloc si realloc

#include "MyList.h"
#include "cheltuieli.h"

#include<string.h>
#include<assert.h>
#include<stdio.h>

// Defineste marimea initiala a vectorului dinamic
#define INITIAL_CAPACITY 100


MyList* createEmpty()
{
    MyList* l = (MyList*)malloc(sizeof(MyList));
    if (l != NULL)
    {
        l->elem = (ElemType*)malloc(INITIAL_CAPACITY * sizeof(ElemType));
        if (l->elem == NULL)
        {
            free(l);
            return NULL; 
        }
        l->lungime = 0;
        l->capacitate = INITIAL_CAPACITY;
    }
    return l;
}


void destroy(MyList* l) 
{
    if (l != NULL)
    {
        free(l->elem);
        free(l);
    }
}


void add(MyList* l, ElemType c)
{
    if (l != NULL)
    {
        if (l->lungime == l->capacitate)
        {
            l->capacitate *= 2;
            ElemType* new_elem = (ElemType*)realloc(l->elem, l->capacitate * sizeof(ElemType));
            if (new_elem == NULL)
            {
                return;
            }
            l->elem = new_elem;
        }
        l->elem[l->lungime] = c;
        l->lungime++;
    }
}


ElemType get(MyList* l, int pozitie)
{
    return l->elem[pozitie];
}



int size(MyList* l)
{
    return l->lungime;
}



MyList* copyList(MyList* l)
{
    
    MyList* copie = createEmpty();
    if (copie != NULL)
    {
        for (int i = 0; i < size(l); i++)
        {
           Cheltuiala c = get(l, i);
           add(copie, c);
        }
    }
    return copie;
}



/*
MyList* copieLista(MyList* l)
{
    MyList* copie = (MyList*)malloc(sizeof(MyList));

    if (copie != NULL)
    {
        copie->lungime = l->lungime;
        copie->capacitate = l->capacitate;

        // Verific?m dac? lista original? nu este goal?
        if (l->lungime > 0 && l->elem != NULL) {
            // Aloc?m memorie pentru vectorul de elemente al listei copie
            copie->elem = (ElemType*)malloc(copie->capacitate * sizeof(ElemType));

            // Verific?m dac? alocarea memoriei a fost reu?it?
            if (copie->elem != NULL) {
                // Copiem elementele din lista original? în lista copie
                memcpy(copie->elem, l->elem, l->lungime * sizeof(ElemType));
            }

        }
        else {
            // Lista original? este goal? sau nu exist?, deci nu avem elemente de copiat
            copie->elem = NULL;
        }
    }

    return copie;
}
*/


void modificaElementLista(MyList* l, ElemType c, int index)
{
    if (l != NULL && index >= 0 && index < l->lungime)
    {
        l->elem[index] = c;
    }
}


void stergeElementLista(MyList* l, int index)
{
    if (l != NULL && index >= 0 && index < l->lungime)
    {
        for (int i = index; i < l->lungime - 1; i++)
        {
            l->elem[i] = l->elem[i + 1];
        }
        l->lungime--;
        ElemType* new_elem = (ElemType*)realloc(l->elem, l->lungime * sizeof(ElemType));
        if (new_elem != NULL)
        {
            l->elem = new_elem;
        }
    }
}