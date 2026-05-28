#include <string>
#include <stdexcept>
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
		validate(num);
		answer = num;
	}

	GameResult* doGame(const string& guessNum)
	{
		validate(guessNum);

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

	void validate(const string& num)
	{
		if (num.size() != 3)
			throw invalid_argument("number must be 3 digits");
		for (char c : num)
			if (!isdigit(c))
				throw invalid_argument("number must contain only digits");
		for (int i = 0; i < (int)num.size(); i++)
			for (int j = i + 1; j < (int)num.size(); j++)
				if (num[i] == num[j])
					throw invalid_argument("number must not contain duplicate digits");
	}
};