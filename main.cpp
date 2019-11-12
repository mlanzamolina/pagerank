#include <iostream>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "pglist.h"
using namespace std;
typedef std::vector<std::string> stringvec;
int main()
{
	pglist a;
	char* cstr; 
	string keyword_s;
	string str;
	stringvec v;
	
	cout << "search: ";
	cin >> keyword_s;
	str =keyword_s;
	cstr = &str[0];
	a.buscar(cstr);
	a.print();
	a.read_directory("C:\\Users\\MarcoL\\Documents\\PageRank\\PageRank", v);

}
