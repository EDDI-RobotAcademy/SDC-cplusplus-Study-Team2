//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_BOARDRESPONSEREAD_H
#define CLASS_TEST_BOARDRESPONSEREAD_H


#include <string>

class BoardResponseRead {
public:
    std::string title;
    std::string content;
    unsigned int writer_uid;
    ~BoardResponseRead();

};


#endif //CLASS_TEST_BOARDRESPONSEREAD_H
