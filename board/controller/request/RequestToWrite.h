//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_REQUESTTOWRITE_H
#define CPP_GTEST_REQUESTTOWRITE_H


#include <string>
#include "../../service/request/BoardRequestFormWrite.h"

class RequestToWrite {
private:
    std::string title;
    std::string writer;
    std::string content;
public:
    RequestToWrite(std::string, std::string, std::string);
    ~RequestToWrite()=default;
    BoardRequestFormWrite requestForService();


};


#endif //CPP_GTEST_REQUESTTOWRITE_H
