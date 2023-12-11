//
// Created by eddi on 23. 12. 11.
//

#include "AccountRegisterResponse.h"


AccountRegisterResponse::AccountRegisterResponse (bool isRegisterSuccess)
        : isRegisterSuccess(isRegisterSuccess) { }

AccountRegisterResponseForm *AccountRegisterResponse::toResponseForm()
{
    return new AccountRegisterResponseForm(isRegisterSuccess);
}