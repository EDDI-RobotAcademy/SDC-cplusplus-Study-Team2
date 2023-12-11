//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUISERVICEIMPL_H
#define CPP_GTEST_CONSOLEUISERVICEIMPL_H

#include <memory>

#include "ConsoleUiService.h"
#include "../repository/ConsoleUiRepository.h"

class ConsoleUiServiceImpl : public ConsoleUiService {

private:
    std::shared_ptr<ConsoleUiRepository> consoleUiRepository;

public:
    ConsoleUiServiceImpl();
    ConsoleUiServiceImpl(std::shared_ptr<ConsoleUiRepository> consoleUiRepository);

    void makeUiPrint() override;
};


#endif //CPP_GTEST_CONSOLEUISERVICEIMPL_H
