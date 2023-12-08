//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_RESPONSEFOUNDPOSTFOREDIT_H
#define CPP_GTEST_RESPONSEFOUNDPOSTFOREDIT_H


#include <string>

class ResponseFoundPostForEdit {
private:
    std::string title;
    std::string content;
public:
    ResponseFoundPostForEdit(std::string, std::string );
    ~ResponseFoundPostForEdit() = default;
};


#endif //CPP_GTEST_RESPONSEFOUNDPOSTFOREDIT_H
