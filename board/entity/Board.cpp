//
// Created by eddi on 23. 11. 30.
//

#include "Board.h"
#include "../repository/BoardRepositoryImpl.h"
#include "../service/BoardServiceImpl.h"
#include "manager/BoardManager.h"

//BoardManager boardManager(std::make_shared<BoardController>(std::make_shared<BoardServiceImpl>(std::make_shared<BoardRepositoryImpl>())));

Board::Board(const std::string& title, const std::string& writer, const std::string& content)
        : title(title),
          writer(writer),
          content(content) {

    id = boardManager.getNextUid();

    std::cout << id << "번째 게시물 생성" << std::endl;
}

Board::Board(int id, const std::string& title, const std::string& writer, const std::string& content)
        : id(id),
          title(title),
          writer(writer),
          content(content) {}

Board::Board(int id, const std::string& title, const std::string& writer, const std::string& content,
      const std::string& reg_date, const std::string& upd_date)
        : id(id),
          title(title),
          writer(writer),
          content(content) {
    // reg_date, upd_date를 이용하여 시간 설정 (형식에 따라 변경이 필요할 수 있음)
    created_at = std::chrono::system_clock::from_time_t(std::stoi(reg_date));
    updated_at = upd_date.empty() ? created_at : std::chrono::system_clock::from_time_t(std::stoi(upd_date));
}

void Board::printBoardInfo() const {
    std::cout << "ID: " << id
        << ", Title: " << title
        << ", Writer UID: " << writer
        << ", Content: " << content
        << ", Created At: " << std::chrono::system_clock::to_time_t(created_at)
        << ", Updated At: " << std::chrono::system_clock::to_time_t(updated_at) << std::endl;
}

int Board::getBoardUID() {
    return id;
}

std::string Board::getTitle() {
    return title;
}

int Board::getWriter() {
    return writer;
}

std::string Board::getContent() {
    return content;
}
