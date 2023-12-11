//
// Created by eddi on 23. 12. 11.
//

#include "AccountLoginRequest.h"

AccountLoginRequest::AccountLoginRequest(
        const std::string &account_id, const std::string &password) :
        account_id(account_id), password(password) { }

std::string AccountLoginRequest::getPassword() {
    return password;
}

std::string AccountLoginRequest::getAccountId() {
    return account_id;
}