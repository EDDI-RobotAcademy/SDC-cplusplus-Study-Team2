//
// Created by eddi on 23. 12. 4.
//


#ifndef CLASS_TEST_CONSOLEUISERVICEIMPL_H
#define CLASS_TEST_CONSOLEUISERVICEIMPL_H

#include <string>
#include <vector>
#include "ConsoleUiService.h"
#include "../../../board/entity/Board.h"

class ConsoleUiServiceImpl : public ConsoleUiService {
public:
    ConsoleUiServiceImpl();
    Board *creatPost();
    //void postExit ();

    ~ConsoleUiServiceImpl();

    std::string writer;
    std::string content;
    std::string title;
};

#endif //CLASS_TEST_CONSOLEUISERVICEIMPL_H