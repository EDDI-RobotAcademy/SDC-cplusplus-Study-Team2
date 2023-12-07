//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_DBPROCESS_H
#define CPP_TEST_DBPROCESS_H

#include <mysql/mysql.h>
#include <string>

class DbProcess {
public:
    DbProcess(const char* host, const char* user, const char* pass, const char* dbName);
    ~DbProcess();

    bool connect();
    bool insertAccountData(const std::string& accountID, const std::string& password);
    bool insertBoardData(const std::string& title, const std::string& writer, const std::string& content);
    bool updateBoardData(int boardId, const std::string& newTitle, const std::string& newContent);

    void selectBoardData();
    void selectAccountData();

    bool deleteBoardData(int boardId);
    void readBoardData(int boardId);

    MYSQL *getConn();

private:
    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;
};


#endif //CPP_TEST_DBPROCESS_H
