//
// Created by eddi on 23. 12. 6.
//
#include "AccountController.h"
#include "../service/response/AccountLoginResponse.h"
#include "../service/response/AccountRegisterResponse.h"

#include <iostream>
#include <vector>

AccountController::AccountController(std::shared_ptr<AccountService> accountService) : accountService(accountService) { }

AccountRegisterResponseForm *
AccountController::accountRegister(AccountRegisterRequestForm *requestForm)
{
    std::cout << "accountController: 회원가입" << std::endl;

    AccountRegisterResponse response = accountService->regi(requestForm->toAccountRegisterRequest());

    return response.toResponseForm();

}

AccountLoginResponseForm *
AccountController::accountLogin(AccountLoginRequestForm *requestForm)
{
    std::cout << "accountController: 로그인" <<std::endl;

    AccountLoginResponse response = accountService->login(requestForm->toAccountLoginRequest());

    return response.toResponseForm();

}