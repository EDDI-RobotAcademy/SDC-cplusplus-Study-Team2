//
// Created by eddi on 23. 11. 30.
//

#include "BoardServiceImpl.h"
#include "../entity/manager/BoardManager.h"

#include <iostream>

BoardServiceImpl::BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository) : boardRepository(boardRepository) { }

std::vector<ResponseList> BoardServiceImpl::list()
{
   // std::cout << "BoardService: 리스트 출력!" << std::endl;
    std::vector<ResponseList> response;
    int count = boardManager.getBoardList().size();
    for(int i = 0; i < count; i++){
        Board board = boardManager.getBoardList()[i];
        ResponseList _response(board.getBoardUID(), board.getTitle(), board.getWriter());
        response.push_back(_response);
    }
    for (const auto& board : boardManager.getBoardList()) {
        board.printBoardInfo();
    }
    return response;
}

ResponseRead *BoardServiceImpl::read(int board_id) {
   // std::cout << "BoardService: 게시물 읽기!" << std::endl;

    Board boardToRead = boardRepository->findPost(board_id);
    //BoardAdapter *adapter = new BoardAdapter();

//    std::cout << "제목: " << boardToRead.getTitle() << "\n작성자: " << boardToRead.getWriter() << /*<< adapter->requestAccountNameToAccountAdapter(boardToRead.getWriter()) <<*/
//    "\n내용: " << boardToRead.getContent() << std::endl;
    ResponseRead *response = new ResponseRead(boardToRead.getTitle(), boardToRead.getWriter(), boardToRead.getContent());
    return response;
}

void BoardServiceImpl::write(BoardRequestFormWrite _request) {
   // std::cout << "BoardService: 게시물 쓰기!" << std::endl;
    boardRepository->writePost(_request.requestToBoardForDB());
}

void BoardServiceImpl::edit(BoardRequestFormEdit _request) {
 //   std::cout << "BoardService: 게시물 수정!" << std::endl;
    boardRepository->editPost(_request);

}

void BoardServiceImpl::remove(int _boardUid) {
   // std::cout << "BoardService: 게시물 삭제!" << std::endl;
    boardRepository->removePost(_boardUid);

}

ResponseFoundPostForEdit BoardServiceImpl::findPostToEdit(int boardId) {
   // std::cout << "BoardService: 게시물 찾기!" << std::endl;
    Board board = boardRepository->findPost(boardId);
    ResponseFoundPostForEdit response(board.getTitle(), board.getContent());
    return response;
}

void BoardServiceImpl::update() {
    boardManager.setBoardList(boardRepository->findAll());

}

