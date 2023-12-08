//
// Created by eddi on 23. 12. 8.
//

#include "ResponseList.h"


ResponseList::ResponseList(int _boardId, std::string _title, std::string _writer)
: boardId(_boardId), title(_title), writer(_writer){}

int ResponseList::getBoardId() {
    return boardId;
}

std::string ResponseList::getTitle() {
    return title;
}

std::string ResponseList::getWriter() {
    return writer;
}
