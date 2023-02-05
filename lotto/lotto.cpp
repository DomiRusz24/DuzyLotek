#include "lotto.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Lotto::Lotto() {
	srand(time(NULL));
	this->hasRandomized = false;
	this->hasSelected = false;
}

int promptIntUntilGood(int i) {
	cout << "Prosze podaj " << (i + 1) << " liczbe: ";
	int a;
	cin >> a;
	if (a >= 0 && a <= 49) {
		return a;
	}
	cout << endl << "Liczba musi być w zakresie 0 - 49, sprobuj jeszcze raz!" << endl;
	return promptIntUntilGood(i);
}

void Lotto::promptUser() {
	for (int i = 0; i < AMOUNT; i++) {
		this->selected[i] = promptIntUntilGood(i);
	}
	this->hasSelected = true;
}



int randomInt(int min, int max) {
	return (rand() % (max - min)) + min;
}

int Lotto::check() {
	if (!this->hasRandomized || !this->hasSelected) return 0;

	int guessed = 0;

	for (int i = 0; i < AMOUNT; i++) {
		if (this->random[i] == this->selected[i]) guessed++;
	}

	return guessed;
}

void Lotto::randomize() {
	for (int i = 0; i < AMOUNT; i++) {
		this->random[i] = randomInt(0, 49);
	}
	this->hasRandomized = true;
}