//
// Created by eddi on 23. 12. 11.
//
#include "AccountLoginRequestForm.h"




AccountLoginRequestForm::AccountLoginRequestForm(
        const std::string& account_id, const std::string& password) :
        account_id(account_id), password(password) { }

AccountLoginRequest *AccountLoginRequestForm::toAccountLoginRequest()
{
    return new AccountLoginRequest(account_id, password);
}