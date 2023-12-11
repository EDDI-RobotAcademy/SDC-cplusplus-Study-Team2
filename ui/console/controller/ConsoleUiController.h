//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUICONTROLLER_H
#define CPP_GTEST_CONSOLEUICONTROLLER_H

#include <memory>
#include <vector>

#include "../service/ConsoleUiService.h"

class ConsoleUiController {

private:
    std::shared_ptr<ConsoleUiService> consoleUiService;

public:
    ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService);

//    void uiAccountLogin();
//    void uiAccountRegister();
//    void uiAccountExit();

    void uiBoardWrite();

    void uiEngine();

    using CommandFunction = void (*)(ConsoleUiController*, void*);
    std::vector<CommandFunction> commandTable;

};


#endif //CPP_GTEST_CONSOLEUICONTROLLER_H
