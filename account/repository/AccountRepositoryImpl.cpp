//
// Created by eddi on 23. 12. 6.
//

#include "AccountRepositoryImpl.h"
#include "../../mysql/DbProcess.h"
#include <string>
#include <iostream>


bool AccountRepositoryImpl::createAccount(Account *account)
{
    std::string id = account->getAccount_id();
    std::string pass = account->getPassword();


    std::cout << "AccountRepository: 회원가입" << std::endl;

    // mysql 접속
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);


    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }

    int check_id = db.checkId(id);
    if(check_id == 1)
    {
        db.insertAccountData(id, pass);
        return true;
    }
    else if(check_id == 0) { return false; }

}


bool AccountRepositoryImpl::checkAccount(std::string account_id, std::string password)
{

    std::cout << "AccountRepositoryImpl 아이디 비밀번호 체크" << std::endl;

    // mysql 접속
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);


    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }
    // 로그인 실패하면 0 성공하면 1
    int check_Account = db.checkAccount(account_id, password);

    return check_Account;

}