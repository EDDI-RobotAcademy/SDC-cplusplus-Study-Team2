//
// Created by lohen on 23. 12. 4.
//

#include <iostream>
#include "BoardRequestFormEdit.h"


BoardRequestFormEdit::BoardRequestFormEdit(int _boardUid, std::string _title, std::string _content) :
            boardUid(_boardUid), title(_title), content(_content) {}


BoardRequestFormEdit::~BoardRequestFormEdit() {
    std::cout << "수정 요청 다 했으니 꺼져!" << std::endl;
}

std::string BoardRequestFormEdit::getTitle() {
    return title;
}

std::string BoardRequestFormEdit::getContent() {
    return content;
}

int BoardRequestFormEdit::getBoardUid() {
    return boardUid;
}

