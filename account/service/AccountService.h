//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTSERVICE_H
#define YOUNGCHANHWANG_ACCOUNTSERVICE_H

#include <vector>
#include "request/AccountRegisterRequest.h"
#include "request/AccountLoginRequest.h"


class AccountService {
public:
    virtual ~AccountService() = default;
    virtual bool regi(AccountRegisterRequest *request) = 0;
    virtual bool login(AccountLoginRequest *request) = 0;

};

#endif //YOUNGCHANHWANG_ACCOUNTSERVICE_H
