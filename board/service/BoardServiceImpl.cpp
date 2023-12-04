//
// Created by eddi on 23. 11. 30.
//

#include "BoardServiceImpl.h"
#include <iostream>

BoardServiceImpl::BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository) : boardRepository(boardRepository) { }

std::vector<Board> BoardServiceImpl::list()
{
    std::cout << "BoardService: 리스트 출력!" << std::endl;

    return boardRepository->findAll();
}

Board BoardServiceImpl::read(int uid) {
    std::cout << "BoardService: 게시물 읽기!" << std::endl;

    return boardRepository->findPost(uid);
}

void BoardServiceImpl::write(BoardRequestFormWrite _request) {
    std::cout << "BoardService: 게시물 쓰기!" << std::endl;
    boardRepository->writePost(_request.requestToBoardForDB());
}

void BoardServiceImpl::edit() {
    std::cout << "BoardService: 게시물 수정!" << std::endl;
}

void BoardServiceImpl::remove() {
    std::cout << "BoardService: 게시물 삭제!" << std::endl;
}
