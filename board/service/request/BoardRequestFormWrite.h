//
// Created by lohen on 23. 12. 4.
//

#ifndef CLASS_TEST_BOARDREQUESTFORMWRITE_H
#define CLASS_TEST_BOARDREQUESTFORMWRITE_H


#include <string>
#include "../../entity/Board.h"

class BoardRequestFormWrite {
private:

    std::string title;
    std::string writer;
    std::string content;
public:
    BoardRequestFormWrite(std::string, std::string, std::string);
    Board requestToBoardForDB();
    ~BoardRequestFormWrite();
};


#endif //CLASS_TEST_BOARDREQUESTFORMWRITE_H
