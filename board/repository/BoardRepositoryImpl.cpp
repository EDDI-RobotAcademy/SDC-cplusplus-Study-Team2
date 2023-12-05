//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../manager/BoardManager.h"
#include "../../mysql/DbProcess.h"
#include "../service/BoardServiceImpl.h"

#include <mysql/mysql.h>

BoardManager boardManager(std::make_shared<BoardController>(std::make_shared<BoardServiceImpl>(std::make_shared<BoardRepositoryImpl>())));


std::vector<Board> fetchResults(MYSQL* conn) {
    std::vector<Board> boardList;

    const std::string& selectQuery = "SELECT * FROM board";

    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return boardList;
        }

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result)) != nullptr) {
            Board board(
                    std::stoi(row[0]),                        // board_id
                    row[3],                                     // title
                    //(unsigned int)std::stoul(row[5]),     // writer
                    0,
                    row[1],                                 // content
                    row[2] ? row[2] : "NULL",               // reg_date
                    row[4] ? row[4] : "NULL"                // upd_date
            );
            // pushback : 동적배열에 저장하는 명령어
            boardList.push_back(board);
        }

        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }

    return boardList;
}

std::vector<Board> BoardRepositoryImpl::findAll()
{
    std::cout << "BoardReopository: 리스트 전체 출력!" << std::endl;

    // mysql 접속
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }

    std::vector<Board> boardList = fetchResults(db.getConn());

    for (const auto& board : boardList) {
        board.printBoardInfo();
    }

    return boardList;
}

Board BoardRepositoryImpl::findPost(int uid) {
    int boardCount = (int)boardManager.getBoardList().size();
    for(int i = 0; i < boardCount; i++){
        if(uid == boardManager.getBoardList()[i].getBoardUID()){
            return boardManager.getBoardList()[i];
        }
    }

    std::cout << "찾을 수 없음!" << std::endl;
    Board b(0,"",0,"");
    return b;
}

void BoardRepositoryImpl::writePost(Board _request) {

}
