//
// Created by eddi on 23. 12. 8.
//
#include <iostream>

#include "ConsoleUiServiceImpl.h"
#include "../user_keyboard/user_keyboard_input.h"

ConsoleUiServiceImpl::ConsoleUiServiceImpl() {}

ConsoleUiServiceImpl::ConsoleUiServiceImpl(std::shared_ptr<ConsoleUiRepository> consoleUiRepository) : consoleUiRepository(consoleUiRepository) {}

void ConsoleUiServiceImpl::makeUiPrint() {
    std::cout << "ConsoleUiService: makeUiPrint" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
//    consoleUiRepository->getSession();
}

int ConsoleUiServiceImpl::makeRequestToReadForm() {
    std::string boardUid;

    get_user_keyboard_input_with_message("조회할 게시물 번호를 입력하세요: ", boardUid);
    int boardNo = std::stoi(boardUid);

    return boardNo;
}

RequestToWrite *ConsoleUiServiceImpl::makeRequestToWriteForm() {
    std::string title, writer, content;

    get_user_keyboard_input_with_message("게시물 제목을 입력하세요: ", title);
    // 입력 받는 것이 아닌 account 정보를 받는 것
    get_user_keyboard_input_with_message("게시물 작성자를 입력하세요: ", writer);
    get_user_keyboard_input_with_message("게시물 내용을 입력하세요: ", content);

    return new RequestToWrite(title, writer, content);
}

RequestToEdit *ConsoleUiServiceImpl::makeRequestToEditForm() {
    std::string uid, title, content;

    get_user_keyboard_input_with_message("수정할 게시물 번호를 입력하세요: ", uid);
    get_user_keyboard_input_with_message("수정할 제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("수정할 내용을 입력하세요: ", content);

    return new RequestToEdit(stoi(uid), title, content);
}

int ConsoleUiServiceImpl::makeRequestToDeleteForm() {
    std::string boardUid;

    get_user_keyboard_input_with_message("삭제할 게시물 번호를 입력하세요: ", boardUid);
    int boardNo = std::stoi(boardUid);

    return boardNo;
}