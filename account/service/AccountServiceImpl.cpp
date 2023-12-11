//
// Created by eddi on 23. 12. 6.
//
#include "AccountServiceImpl.h"

#include <iostream>

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

std::vector<AccountResponse> AccountServiceImpl::regi()
{
    std::cout << "회원가입" << std::endl;

    accountRepository->createAccount();

    return std::vector<AccountResponse>();
}

bool AccountServiceImpl::login(AccountLoginRequest *request)
{
    return accountRepository->checkAccount(request->getAccountId(), request->getPassword());
}