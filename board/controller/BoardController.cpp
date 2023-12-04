//
// Created by eddi on 23. 11. 30.
//

#include "BoardController.h"

#include <iostream>
#include <vector>

                                // shared_ptr: sharing 되고 있는 포인터
BoardController::BoardController(std::shared_ptr<BoardService> boardService) : boardService(boardService) { }

std::vector<Board> BoardController::boardList()
{
    std::cout << "BoardController: 게시물 리스트 출력!" << std::endl;

    //boardService->list();

    return boardService->list();
}

Board BoardController::boardRead(int uid) {

    std::cout << "BoardController: 게시물 출력!" << std::endl;

    return boardService->read(uid);
}

void BoardController::boardWrite(BoardRequestFormWrite _request) {

    std::cout << "BoardController: 게시물 작성!" << std::endl;
    boardService->write(_request);
}

