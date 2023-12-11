//
// Created by eddi on 23. 12. 11.
//

#ifndef CPP_GTEST_ACCOUNTLOGINREQUEST_H
#define CPP_GTEST_ACCOUNTLOGINREQUEST_H

#include <string>
#include <vector>
#include "../../entity/Account.h"


class AccountLoginRequest {
private:
    std::string account_id;
    std::string password;

public:
    AccountLoginRequest(const std::string& account_id, const std::string& password );
    std::string getAccountId();
    std::string getPassword();
};


#endif //CPP_GTEST_ACCOUNTLOGINREQUEST_H
