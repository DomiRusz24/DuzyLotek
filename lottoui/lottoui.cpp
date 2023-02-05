#include "lottoui.h"
#include <string>

using namespace std;

LottoUI::LottoUI() : ConsoleGUI("Prosze wylosowac liczbe") {

}

string LottoUI::onChoose(LottoButton option) {
	switch (option) {
		case CHECK:
			return this->check();
		case GENERATE:
			return this->generate();
		case INPUT:
			return this->input();
		case LEAVE:
			this->run = false;
			return "";
	}

	return "Incorrect option";
}

vector<ConsoleOption<LottoButton>> LottoUI::generateOptions() {
	vector<ConsoleOption<LottoButton>> options;
	options.push_back(ConsoleOption<LottoButton> { "Wylosuj", GENERATE });
	options.push_back(ConsoleOption<LottoButton> { "Wprowadz", INPUT });
	if (this->lotto.hasRandomized && this->lotto.hasSelected) {
		options.push_back(ConsoleOption<LottoButton> { "Sprawdz", CHECK });
	}
	options.push_back(ConsoleOption<LottoButton> { "Wyjdz", LEAVE });

	return options;
}

string LottoUI::input() {

	cout << endl << endl;
	lotto.promptUser();

	string s = "Wprowadzono liczby: ";

	int* selected = this->lotto.selected;

	for (int i = 0; i < AMOUNT - 1; i++) {
		s += to_string(selected[i]) + ", ";
	}
	s += to_string(selected[AMOUNT - 1]) + ".";

	if (!this->lotto.hasRandomized) {
		s += " Teraz jeszcze wystarczy wylosowac.";
	}


	return s;
}

string LottoUI::generate() {

	cout << endl << endl;
	lotto.randomize();

	string s = "Wylosowano liczby!";

	if (!this->lotto.hasSelected) {
		s += " Teraz jeszcze wystarczy swoje liczby wprowadzic.";
	}

	return s;
}

string LottoUI::check() {

	string s = "Twoje liczby: ";

	int* selected = this->lotto.selected;
	int* random = this->lotto.random;

	for (int i = 0; i < AMOUNT - 1; i++) {
		s += to_string(selected[i]) + ", ";
	}
	s += to_string(selected[AMOUNT - 1]) + ". Wylosowane liczby: ";

	for (int i = 0; i < AMOUNT - 1; i++) {
		s += to_string(random[i]) + ", ";
	}
	s += to_string(random[AMOUNT - 1]) + ". Odgadles: " + to_string(this->lotto.check()) + " liczb.";

	return s;
}