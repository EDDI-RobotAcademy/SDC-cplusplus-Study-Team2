//
// Created by lohen on 23. 12. 4.
//

#ifndef CLASS_TEST_BOARDREQUESTFORMEDIT_H
#define CLASS_TEST_BOARDREQUESTFORMEDIT_H


#include <string>
#include "../../entity/Board.h"

class BoardRequestFormEdit {
private:
    int boardUid;
    std::string title;
    std::string content;
public:
    BoardRequestFormEdit(int, std::string, std::string);
    ~BoardRequestFormEdit();
    std::string getTitle();
    std::string getContent();
    int getBoardUid();
};


#endif //CLASS_TEST_BOARDREQUESTFORMEDIT_H
