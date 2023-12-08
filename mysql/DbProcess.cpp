//
// Created by eddi on 23. 11. 29.
//

#include "DbProcess.h"
#include <iostream>


DbProcess::DbProcess(const char* host, const char* user, const char* pass, const char* dbName)
        : conn(nullptr), DB_HOST(host), DB_USER(user), DB_PASS(pass), DB_NAME(dbName) {}

DbProcess::~DbProcess() {
    if (conn != nullptr) {
        mysql_close(conn);
    }
}

bool DbProcess::connect() {

    conn = mysql_init(nullptr);
    return (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, nullptr, 0) != nullptr);
}

// DbProcess.cpp

bool DbProcess::insertAccountData(const std::string& accountId, const std::string& password) {

        std::string insertQuery = "INSERT INTO account (account_id, password, reg_date, upd_date) VALUES ('" +
                                  accountId + "', '" + password + "', NOW(6), NOW(6))";

        return (mysql_query(conn, insertQuery.c_str()) == 0);
    }

bool DbProcess::checkId(const std::string& accountId) {
    std::string checkDuplicateQuery = "SELECT COUNT(*) FROM account WHERE account_id = '" + accountId + "'";
    if (mysql_query(conn, checkDuplicateQuery.c_str()) == 0) {
        MYSQL_RES *result = mysql_store_result(conn);
        if (result != nullptr) {
            MYSQL_ROW row = mysql_fetch_row(result);
            int rowCount = row ? std::stoi(row[0]) : 0;
            mysql_free_result(result);

            if (rowCount > 0) {
                std::cerr << "중복된 account_id 발견: " << accountId << std::endl;
                return false;
            }
        } else {
            std::cerr << "중복 확인을 위한 mysql_store_result() 실패" << std::endl;
            return false;
        }
    } else {
        std::cerr << "중복 확인을 위한 mysql_query() 실패" << std::endl;
        return false;
    }
    return true;
}

int DbProcess::checkAccount(const std::string &accountId, const std::string &password) {

        std::string checkAccountQuery =
                "SELECT COUNT(*) FROM account WHERE account_id = '" + accountId + "' AND password = '" + password + "'";

        if (mysql_query(conn, checkAccountQuery.c_str()) == 0) {
            MYSQL_RES *result = mysql_store_result(conn);
            if (result != nullptr) {
                MYSQL_ROW row = mysql_fetch_row(result);
                int rowCount = row ? std::stoi(row[0]) : 0;
                mysql_free_result(result);

                // rowCount가 1이면 계정이 존재하고 비밀번호도 일치함
                if (rowCount == 1) {
                    return 1; // 로그인 성공
                } else {
                    return 0; // 계정이 존재하지 않거나 비밀번호 불일치
                }
            } else {
                std::cerr << "계정 확인을 위한 mysql_store_result() 실패" << std::endl;
                throw std::runtime_error("계정 확인 중 오류 발생");
            }
        } else {
            std::cerr << "계정 확인을 위한 mysql_query() 실패" << std::endl;
            throw std::runtime_error("계정 확인 중 오류 발생");
        }
    }

bool DbProcess::insertBoardData(const std::string &title, const std::string &writer, const std::string &content) {
        std::string insertQuery = "INSERT INTO board (title, writer, content, reg_date, upd_date) VALUES ('" +
                                  title + "', '" + writer + "', '" + content + "',NOW(6), NOW(6))";

        return (mysql_query(conn, insertQuery.c_str()) == 0);
    }

bool DbProcess::updateBoardData(int boardId, const std::string &newTitle, const std::string &newContent) {
        std::string updateQuery = "UPDATE board SET title = '" + newTitle +
                                  "', content = '" + newContent +
                                  "' WHERE board_id = " + std::to_string(boardId);

        return (mysql_query(conn, updateQuery.c_str()) == 0);
    }

void DbProcess::selectAccountData() {
        std::string selectQuery = "SELECT * FROM account";
        if (mysql_query(conn, selectQuery.c_str()) == 0) {
            MYSQL_RES *result = mysql_store_result(conn);
            if (result == nullptr) {
                std::cerr << "mysql_store_result() failed" << std::endl;
                return;
            }

            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)) != nullptr) {
                std::cout << "id: " << row[0] << ", account_id: " << row[1]
                          << ", password: " << row[2]
                          << ", reg_date: " << (row[3] ? row[3] : "NULL") << ", upd_date: "
                          << (row[4] ? row[4] : "NULL") << std::endl;
            }

            mysql_free_result(result);
        } else {
            std::cerr << "mysql_query() failed" << std::endl;
        }
    }

void DbProcess::selectBoardData() {

        std::string selectQuery = "SELECT * FROM board";

        if (mysql_query(conn, selectQuery.c_str()) == 0) {
            // 위에서 처리한 select 결과를 result에 저장
            MYSQL_RES *result = mysql_store_result(conn);
            if (result == nullptr) {
                std::cerr << "mysql_store_result() failed" << std::endl;
                return;
            }

            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)) != nullptr) {
                std::cout << "board_id: " << row[0] << ", title: " << row[1]
                          << ", writer: " << row[2] << ", content: " << row[3]
                          << ", reg_date: " << (row[4] ? row[4] : "NULL")
                          << ", upd_date: " << (row[5] ? row[5] : "NULL") << std::endl;
            }

            mysql_free_result(result);
        } else {
            std::cerr << "mysql_query() failed" << std::endl;
        }
    }

bool DbProcess::deleteBoardData(int boardId) {
        std::string deleteQuery = "DELETE FROM board WHERE board_id = " + std::to_string(boardId);

        return (mysql_query(conn, deleteQuery.c_str()) == 0);
    }

void DbProcess::readBoardData(int boardId) {

        std::string readQuery = "SELECT * FROM board WHERE board_id = " + std::to_string(boardId);
        if (mysql_query(conn, readQuery.c_str()) == 0) {
            MYSQL_RES *result = mysql_store_result(conn);
            if (result == nullptr) {
                std::cerr << "mysql_store_result() failed" << std::endl;
                return;
            }

            MYSQL_ROW row = mysql_fetch_row(result);
            if (row != nullptr) {
                std::cout << "board_id: " << row[0] << ", title: " << row[1]
                          << ", writer: " << row[2] << ", content: " << row[3]
                          << ", reg_date: " << (row[4] ? row[4] : "NULL")
                          << ", upd_date: " << (row[5] ? row[5] : "NULL") << std::endl;
            } else {
                std::cout << "Record not found for board_id: " << boardId << std::endl;
            }

            mysql_free_result(result);
        } else {
            std::cerr << "mysql_query() failed" << std::endl;
        }
    }

MYSQL* DbProcess::getConn() {
    return conn;
}