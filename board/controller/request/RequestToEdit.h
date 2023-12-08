//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_REQUESTTOEDIT_H
#define CPP_GTEST_REQUESTTOEDIT_H

#include <string>
#include "../../service/request/BoardRequestFormEdit.h"

class RequestToEdit {
public:
    int boardUid;
    std::string title;
    std::string content;
    RequestToEdit(int, std::string, std::string);
    ~RequestToEdit() = default;
};


#endif //CPP_GTEST_REQUESTTOEDIT_H
