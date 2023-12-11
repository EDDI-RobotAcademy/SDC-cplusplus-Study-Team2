//
// Created by eddi on 23. 12. 11.
//

#include "AccountRegisterResponseForm.h"


AccountRegisterResponseForm::AccountRegisterResponseForm(bool RegisterSuccess)
        : RegisterSuccess(RegisterSuccess) {}


bool AccountRegisterResponseForm::getRegisterSuccess() {
    return RegisterSuccess;
}