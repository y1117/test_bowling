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
