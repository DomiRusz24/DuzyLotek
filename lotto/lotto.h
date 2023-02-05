#ifndef LOTTO_H
#define LOTTO_H

#include <ctime>
#include <cstdlib>
#include <iostream>

#define AMOUNT 6

class Lotto {
public:
	int random[AMOUNT];
	int selected[AMOUNT];
	bool hasSelected;
	bool hasRandomized;
	Lotto();

	void randomize();
	void promptUser();
	int check();
};

#endif