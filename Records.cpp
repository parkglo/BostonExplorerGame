#include "Records.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

Records::Records()
:date("01.01.2015"),
nr_points(0),
nr_level(0),
setline(0),
firstplace(0),
secondplace(0),
thirdplace(0)

{
}

void Records::loading(){

	ifstream file;
	file.open("Data/records.txt", ios::in);

	if (file.good() == false)
	{
		MessageBox(NULL, "Loading records file failing!", "ERROR", NULL);
		return;
	}

	string line;
	int new_numer_line = 0;

	while (getline(file, line))
	{
		if (new_numer_line == 30)
		{
			file >> firstplace >> secondplace >> thirdplace;
		}

		if (new_numer_line == setline)
		{
			file >> nr_level >> date >> nr_points;
		}

		new_numer_line++;
	}

	file.close();
}

Records::~Records()
{
}
