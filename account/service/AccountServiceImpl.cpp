//
// Created by eddi on 23. 12. 6.
//
#include "AccountServiceImpl.h"

#include <iostream>

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

bool AccountServiceImpl::regi(AccountRegisterRequest *request)
{
    std::cout << "회원가입" << std::endl;
    bool isRegisterSuccess = accountRepository->createAccount(request->toAccount());

    if(isRegisterSuccess == false) { std::cout << "회원가입 실패" << std::endl; }
    if(isRegisterSuccess == true) { std::cout << "회원가입 성공" << std::endl; }



    return isRegisterSuccess;

}

bool AccountServiceImpl::login(AccountLoginRequest *request)
{
    std::cout << "로그인" << std::endl;


    return accountRepository->checkAccount(request->getAccountId(), request->getPassword());

}