#pragma once

#ifndef PGLIST_H
#define PSLIST_H
#include <string.h>
#include <fstream>
#include <direct.h>
#include <sys/stat.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
typedef std::vector<std::string> stringvec;
struct nodoPagina
{
	char* nombre;
	double pageRank;
	nodoPagina * abajo;
	nodoPagina* siguiente;
	nodoPagina(char*name):abajo(0),siguiente(0),pageRank(0)
	{
		nombre = new char[strlen(name)];
		strcpy(nombre, name);
	}

};


class pglist
{
private:
	nodoPagina* primero;
	nodoPagina* primeroBuscar;
public:
	pglist():primero(0),primeroBuscar(0)
	{

	}
	bool isEmptyB();
	bool isEmpty();
	void loadList();
	void read_directory(const std::string& name, stringvec& v);
	void buscar(std::string keyword_);
	void print();
	void printb();
};


#endif // !PGLIST_H
