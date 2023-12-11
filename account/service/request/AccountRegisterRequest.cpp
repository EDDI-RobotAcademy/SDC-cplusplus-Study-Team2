//
// Created by eddi on 23. 12. 11.
//

#include "AccountRegisterRequest.h"

AccountRegisterRequest::AccountRegisterRequest(const std::string &account_id, const std::string &password)
        : account_id(account_id), password(password) { }

Account *AccountRegisterRequest::toAccount() {
    return new Account(account_id, password);
}