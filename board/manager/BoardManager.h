//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_BOARDMANAGER_H
#define CLASS_TEST_BOARDMANAGER_H


#include <memory>

#include "../controller/BoardController.h"
#include "../entity/Board.h"

class BoardManager {
private:
    std::shared_ptr<BoardController> boardController;
    std::vector<Board> boardList;
    unsigned int boardCount;
public:
    BoardManager(std::shared_ptr<BoardController> boardController);
    void startBoard();
    void printBoardList();
};


#endif //CLASS_TEST_BOARDMANAGER_H
