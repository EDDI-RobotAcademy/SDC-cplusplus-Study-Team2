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
    BoardManager() {}
    BoardManager(const BoardManager& ref) {}
    BoardManager& operator=(const BoardManager& ref) {}
    ~BoardManager() {}
    static std::shared_ptr<BoardController> boardController;
    static std::vector<Board> boardList;
    static unsigned int nextUid;
    static void printBoardList();
public:
    static BoardManager& getInstance(std::shared_ptr<BoardController> _boardController);
    static void startBoard();
    static unsigned int getNextUid();
    static std::vector<Board> getBoardList();


};


#endif //CLASS_TEST_BOARDMANAGER_H
