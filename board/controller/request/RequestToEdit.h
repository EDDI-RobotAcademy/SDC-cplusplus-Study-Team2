//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_REQUESTTOEDIT_H
#define CPP_GTEST_REQUESTTOEDIT_H

#include <string>
#include "../../service/request/BoardRequestFormEdit.h"

class RequestToEdit {
private:
    int boardUid;
    std::string title;
    std::string content;
public:
    RequestToEdit(int, std::string, std::string);
    ~RequestToEdit() = default;
    BoardRequestFormEdit requestForService();
};


#endif //CPP_GTEST_REQUESTTOEDIT_H
