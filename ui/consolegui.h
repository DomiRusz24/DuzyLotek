#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include "consoleoption.h"
#include <vector>
#include <iostream>

using namespace std;

inline string repeat(string single, int amount) {
	string str = "";

	for (int i = 0; i < amount; i++) {
		str += single;
	}

	return str;
}

template<class T>
class ConsoleGUI {
public:
	vector<ConsoleOption<T>> options;
	bool run = true;

	ConsoleGUI(string text) {
		this->text = text;
	}

	void display() {

		this->options = this->generateOptions();

		string optionsString = " ";

		for (ConsoleOption<T> option : this->options) {
			optionsString += "[" + option.text + "]   ";
		}

		int dialogLength = this->text.length() + 2;

		if (optionsString.length() - 4 > dialogLength) {
			dialogLength = optionsString.length() - 4;
		}

		string line = "+" + repeat("-", dialogLength) + "+";

		cout << line << endl << endl;
		cout << repeat(" ", dialogLength / 2 - this->text.length() / 2) << this->text << endl << endl;
		cout << repeat(" ", dialogLength / 2 - optionsString.length() / 2) << optionsString;
		cout << endl << line << endl << endl;

		this->chooseOption();
	}
private:
	string text;

	void chooseOption() {
		string selected;
		cout << "Podaj opcje: ";
		cin >> selected;

		for (ConsoleOption<T> option : this->options) {
			if (option.text == selected) {
				this->text = this->onChoose(option.value);
				if (this->run) this->display();
				return;
			}
		}

		cout << "Nie poprawna opcja, sprobuj jeszcze raz!" << endl << endl;
		this->chooseOption();
	}
protected:
	virtual vector<ConsoleOption<T>> generateOptions() = 0;

	virtual string onChoose(T option) = 0;
};


#endif