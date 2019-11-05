#pragma once
#ifndef PGLIST_H
#define PSLIST_H
#include <string.h>
struct nodoPagina
{
	char* nombre;
	double pageRank;
	nodoPagina* abajo;
	nodoPaginaRedirect* siguiente;
	nodoPagina(char*name):abajo(0),siguiente(0)
	{
		nombre = new char[strlen(name)];
		strcpy(nombre, name);
	}

};
struct nodoPaginaRedirect
{
	char* nombre;
	nodoPaginaRedirect* siguiente;
	nodoPaginaRedirect(char* name) :siguiente(0)
	{
		nombre = new char[strlen(name)];
		strcpy(nombre, name);
	}

};

class pglist
{
private:
	nodoPagina* primero;

public:
	bool isEmpty();
	void agregar(nodoPagina**,char*);
	void agregarLinks();
	void ordenarCalculo();
	
	 
};

#endif // !PGLIST_H
