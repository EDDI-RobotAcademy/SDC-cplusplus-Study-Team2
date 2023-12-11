//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTLOGINRESPONSEFORM_H
#define CPP_GTEST_ACCOUNTLOGINRESPONSEFORM_H

class AccountLoginResponseForm {
private:
    bool LoginSuccess;

public:
    AccountLoginResponseForm (bool LoginSuccess);
    bool getLoginSuccess();

};

#endif //CPP_GTEST_ACCOUNTLOGINRESPONSEFORM_H
