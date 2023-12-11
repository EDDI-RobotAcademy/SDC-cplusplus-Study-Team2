//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTLOGINRESPONSE_H
#define CPP_GTEST_ACCOUNTLOGINRESPONSE_H

#include "../../controller/response/AccountLoginResponseForm.h"

class AccountLoginResponse{
private:
    bool isLoginSuccess;

public:
    AccountLoginResponse( bool isLoginSuccess);
    AccountLoginResponseForm *toResponseForm();


};
#endif //CPP_GTEST_ACCOUNTLOGINRESPONSE_H
