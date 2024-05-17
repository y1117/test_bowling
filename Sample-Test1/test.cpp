#include "pch.h"
#include "../240517_bowling/bowling.cpp"

TEST(GameTest, AllZeroPoints) {
    Game game;
    for (int i = 0; i < 20; ++i) {
        game.Roll(0);
    }
    EXPECT_EQ(0, game.Score());
}