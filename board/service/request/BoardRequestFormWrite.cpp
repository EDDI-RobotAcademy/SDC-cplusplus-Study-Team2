//
// Created by lohen on 23. 12. 4.
//

#include <iostream>
#include "BoardRequestFormWrite.h"

#include "../../entity/manager/BoardManager.h"
#include "../BoardServiceImpl.h"
#include "../../repository/BoardRepositoryImpl.h"



BoardRequestFormWrite::BoardRequestFormWrite(std::string _title, int _accountUid, std::string _content) :
            accountUid(_accountUid), title(_title), content(_content) {}


BoardRequestFormWrite::~BoardRequestFormWrite() {
    std::cout << "작성 요청 다 했으니 꺼져!" << std::endl;
}

Board BoardRequestFormWrite::requestToBoardForDB() {
    int boardUid = boardManager.getNextUid();
    Board board(boardUid, title, accountUid, content);
    return board;
}