//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTCONTROLLER_H
#define YOUNGCHANHWANG_ACCOUNTCONTROLLER_H

#include <memory>
#include <vector>

#include "../service/AccountService.h"
#include "response/AccountLoginResponseForm.h"
#include "request/AccountLoginRequestForm.h"
#include "response/AccountRegisterResponseForm.h"
#include "request/AccountRegisterRequestForm.h"

class AccountController {
private:
    std::shared_ptr<AccountService> accountService;

public:
    AccountController(std::shared_ptr<AccountService> accountService);

    AccountRegisterResponseForm *accountRegister(AccountRegisterRequestForm *requestForm);
    AccountLoginResponseForm *accountLogin(AccountLoginRequestForm *requestForm);

};


#endif //YOUNGCHANHWANG_ACCOUNTCONTROLLER_H
