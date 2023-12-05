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
    unsigned int nextUid;
    void printBoardList();
public:
    BoardManager(std::shared_ptr<BoardController> _boardController);
    ~BoardManager(){}
    void startBoard();
    unsigned int getNextUid();
    std::vector<Board> getBoardList();


};
extern BoardManager boardManager;

#endif //CLASS_TEST_BOARDMANAGER_H
