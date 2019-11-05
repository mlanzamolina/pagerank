#include "pglist.h"
#include <iostream>
#include <fstream>
using namespace std;

bool pglist::isEmpty() 
{
	return primero == 0;
}
void pglist::agregar(nodoPagina**raiz,char* name) 
{
	
	if (!isEmpty())
	{
		nodoPagina* nuevo=new nodoPagina(name);


	}
}