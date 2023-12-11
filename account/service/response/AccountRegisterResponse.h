//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTREGISTERRESPONSE_H
#define CPP_GTEST_ACCOUNTREGISTERRESPONSE_H

#include "../../controller/response/AccountRegisterResponseForm.h"


class AccountRegisterResponse{
private:
    bool isRegisterSuccess;

public:
    AccountRegisterResponse( bool isRegisterSuccess);
    AccountRegisterResponseForm *toResponseForm();


};

#endif //CPP_GTEST_ACCOUNTREGISTERRESPONSE_H
