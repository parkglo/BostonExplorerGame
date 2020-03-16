#include "Records.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

Records::Records()
nr_points(0),
nr_level(0),
setline(0),

    vector <string > vec;                               // instead of initializing first, second, and third place scores to 0, read in from the records files to get the current first, second, third score.
    file.open("Data/records.txt", ios::in);

    string tmp;
    string substring__Record;
    string substring__Date;

    int temp_int = 0;

    for (int i = 0; i < 3 ; i++){
        getline(file, tmp);
        substring__Date = tmp.substr(3,12)

        substring__Record = tmp.substr(24);
        temp_int = atoi(substring__Record);

        if (i == 0){
            date(substring__Date);
            firstplace(temp_int);
        }

        if (i == 1){
            date(substring__Date);
            secondplace(temp_int);
        }

        if (i == 2){
            date(substring__Date);
            thirdplace(temp_int);
        }
    }


    file.close();


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
