//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTSERVICE_H
#define YOUNGCHANHWANG_ACCOUNTSERVICE_H

#include <vector>
#include "response/AccountResponse.h"
#include "request/AccountLoginRequest.h"


class AccountService {
public:
    virtual ~AccountService() = default;
    virtual std::vector<AccountResponse> regi() = 0;
    virtual bool login(AccountLoginRequest *request) = 0;

};

#endif //YOUNGCHANHWANG_ACCOUNTSERVICE_H
