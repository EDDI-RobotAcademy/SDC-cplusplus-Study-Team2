//
// Created by eddi on 23. 12. 8.
//

#include "RequestToEdit.h"

RequestToEdit::RequestToEdit
(int _boardUid, std::string _title, std::string _content) : boardUid(_boardUid), title(_title), content(_content){}

BoardRequestFormEdit RequestToEdit::requestForService() {
    BoardRequestFormEdit request(boardUid, title, content);
    return request;
}
