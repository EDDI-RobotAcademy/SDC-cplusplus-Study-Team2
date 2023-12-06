#include <string>
#include <iostream>
#include "ConsoleUiServiceImpl.h"
#include "../user_keyboard/user_keyboard_input.h"
#include "../../../board/entity/Board.h"

//
// Created by eddi on 23. 12. 4.
//
ConsoleUiServiceImpl::ConsoleUiServiceImpl () { }

Board *ConsoleUiServiceImpl::creatPost() {
    user_keyboard_input _user_keyboard_input;

    std::vector<ConsoleUiServiceImpl> resultVector;

    std::string title_print = "\n제목을 입력하세요: ";
    std::string writer_print = "\n작성자를 입력하세요: ";
    std::string content_print = "\n내용을 입력하세요: ";

    std::string title;
    std::string writer;
    std::string content;

    _user_keyboard_input.get_user_keyboard_input_with_message(title_print, title);
    _user_keyboard_input.get_user_keyboard_input_with_message(writer_print, writer);
    _user_keyboard_input.get_user_keyboard_input_with_message(content_print, content);

    // 새로운 객체를 생성하고 값을 설정
    Board *newPost = new Board(title, writer, content);

    std::cout << "\n제목 :" << title << "내용: " << writer << "내용: " << content << std::endl;

    return newPost; // entity 로 접근
}

/*ConsoleUiServiceImpl::postExit () {
    std::cout << "exitPost 함수 호출 확인" << std::endl;
}

ConsoleUiServiceImpl::postList () {
    std::cout << "postList 함수 호출 확인" << std::endl;
}

ConsoleUiServiceImpl::postModify () {
    std::cout << "postModify 함수 호출 확인" << std::endl;
}

ConsoleUiServiceImpl::postRead () {
    std::cout << "postRead 함수 호출 확인" << std::endl;
}

ConsoleUiServiceImpl::postRemove () {
    std::cout << "postRemove 함수 호출 확인" << std::endl;
}*/

ConsoleUiServiceImpl::~ConsoleUiServiceImpl() { }

