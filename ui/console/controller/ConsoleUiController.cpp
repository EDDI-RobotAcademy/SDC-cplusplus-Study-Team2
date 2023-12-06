/*
//
// Created by junghwan on 23. 12. 6.
//

#include "ConsoleUiController.h"

ConsoleUiController::ConsoleUiController(std::shared_ptr<BoardService> boardService) : boardService(boardService) { }

std::vector<Board> BoardController::boardList()
{
    std::cout << "BoardController: 게시물 리스트 출력!" << std::endl;

    //boardService->list();

    return boardService->list();
}
*/
