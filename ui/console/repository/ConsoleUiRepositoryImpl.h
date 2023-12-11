//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUIREPOSITORYIMPL_H
#define CPP_GTEST_CONSOLEUIREPOSITORYIMPL_H

#include <memory>

#include "ConsoleUiRepository.h"

class ConsoleUiRepositoryImpl : public ConsoleUiRepository {
public:
    void getSession() override;
};


#endif //CPP_GTEST_CONSOLEUIREPOSITORYIMPL_H
