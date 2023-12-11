//
// Created by eddi on 23. 12. 11.
//

#include "AccountLoginResponseForm.h"


AccountLoginResponseForm::AccountLoginResponseForm(bool LoginSuccess)
        : LoginSuccess(LoginSuccess) {}


bool AccountLoginResponseForm::getLoginSuccess() {
    return LoginSuccess;
}