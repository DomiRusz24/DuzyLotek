#ifndef CONSOLEOPTION_H
#define CONSOLEOPTION_H

#include <string>

using namespace std;

template<typename T>
struct ConsoleOption {
	string text;
	T value;
};


#endif
