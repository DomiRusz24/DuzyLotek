#ifndef LOTTO_H
#define LOTTO_H

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