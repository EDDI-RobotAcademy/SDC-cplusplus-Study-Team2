//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUICONTROLLER_H
#define CPP_GTEST_CONSOLEUICONTROLLER_H

#include <memory>
#include <vector>
#include <functional>

#include "../service/ConsoleUiService.h"
#include "ConsoleUiControllerCommand.h"

class ConsoleUiController {

private:
    std::shared_ptr<ConsoleUiService> consoleUiService;

    typedef std::function<void(void)> ConsoleBoardCommandType;
    ConsoleBoardCommandType consoleBoardCommandTable[NUM_BOARD_COMMANDS];

public:
    ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService);

//    void uiAccountLogin();
//    void uiAccountRegister();
//    void uiAccountExit();

    void uiBoardWrite();
    void uiBoardEdit();

    void uiEngine();

    using CommandFunction = void (*)(ConsoleUiController*, void*);
    std::vector<CommandFunction> commandTable;

};


#endif //CPP_GTEST_CONSOLEUICONTROLLER_H
