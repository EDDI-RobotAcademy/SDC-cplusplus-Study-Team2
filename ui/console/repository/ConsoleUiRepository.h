//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUIREPOSITORY_H
#define CPP_GTEST_CONSOLEUIREPOSITORY_H

class ConsoleUiRepository {
public:
    virtual ~ConsoleUiRepository() = default;
    virtual void getSession() = 0;
};

#endif //CPP_GTEST_CONSOLEUIREPOSITORY_H
