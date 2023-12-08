//
// Created by lohen on 23. 12. 4.
//

#include <iostream>
#include "BoardRequestFormWrite.h"

#include "../../entity/manager/BoardManager.h"
#include "../BoardServiceImpl.h"
#include "../../repository/BoardRepositoryImpl.h"



BoardRequestFormWrite::BoardRequestFormWrite(std::string _title,  std::string _writer, std::string _content) :
            writer(_writer), title(_title), content(_content) {}


BoardRequestFormWrite::~BoardRequestFormWrite() {
    std::cout << "작성 요청 다 했으니 꺼져!" << std::endl;
}

Board BoardRequestFormWrite::requestToBoardForDB() {
    int boardUid = boardManager.getNextUid();
    Board board(boardUid, title, writer, content);
    return board;
}