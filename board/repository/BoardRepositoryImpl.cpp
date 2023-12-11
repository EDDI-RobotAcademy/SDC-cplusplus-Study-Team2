//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../entity/manager/BoardManager.h"
#include "../../mysql/DbProcess.h"
#include "../service/BoardServiceImpl.h"

#include <mysql/mysql.h>
#include <string>

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

            //std::cout << "Value of row[0]: " << row[0] << std::endl;

            Board board(
                    std::stoi(row[0]),                        // board_id
                    row[1],                                     // title
                    row[2],                                     // writer,
                    row[3],                                 // content
                    row[4] ? row[4] : "NULL",               // reg_date
                    row[5] ? row[5] : "NULL"                // upd_date
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
    std::cout << "BoardRepository: 리스트 전체 출력!" << std::endl;

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
    Board board(uid,"hi", "", "hi");
    return board;
}

void BoardRepositoryImpl::writePost(Board _request) {

    std::cout << "BoardRepository: 게시물 쓰기!" << std::endl;

    // mysql 접속기
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }
    std::string _title = _request.getTitle();
    std::string _writer = _request.getWriter();
    std::string _content = _request.getContent();

    // _request를 파라미터로 받아서 insertData가 동작해야함
    db.insertBoardData(_title, _writer, _content);
}

void BoardRepositoryImpl::editPost(BoardRequestFormEdit _request) {
    std::cout << "BoardRepository: 게시물 수정!" << std::endl;

    // mysql 접속기
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }
    int boardUid = _request.getBoardUid();
    std::string _newTitle = _request.getTitle();
    std::string _newContent = _request.getContent();

    // 이거 알아서 잘 해주세용
    db.updateBoardData(boardUid, _newTitle, _newContent);
}

void BoardRepositoryImpl::removePost(int _boardUid) {
    std::cout << "BoardRepository: 게시물 수정!" << std::endl;

    // mysql 접속기
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }

    // 체크 바람
    db.deleteBoardData(_boardUid);
}
