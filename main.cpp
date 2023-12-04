#include <iostream>
#include <memory>
#include "board/controller/BoardController.h"
#include "board/service/BoardServiceImpl.h"
#include "board/repository/BoardRepository.h"
#include "board/repository/BoardRepositoryImpl.h"

int main() {


//    BoardRepository *boardRepository = new BoardRepositoryImpl();
//    BoardService* boardService = new BoardServiceImpl();
// make::shared : 공유 포인터 선언
// 다른곳에서 헤더참조만 하면 언제든 사용 할 수 있음
    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardList();

    return 0;
}
