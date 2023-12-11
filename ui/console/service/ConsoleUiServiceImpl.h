//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUISERVICEIMPL_H
#define CPP_GTEST_CONSOLEUISERVICEIMPL_H

#include <memory>

#include "ConsoleUiService.h"

class ConsoleUiServiceImpl : public ConsoleUiService {

public:
    ConsoleUiServiceImpl();

    void makeUiAccountPrint() override;
    void makeUiBoardPrint() override;

    AccountLoginRequestForm *makeAccountRequestForm() override;

    int makeRequestToReadForm() override;
    RequestToWrite *makeRequestToWriteForm() override;
    RequestToEdit *makeRequestToEditForm() override;
    int makeRequestToDeleteForm() override;
};


#endif //CPP_GTEST_CONSOLEUISERVICEIMPL_H
