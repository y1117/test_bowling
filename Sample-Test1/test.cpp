#include "pch.h"
#include "../240517_bowling/bowling.cpp"

class GameFixture : public testing::Test {
public:
    Game game;
};

const int TOTAL_ROLL_TRY = 20;
TEST_F(GameFixture, AllZeroPoints) {
    for (int i = 0; i < TOTAL_ROLL_TRY; ++i) {
        game.Roll(0);
    }
    EXPECT_EQ(0, game.Score());
}
TEST_F(GameFixture, All1Points) {
    for (int i = 0; i < TOTAL_ROLL_TRY; ++i) {
        game.Roll(1);
    }
    EXPECT_EQ(20, game.Score());
}
TEST_F(GameFixture, Spare1_OthersAllZeroPoints) {
    game.Roll(5);
    game.Roll(5);
    game.Roll(3);
    for (int i = 3; i < TOTAL_ROLL_TRY; ++i) {
        game.Roll(0);
    }
    EXPECT_EQ(10+3+3, game.Score());
}



