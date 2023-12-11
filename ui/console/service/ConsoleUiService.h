//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUISERVICE_H
#define CPP_GTEST_CONSOLEUISERVICE_H

#include "../../../board/controller/request/RequestToWrite.h"

class ConsoleUiService {
public:
    virtual ~ConsoleUiService() = default;
    virtual void makeUiPrint() = 0;

    virtual RequestToWrite *makeRequestToWriteForm() = 0;
};

#endif //CPP_GTEST_CONSOLEUISERVICE_H
