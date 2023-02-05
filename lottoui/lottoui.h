#ifndef LOTTOUI_H
#define LOTTOUI_H

#include "../ui/consolegui.h"
#include "../lotto/lotto.h"

enum LottoButton {
	INPUT = 0,
	GENERATE = 1,
	CHECK = 2,
	LEAVE = 3
};

class LottoUI : public ConsoleGUI<LottoButton> {
public:
	LottoUI();
protected:
	string onChoose(LottoButton option) override;
	vector<ConsoleOption<LottoButton>> generateOptions() override;
private:
	Lotto lotto;
	string input();
	string generate();
	string check();
};

#endif