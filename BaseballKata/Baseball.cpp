#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GameResult {
public:
	void setResult(bool _solved, int _strike, int _ball) {
		solved = _solved;
		strike = _strike;
		ball = _ball;
	}
	bool getSolved() {
		return solved;
	}
	int getStrike()
	{
		return strike;
	}
	int getBall() {
		return ball;
	}

private:
	bool solved;
	int strike;
	int ball;
};

class Baseball {
public:
	void setNum(const string num)
	{
		answer = num;
	}

	GameResult* doGame(const string& guessNum)
	{
		int strikes = 0;
		int balls = 0;

		for (int i = 0; i < (int)answer.size(); i++) {
			if (answer[i] == guessNum[i]) {
				strikes++;
			} else {
				for (int j = 0; j < (int)answer.size(); j++) {
					if (answer[j] == guessNum[i]) {
						balls++;
						break;
					}
				}
			}
		}

		GameResult* result = new GameResult();
		result->setResult(strikes == 3, strikes, balls);
		return result;
	}

private:
	string answer = "111";
};