#pragma once
#include <string>

using namespace std;

class Records
{

public:

	Records();
	~Records();

	int nr_level;
	int	nr_points;
	int firstplace;
	int secondplace;
	int thirdplace;
	string date;

	void SetLinie(unsigned int n_linia)		{ setline = n_linia; };
	void loading();

private:

	unsigned int setline;

};
