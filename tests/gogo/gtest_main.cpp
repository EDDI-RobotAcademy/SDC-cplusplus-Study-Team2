#include <gtest/gtest.h>

#include "../../board/entity/Board.h"

TEST(boardEntity, createBoardEntity)
{
    Board *board = new Board("hi", "hi",  "why");
    board->printBoardInfo();

    EXPECT_NE(board, nullptr);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}