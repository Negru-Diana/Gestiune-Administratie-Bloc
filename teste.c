#include"MyList.h"
#include"cheltuieli.h"
#include"service.h"

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef Cheltuiala ElemType; 

// Functie de test pentru createCheltuiala()
void test_createCheltuiala() 
{
    Cheltuiala c = createCheltuiala(1, 100.0, "Alimente");

    assert(c.nrApartament == 1);
    assert(c.suma == 100.0);
    assert(strcmp(c.tip, "Alimente") == 0);
    destroyCheltuiala(&c);
}

// Functie de test pentru destroyCheltuiala()
void test_destroyCheltuiala() 
{
    Cheltuiala c = createCheltuiala(1, 100.00, "apa");

    destroyCheltuiala(&c); 

    assert(c.nrApartament == -1);
    assert(c.suma == -1.0);
    assert(strcmp(c.tip, "") == 0);
}

// Functie de test pentru valideazaCheltuiala()
void test_valideazaCheltuiala() 
{
    Cheltuiala c_valida = createCheltuiala(1, 100.0, "Alimente");
    assert(valideazaCheltuiala(c_valida) == 0);
    destroyCheltuiala(&c_valida);

    Cheltuiala c_nrApartament_invalid = createCheltuiala(-1, 100.0, "Alimente");
    assert(valideazaCheltuiala(c_nrApartament_invalid) == 1);
    destroyCheltuiala(&c_nrApartament_invalid);

    Cheltuiala c_suma_invalida = createCheltuiala(1, -100.0, "Alimente");
    assert(valideazaCheltuiala(c_suma_invalida) == 2);
    destroyCheltuiala(&c_suma_invalida);

    Cheltuiala c_tip_invalid = createCheltuiala(1, 100.0, "");
    assert(valideazaCheltuiala(c_tip_invalid) == 3);
    destroyCheltuiala(&c_tip_invalid);
}

// Test pentru createEmpty()
void test_createEmpty() 
{
    MyList* l = createEmpty();
    assert(l != NULL);

    assert(size(l) == 0);
    assert(l->capacitate == 100);

    destroy(l);

    printf("Testul functiei createEmpty a fost efectuat cu succes!\n");
}

// Test pentru destroy()
void test_destroy() 
{
    MyList* list = createEmpty();
    add(list, createCheltuiala(1, 100.0, "Alimente"));
    add(list, createCheltuiala(2, 200.0, "Gaz"));

    destroy(list);
    list = NULL; 
}

// Test pentru add() si get()
void test_add_get() 
{
    MyList* list = createEmpty();
    Cheltuiala c1 = createCheltuiala(1, 100.0, "Alimente");
    Cheltuiala c2 = createCheltuiala(2, 200.0, "Gaz");

    add(list, c1);
    add(list, c2);

    assert(size(list) == 2);

    assert(get(list, 0).nrApartament == c1.nrApartament);
    assert(get(list, 0).suma == c1.suma);
    assert(strcmp(get(list, 0).tip, c1.tip) == 0);

    assert(get(list, 1).nrApartament == c2.nrApartament);
    assert(get(list, 1).suma == c2.suma);
    assert(strcmp(get(list, 1).tip, c2.tip) == 0);

    destroy(list);
    destroyCheltuiala(&c1);
    destroyCheltuiala(&c2);
}

// Test pentru copyList()
void test_copyList() 
{
    MyList* l = createEmpty();
    add(l, createCheltuiala(1, 20, "apa"));
    add(l, createCheltuiala(2, 10, "gaz"));
    MyList* l2 = copyList(l);
    assert(size(l2) == 2);
    Cheltuiala c = get(l2, 0);
    assert(c.nrApartament == 1);
    destroyCheltuiala(&c);
    destroy(l);
    destroy(l2);
}

// Test pentru stergeElementLista()
void test_stergeElementLista() 
{
    MyList* list = createEmpty();
    add(list, createCheltuiala(1, 100.0, "Alimente"));
    add(list, createCheltuiala(2, 200.0, "Gaz"));
    add(list, createCheltuiala(3, 150.0, "Altele"));

    stergeElementLista(list, 1);
    destroy(list);
}


// Test pentru add
void test_add() 
{
   
    MyList* list = createEmpty();

    Cheltuiala c = createCheltuiala(1, 100.0, "Electricitate"); 

    add(list, c);

    assert(size(list) == 1);

    assert(list->elem[0].nrApartament == c.nrApartament);
    assert(list->elem[0].suma == c.suma);
    assert(strcmp(list->elem[0].tip, c.tip) == 0);

    for (int i = 0; i < 100; i++) 
    {
        add(list, c);
    }
    assert(list->capacitate == 200);

    destroy(list);
    destroyCheltuiala(&c);
}




// Test modificaElementLista()
void test_modificaElementLista()
{
    MyList* list = createEmpty();

    ElemType c1 = createCheltuiala(1, 100.0, "Electricitate");
    ElemType c2 = createCheltuiala(2, 150.0, "Gaz");
    ElemType c3 = createCheltuiala(3, 200.0, "Ap?");

    add(list, c1);
    add(list, c2);
    add(list, c3);

    ElemType new_c1 = createCheltuiala(10, 500.0, "Internet");
    modificaElementLista(list, new_c1, 0);

    assert(list->elem[0].nrApartament == new_c1.nrApartament);
    assert(list->elem[0].suma == new_c1.suma);
    assert(strcmp(list->elem[0].tip, new_c1.tip) == 0);

    ElemType new_c2 = createCheltuiala(20, 750.0, "Înc?lzire");
    modificaElementLista(list, new_c2, 1);

    assert(list->elem[1].nrApartament == new_c2.nrApartament);
    assert(list->elem[1].suma == new_c2.suma);
    assert(strcmp(list->elem[1].tip, new_c2.tip) == 0);

    ElemType new_c3 = createCheltuiala(30, 1000.0, "Lumân?ri");
    modificaElementLista(list, new_c3, 2);

    assert(list->elem[2].nrApartament == new_c3.nrApartament);
    assert(list->elem[2].suma == new_c3.suma);
    assert(strcmp(list->elem[2].tip, new_c3.tip) == 0);

    destroy(list);
    destroyCheltuiala(&c1);
    destroyCheltuiala(&c2);
    destroyCheltuiala(&c3);
    destroyCheltuiala(&new_c1);
    destroyCheltuiala(&new_c2);
    destroyCheltuiala(&new_c3);

    printf("Testul pentru modificaElementLista a fost efectuat cu succes!\n");
}


// Test pentru ExistaCheltuiala()
void testExistaCheltuiala() 
{
    
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 100.0, "Alimente");

    Cheltuiala c1 = createCheltuiala(1, 100.0, "Alimente");
    assert(existaCheltuiala(lista, c1) == 0); 

    Cheltuiala c2 = createCheltuiala(2, 200.0, "Transport");
    assert(existaCheltuiala(lista, c2) == -1); 

    destroy(lista);
    destroyCheltuiala(&c1);
    destroyCheltuiala(&c2);
}

//Test AddCheltuiala()
void testAddCheltuiala() 
{
    MyList* lista = createEmpty();

    assert(addCheltuiala(lista, 1, 100.0, "Alimente") == 0); 

    assert(addCheltuiala(lista, 2, -50.0, "Transport") == 1);

    assert(addCheltuiala(lista, 1, 150.0, "Alimente") == 2); 

    assert(size(lista) == 1);

    destroy(lista);
}

//Test FiltrareDupaNumarApartament() 
void testFiltrareDupaNumarApartament() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 100.0, "Alimente");
    addCheltuiala(lista, 2, 150.0, "Transport");
    addCheltuiala(lista, 1, 200.0, "Altele");

    MyList* filtrata = filtrareDupaNumarApartament(lista, 1);

    assert(size(filtrata) == 2);

   
    assert(get(filtrata, 0).nrApartament == 1);
    assert(get(filtrata, 1).nrApartament == 1);

    destroy(lista);
    destroy(filtrata);
}

//Test FiltrareDupaTip() 
void testFiltrareDupaTip() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 100.0, "Alimente");
    addCheltuiala(lista, 2, 150.0, "Transport");
    addCheltuiala(lista, 1, 200.0, "Altele");

    MyList* filtrata = filtrareDupaTip(lista, "Alimente");

    assert(size(filtrata) == 1);

    assert(strcmp(get(filtrata, 0).tip, "Alimente") == 0);

    destroy(lista);
    destroy(filtrata);
}

//Test SortareSumaCrescator() 
void testSortareSumaCrescator() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Alimente");
    addCheltuiala(lista, 2, 150.0, "Transport");
    addCheltuiala(lista, 3, 250.0, "Altele");

    MyList* listaSortata = SortareSumaCrescator(lista);

    assert(size(listaSortata) == 3);

    for (int i = 0; i < size(listaSortata) - 1; i++) 
    {
        assert(get(listaSortata, i).suma <= get(listaSortata, i + 1).suma);
    }

    destroy(lista);
    destroy(listaSortata);
}


//Test SortareSumaDescrescator()
void testSortareSumaDescrescator() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Alimente");
    addCheltuiala(lista, 2, 150.0, "Transport");
    addCheltuiala(lista, 3, 250.0, "Altele");

    MyList* listaSortata = SortareSumaDesrescator(lista);

    assert(size(listaSortata) == 3);

    for (int i = 0; i < size(listaSortata) - 1; i++) 
    {
        assert(get(listaSortata, i).suma >= get(listaSortata, i + 1).suma);
    }

    destroy(lista);
    destroy(listaSortata);
}

//Test SortareTipCrescator()
void testSortareTipCrescator() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Transport");
    addCheltuiala(lista, 2, 150.0, "Alimente");
    addCheltuiala(lista, 3, 250.0, "Altele");

    MyList* listaSortata = SortareTipCrescator(lista);

    assert(size(listaSortata) == 3);

    for (int i = 0; i < size(listaSortata) - 1; i++) 
    {
        assert(strcmp(get(listaSortata, i).tip, get(listaSortata, i + 1).tip) <= 0);
    }

    destroy(lista);
    destroy(listaSortata);
}

//Test SortareTipDescrescator()
void testSortareTipDescrescator() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Transport");
    addCheltuiala(lista, 2, 150.0, "Alimente");
    addCheltuiala(lista, 3, 250.0, "Altele");

    MyList* listaSortata = SortareTipDescrescator(lista);

    assert(size(listaSortata) == 3);

    for (int i = 0; i < size(listaSortata) - 1; i++) 
    {
        assert(strcmp(get(listaSortata, i).tip, get(listaSortata, i + 1).tip) >= 0);
    }

    destroy(lista);
    destroy(listaSortata);
}


//Test FiltrareDupaSuma()
void testFiltrareDupaSuma() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Transport");
    addCheltuiala(lista, 2, 150.0, "Alimente");
    addCheltuiala(lista, 3, 250.0, "Altele");
    addCheltuiala(lista, 4, 180.0, "Transport");

    MyList* listaFiltrata = filtrareDupaSuma(lista, 150.0, 200.0);

    assert(size(listaFiltrata) == 3);

    assert(get(listaFiltrata, 0).suma == 200.0);
    assert(get(listaFiltrata, 1).suma == 150.0);
    assert(get(listaFiltrata, 2).suma == 180.0);

    destroy(lista);
    destroy(listaFiltrata);
}

//Test StergeElementLista()
void testStergeElementLista() 
{
    MyList* lista = createEmpty();

    addCheltuiala(lista, 1, 200.0, "Transport");
    addCheltuiala(lista, 2, 150.0, "Alimente");
    addCheltuiala(lista, 3, 250.0, "Altele");
    addCheltuiala(lista, 4, 180.0, "Transport");

    stergeElementLista(lista, 1);

    assert(size(lista) == 3);

    assert(get(lista, 1).nrApartament == 3);
    assert(strcmp(get(lista, 1).tip, "Altele") == 0);

    destroy(lista);
}

//Test compTip()
void testCompTip() 
{
    Cheltuiala cheltuiala1 = { 1, 100.0, "Alimente" };
    Cheltuiala cheltuiala2 = { 2, 150.0, "Utilitati" };

    
    int rezultat = CompTip(cheltuiala1, cheltuiala2);

   
    assert(rezultat < 0);  

    rezultat = CompTip(cheltuiala2, cheltuiala1);

    
    assert(rezultat > 0);

    destroyCheltuiala(&cheltuiala1);
    destroyCheltuiala(&cheltuiala2);
}

//Test CompSuma()
void testCompSuma()
{
    Cheltuiala cheltuiala1 = createCheltuiala(1, 100.0, "Cheltuiala 1");
    Cheltuiala cheltuiala2 = createCheltuiala(2, 150.0, "Cheltuiala 2");
    Cheltuiala cheltuiala3 = createCheltuiala(3, 100.0, "Cheltuiala 3");
    Cheltuiala cheltuiala4 = createCheltuiala(4, 200.0, "Cheltuiala 4");

    assert(CompSuma(cheltuiala1, cheltuiala2) == 0); 
    assert(CompSuma(cheltuiala2, cheltuiala1) == 1); 
    assert(CompSuma(cheltuiala1, cheltuiala3) == 2); 
    assert(CompSuma(cheltuiala4, cheltuiala2) == 1); 
    
    destroyCheltuiala(&cheltuiala1);
    destroyCheltuiala(&cheltuiala2);
    destroyCheltuiala(&cheltuiala3);
    destroyCheltuiala(&cheltuiala4);
}


//Test sortareCheltuieli()
void testSortareCheltuieli() 
{
    
    MyList* list = createEmpty();

    
    add(list, createCheltuiala(1, 100.0, "Alimente"));
    add(list, createCheltuiala(2, 200.0, "Gaz"));
    add(list, createCheltuiala(3, 150.0, "Electricitate"));

    
    MyList* sortedAsc = sortareCheltuieli(list, 1, (sorteaza)CompSuma, (sorteaza)CompTip);

    assert(strcmp(get(sortedAsc, 0).tip, "Alimente") == 0);
    assert(strcmp(get(sortedAsc, 1).tip, "Electricitate") == 0);
    assert(strcmp(get(sortedAsc, 2).tip, "Gaz") == 0);

    
    MyList* sortedDesc = sortareCheltuieli(list, 0, (sorteaza)CompSuma, (sorteaza)CompTip);
    
    assert(strcmp(get(sortedDesc, 0).tip, "Gaz") == 0);
    assert(strcmp(get(sortedDesc, 1).tip, "Electricitate") == 0);
    assert(strcmp(get(sortedDesc, 2).tip, "Alimente") == 0);

    destroy(list);
    destroy(sortedAsc);
    destroy(sortedDesc);
}



/*
Coordoneaza testarea tuturor functiilor

    pre: true
    post: coordoneaza testarea tuturor functiilor
*/
void testAll()
{ 
    testSortareSumaCrescator();

    testFiltrareDupaNumarApartament();
    testFiltrareDupaTip();

    test_add();  

    test_modificaElementLista();

    test_createCheltuiala(); 
    test_destroyCheltuiala();
    test_valideazaCheltuiala();

    test_createEmpty(); 
    test_destroy(); 
    test_add_get(); 
    test_copyList(); 
    test_stergeElementLista(); 

    testSortareSumaDescrescator();
    testSortareTipCrescator();
    testSortareTipDescrescator();
    
    testExistaCheltuiala();
    testAddCheltuiala();

    testFiltrareDupaSuma();

    testStergeElementLista();

    testCompTip(); 
    testCompSuma(); 

    testSortareCheltuieli(); 
}