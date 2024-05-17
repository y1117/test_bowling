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
    game.Roll(5); // spare
    game.Roll(3);
    for (int i = 3; i < TOTAL_ROLL_TRY; ++i) {
        game.Roll(0);
    }
    EXPECT_EQ(10+3+3, game.Score());
}
TEST_F(GameFixture, Strike1_OthersAllZeroPoints) {
    game.Roll(10); // strike
    game.Roll(3);
    game.Roll(4);
    for (int i = 4; i < TOTAL_ROLL_TRY; ++i) {
        game.Roll(0);
    }
    EXPECT_EQ(10+7+7, game.Score());
}
TEST_F(GameFixture, AllStrike) {
    for (int i = 0; i < 12; ++i) {
        game.Roll(10);
    }
    EXPECT_EQ(300, game.Score());
}
TEST_F(GameFixture, sampleGame) {
    game.Roll(1);
    game.Roll(4);
    game.Roll(4);
    game.Roll(5);
    game.Roll(6);
    game.Roll(4);
    game.Roll(5);
    game.Roll(5);
    game.Roll(10);
    game.Roll(0);
    game.Roll(1);
    game.Roll(7);
    game.Roll(3);
    game.Roll(6);
    game.Roll(4);
    game.Roll(10);
    game.Roll(2);
    game.Roll(8);
    game.Roll(6);
    EXPECT_EQ(133, game.Score());
}
