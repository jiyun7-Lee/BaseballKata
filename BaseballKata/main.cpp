#include "gmock/gmock.h"
#include "Baseball.cpp"
using namespace testing;

class BaseballFixture : public Test {
protected:
	Baseball* game;
	void SetUp() override {
		game = new Baseball();
		game->setNum("123");
	}
	void TearDown() override {
		delete game;
	}
};

TEST_F(BaseballFixture, NoMatch) {
	GameResult* result = game->doGame("456");
	EXPECT_EQ(false, result->getSolved());
	EXPECT_EQ(0, result->getStrike());
	EXPECT_EQ(0, result->getBall());
}

TEST_F(BaseballFixture, OneStrike) {
	GameResult* result = game->doGame("145");
	EXPECT_EQ(false, result->getSolved());
	EXPECT_EQ(1, result->getStrike());
	EXPECT_EQ(0, result->getBall());
}

TEST_F(BaseballFixture, OneBall) {
	GameResult* result = game->doGame("415");
	EXPECT_EQ(false, result->getSolved());
	EXPECT_EQ(0, result->getStrike());
	EXPECT_EQ(1, result->getBall());
}

TEST_F(BaseballFixture, ThreeBalls) {
	GameResult* result = game->doGame("312");
	EXPECT_EQ(false, result->getSolved());
	EXPECT_EQ(0, result->getStrike());
	EXPECT_EQ(3, result->getBall());
}

TEST_F(BaseballFixture, OneStrikeTwoBalls) {
	GameResult* result = game->doGame("132");
	EXPECT_EQ(false, result->getSolved());
	EXPECT_EQ(1, result->getStrike());
	EXPECT_EQ(2, result->getBall());
}

TEST_F(BaseballFixture, ThreeStrikesWin) {
	GameResult* result = game->doGame("123");
	EXPECT_EQ(true, result->getSolved());
	EXPECT_EQ(3, result->getStrike());
	EXPECT_EQ(0, result->getBall());
}

TEST_F(BaseballFixture, ThrowWhenGuessHasDuplicateDigits) {
	EXPECT_THROW(game->doGame("112"), invalid_argument);
	EXPECT_THROW(game->doGame("111"), invalid_argument);
}

TEST_F(BaseballFixture, ThrowWhenGuessContainsNonDigit) {
	EXPECT_THROW(game->doGame("12a"), invalid_argument);
	EXPECT_THROW(game->doGame("!23"), invalid_argument);
}

TEST_F(BaseballFixture, ThrowWhenGuessIsNot3Digits) {
	EXPECT_THROW(game->doGame("12"), invalid_argument);
	EXPECT_THROW(game->doGame("1234"), invalid_argument);
}

TEST(BaseballTest, ThrowWhenAnswerHasDuplicateDigits) {
	Baseball* game = new Baseball();
	EXPECT_THROW(game->setNum("112"), invalid_argument);
	EXPECT_THROW(game->setNum("111"), invalid_argument);
}

TEST(BaseballTest, ThrowWhenAnswerContainsNonDigit) {
	Baseball* game = new Baseball();
	EXPECT_THROW(game->setNum("12a"), invalid_argument);
	EXPECT_THROW(game->setNum("!23"), invalid_argument);
}

TEST(BaseballTest, ThrowWhenAnswerIsNot3Digits) {
	Baseball* game = new Baseball();
	EXPECT_THROW(game->setNum("12"), invalid_argument);
	EXPECT_THROW(game->setNum("1234"), invalid_argument);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
