//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_RESPONSEREAD_H
#define CPP_GTEST_RESPONSEREAD_H


#include <string>

class ResponseRead {
private:
    std::string title;
    std::string writer;
    std::string content;
public:
    ResponseRead(std::string, std::string, std::string);
    ~ResponseRead() = default;
    std::string getTitle();
    std::string getWriter();
    std::string getContent();


};


#endif //CPP_GTEST_RESPONSEREAD_H
