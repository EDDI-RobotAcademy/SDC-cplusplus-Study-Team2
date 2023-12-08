//
// Created by eddi on 23. 12. 6.
//
#include "AccountController.h"

#include <iostream>
#include <vector>

AccountController::AccountController(std::shared_ptr<AccountService> accountService) : accountService(accountService) { }

std::vector<AccountResponse> AccountController::accountRegister()
{
    std::cout << "accountController: 회원가입" << std::endl;

    accountService->regi();

    return std::vector<AccountResponse>();

}

std::vector<AccountResponse> AccountController::accountLogin()
{
    std::cout << "accountController: 로그인" <<std::endl;

    accountService->login();

    return std::vector<AccountResponse>();

}