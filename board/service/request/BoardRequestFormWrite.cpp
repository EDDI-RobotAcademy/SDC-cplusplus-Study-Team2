//
// Created by lohen on 23. 12. 4.
//

#include <iostream>
#include "BoardRequestFormWrite.h"

#include "../../manager/BoardManager.h"

BoardRequestFormWrite::BoardRequestFormWrite(unsigned int _accountUid, std::string _title, std::string _content) :
            accountUid(_accountUid), title(_title), content(_content) {}


BoardRequestFormWrite::~BoardRequestFormWrite() {
    std::cout << "작성 요청 다 했으니 꺼져!" << std::endl;
}

Board BoardRequestFormWrite::requestToBoardForDB() {
    unsigned int boardUid = BoardManager::getNextUid();
    Board request(boardUid, title, accountUid, content);
    return request;
}


