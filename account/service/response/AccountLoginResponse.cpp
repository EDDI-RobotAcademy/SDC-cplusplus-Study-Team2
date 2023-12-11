//
// Created by eddi on 23. 12. 11.
//

#include "AccountLoginResponse.h"


AccountLoginResponse::AccountLoginResponse (bool isLoginSuccess)
        : isLoginSuccess(isLoginSuccess) { }

AccountLoginResponseForm *AccountLoginResponse::toResponseForm()
{
    return new AccountLoginResponseForm(isLoginSuccess);
}