//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDCONTROLLER_H
#define CLASS_TEST_BOARDCONTROLLER_H


#include <memory>
#include <vector>

#include "../service/BoardService.h"
#include "../entity/Board.h"
#include "../service/request/BoardRequestFormWrite.h"
#include "../service/request/BoardRequestFormEdit.h"

class BoardController {
private:
    std::shared_ptr<BoardService> boardService;
    //BoardService* boardService;

public:
    BoardController(std::shared_ptr<BoardService> boardService);

    std::vector<Board> boardList();
    Board boardRead(int);
    void boardWrite(BoardRequestFormWrite);
    void boardEdit(BoardRequestFormEdit);
};


#endif //CLASS_TEST_BOARDCONTROLLER_H
