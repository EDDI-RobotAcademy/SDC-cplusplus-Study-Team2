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

#include "request/RequestToEdit.h"
#include "request/RequestToWrite.h"
#include "response/ResponseFoundPostForEdit.h"
#include "response/ResponseList.h"
#include "response/ResponseRead.h"

class BoardController {
private:
    std::shared_ptr<BoardService> boardService;
    //BoardService* boardService;

public:
    BoardController(std::shared_ptr<BoardService> boardService);

    std::vector<ResponseList> boardList();
    ResponseRead boardRead(int);
    bool boardWrite(RequestToWrite*);
    bool boardEdit(RequestToEdit);
    ResponseFoundPostForEdit findPostToEdit(int);
    bool boardRemove(int);
};


#endif //CLASS_TEST_BOARDCONTROLLER_H
