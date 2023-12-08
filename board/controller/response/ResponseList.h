//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_RESPONSELIST_H
#define CPP_GTEST_RESPONSELIST_H


#include <string>

// boardId, title, writer
class ResponseList {
private:
    int boardId;
    std::string title;
    std::string writer;
public:
    ResponseList(int, std::string, std::string );
    ~ResponseList() = default;
    int getBoardId();
    std::string getTitle();
    std::string getWriter();

};


#endif //CPP_GTEST_RESPONSELIST_H
