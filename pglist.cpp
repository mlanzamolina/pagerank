#include "pglist.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <sys/stat.h>

using namespace std;
bool pglist::isEmptyB()
{
	return primeroBuscar == 0;
}
bool pglist::isEmpty()
{
	return primero == 0;
}

void pglist::read_directory(const std::string& name, stringvec& v)
{
	std::string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			v.push_back(data.cFileName);
            if (isEmpty())
			{
				nodoPagina* nuevo = new nodoPagina(data.cFileName);
				primero = nuevo;

			}
			else
			{
				nodoPagina* nuevo = new nodoPagina(data.cFileName);
				nodoPagina* actual = primero;
				while (actual!=0)
				{
					if (actual->abajo==0)
					{
						actual->abajo= nuevo;
						break;
					}
					actual = actual->abajo;
				}

			}
			

		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
}

void pglist::loadList()
{
	string str;
	char* cstr;
	bool vEmpty = false;
	int cont = 0; std::string line_; std::string linea;
	stringvec v;
	stringvec pathe;
	std::string::size_type href;

	read_directory("C:\\Users\\MarcoL\\Documents\\PageRank\\PageRank", v);
	
	nodoPagina* actual = primeroBuscar;
	while (!vEmpty)
	{

		std::ifstream file_("C:\\Users\\MarcoL\\Documents\\PageRank\\PageRank\\" + v[cont]);
		if (file_.is_open())
		{

			while (getline(file_, linea))
			{
				href = linea.find("href");
				if (href < std::string::npos)
				{
					str = linea;
					cstr = &str[0];

					if (actual->siguiente==nullptr)
					{
						return;
					}
					actual->siguiente->nombre = cstr;
					actual->siguiente = actual->siguiente->siguiente;
				}



			}
			file_.close();
			if (actual==nullptr)
			{
				break;

			}
			actual = actual->abajo;

		}
		
		
		cont++;
		if (cont == v.size())
		{
			vEmpty = true;

		}
	}

}

void pglist::buscar(string keyword_)
{
	bool vEmpty = false;
	int cont = 0; std::string line_; std::string linea;
	stringvec v;
	stringvec pathe;
	string str;
	char* cstr;
	std::string::size_type href;

	read_directory("C:\\Users\\MarcoL\\Documents\\PageRank\\PageRank", v);
	
	while (!vEmpty)
	{

		std::ifstream file_("C:\\Users\\MarcoL\\Documents\\PageRank\\PageRank\\" + v[cont]);
		if (file_.is_open())
		{
			while (getline(file_, linea))
			{
				href = linea.find(keyword_);
				if (href < std::string::npos)
				{
					str = v[cont];
					cstr = &str[0];
					nodoPagina* nuevo = new nodoPagina(cstr);
					if (isEmptyB())
					{
						primeroBuscar = nuevo;

					}
					else
					{
						nodoPagina* actual = primeroBuscar;
						while (actual != 0)
						{
							if (actual->abajo == 0)
							{
								actual->abajo = nuevo;
								break;
							}
							actual = actual->abajo;
						}
					}
				}



			}
			file_.close();

		}
		cont++;
		if (cont == v.size())
		{
			vEmpty = true;

		}
	}
	loadList();
}
void pglist::print()
{
	nodoPagina* actual = primeroBuscar;
	
	while (actual!=0)
	{
		cout << actual->nombre<<"\n";
		actual = actual->abajo;
		

	}
}
void pglist::printb()
{
	nodoPagina* actual = primero;

	while (actual != 0)
	{
		cout << actual->nombre << "\n";
		actual = actual->abajo;


	}
}
