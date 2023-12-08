//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTSERVICEIMPL_H
#define YOUNGCHANHWANG_ACCOUNTSERVICEIMPL_H

#include <vector>
#include <memory>
#include "response/AccountResponse.h"
#include "AccountService.h"
#include "../repository/AccountRepository.h"
#include "request/AccountRequestLogin.h"

//////////////////
class AccountServiceImpl : public AccountService {
private:
    std::shared_ptr<AccountRepository> accountRepository;

public:
    AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository);
    std::vector<AccountResponse> regi() override;
    std::vector<AccountResponse> login() override;


};

#endif //YOUNGCHANHWANG_ACCOUNTSERVICEIMPL_H