//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTREGISTERRESPONSEFORM_H
#define CPP_GTEST_ACCOUNTREGISTERRESPONSEFORM_H

class AccountRegisterResponseForm {
private:
    bool RegisterSuccess;

public:
    AccountRegisterResponseForm (bool RegisterSuccess);
    bool getRegisterSuccess();

};

#endif //CPP_GTEST_ACCOUNTREGISTERRESPONSEFORM_H
