//
// Created by eddi on 23. 12. 8.
//
#include <iostream>

#include "ConsoleUiServiceImpl.h"
#include "../user_keyboard/user_keyboard_input.h"

ConsoleUiServiceImpl::ConsoleUiServiceImpl() {}

void ConsoleUiServiceImpl::makeUiAccountPrint() {
  //  std::cout << "ConsoleUiService: AccountCommandUi" << std::endl;
    std::cout << "0. 로그인" << std::endl;
    std::cout << "1. 회원가입" << std::endl;
    std::cout << "2. 종료" << std::endl;
    std::cout << "어떤 작업을 수행하시겠습니까?" << std::endl;
}

void ConsoleUiServiceImpl::makeUiBoardPrint() {
 //   std::cout << "ConsoleUiService: BoardCommandUi" << std::endl;
    std::cout << "0. 리스트 출력" << std::endl;
    std::cout << "1. 게시물 작성" << std::endl;
    std::cout << "2. 게시물 조회" << std::endl;
    std::cout << "3. 게시물 수정" << std::endl;
    std::cout << "4. 게시물 삭제" << std::endl;
    std::cout << "5. 종료" << std::endl;
    std::cout << "어떤 작업을 수행하시겠습니까?" << std::endl;
}

AccountLoginRequestForm *ConsoleUiServiceImpl::makeAccountLoginRequestForm() {
    std::string id, pw;

    get_user_keyboard_input_with_message("사용자 아이디를 입력하세요: ", id);
    get_user_keyboard_input_with_message("사용자 비밀번호를 입력하세요: ", pw);

    return new AccountLoginRequestForm(id, pw);
}

AccountRegisterRequestForm *ConsoleUiServiceImpl::makeAccountRegisterRequestForm() {
    std::string id, pw;

    get_user_keyboard_input_with_message("신규 사용자 아이디를 입력하세요: ", id);
    get_user_keyboard_input_with_message("신규 사용자 비밀번호를 입력하세요: ", pw);

    return new AccountRegisterRequestForm(id, pw);
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