//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTREGISTERREQUESTFORM_H
#define CPP_GTEST_ACCOUNTREGISTERREQUESTFORM_H

#include <string>
#include "../../service/request/AccountRegisterRequest.h"


class AccountRegisterRequestForm {
private:
    std::string account_id;
    std::string password;

public:
    AccountRegisterRequestForm(const std::string& account_id, const std::string& password);
    AccountRegisterRequest *toAccountRegisterRequest();


};

#endif //CPP_GTEST_ACCOUNTREGISTERREQUESTFORM_H
