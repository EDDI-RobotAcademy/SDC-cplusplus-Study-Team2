//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>
#include <chrono>
#include <iostream>

class Board {
private:
    unsigned int id;
    std::string title;
    unsigned int writer;
    std::string content;

    std::chrono::system_clock::time_point created_at;
    std::chrono::system_clock::time_point updated_at;

public:
    Board(unsigned int id, const std::string& title, const unsigned int& writer, const std::string& content);
    Board(unsigned int id, const std::string& title, const unsigned int& writer, const std::string& content,
          const std::string& reg_date, const std::string& upd_date);

    void printBoardInfo() const;
    unsigned int getBoardUID();
};


#endif //CLASS_TEST_BOARD_H
