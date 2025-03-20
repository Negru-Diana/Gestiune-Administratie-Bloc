#define _CRTDBG_MAP_ALLOC 

#include "ui.h"
#include"teste.h"

#include <crtdbg.h>


int main()
{
	//testAll();
	run();

	_CrtDumpMemoryLeaks();
}