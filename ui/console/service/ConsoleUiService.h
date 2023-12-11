//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUISERVICE_H
#define CPP_GTEST_CONSOLEUISERVICE_H

#include "../../../board/controller/request/RequestToWrite.h"
#include "../../../board/controller/request/RequestToEdit.h"

class ConsoleUiService {
public:
    virtual ~ConsoleUiService() = default;

    virtual void makeUiAccountPrint() = 0;
    virtual void makeUiBoardPrint() = 0;

    virtual int makeRequestToReadForm() = 0;
    virtual RequestToWrite *makeRequestToWriteForm() = 0;
    virtual RequestToEdit *makeRequestToEditForm() = 0;
    virtual int makeRequestToDeleteForm() = 0;
};

#endif //CPP_GTEST_CONSOLEUISERVICE_H
