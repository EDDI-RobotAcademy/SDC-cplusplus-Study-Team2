//
// Created by eddi on 23. 12. 4.
//

#include <iostream>
#include "UiServiceCreateHandler.h"
#include "../../../user_keyboard/user_keyboard_input.h"

UiServiceCreateHandler::UiServiceCreateHandler () {
    std::cout << "게시글을 작성합니다." << std::endl;
}
std::string UiServiceCreateHandler::getTitle() {
    return title;
}
std::string UiServiceCreateHandler::getWriter() {
    return writer;
}
std::string UiServiceCreateHandler::getContent() {
    return content;
}

std::string UiServiceCreateHandler::getCreatPost() {
    user_keyboard_input _user_keyboard_input;

    std::string title_print = "\n제목을 입력하세요: ";
    std::string writer_print = "\n작성자를 입력하세요: ";
    std::string content_print = "\n내용을 입력하세요: ";

    _user_keyboard_input.get_user_keyboard_input_with_message(title_print,title);
    _user_keyboard_input.get_user_keyboard_input_with_message(writer_print,writer);
    _user_keyboard_input.get_user_keyboard_input_with_message(content_print,content);

    std::cout<<"\n제목 :" << title << "내용: " << writer << "내용: " <<content << std::endl;

}



UiServiceCreateHandler::~UiServiceCreateHandler() { }