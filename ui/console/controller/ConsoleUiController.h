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
    void startApplication();
    int getUserCommandInput();
    typedef std::function<void(void)> ConsoleBoardCommandType;
    ConsoleBoardCommandType consoleBoardCommandTable[NUM_BOARD_COMMANDS];
    typedef std::function<void(void)> ConsoleAccountCommandType;
    ConsoleAccountCommandType consoleAccountCommandTable[NUM_ACCOUNT_COMMANDS];
    void initTables();
public:
    ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService);

    void uiAccountLogin();
    void uiAccountRegister();

    void uiBoardRead();
    void uiBoardWrite();
    void uiBoardEdit();
    void uiBoardRemove();

    void uiExit();

    void uiEngine();

    using CommandFunction = void (*)(ConsoleUiController*, void*);
    std::vector<CommandFunction> commandTable;

};

extern bool isLogin;
extern bool isQuit;


#endif //CPP_GTEST_CONSOLEUICONTROLLER_H
