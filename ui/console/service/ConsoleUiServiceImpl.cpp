//
// Created by eddi on 23. 12. 8.
//
#include <iostream>

#include "ConsoleUiServiceImpl.h"

ConsoleUiServiceImpl::ConsoleUiServiceImpl() {}

ConsoleUiServiceImpl::ConsoleUiServiceImpl(std::shared_ptr<ConsoleUiRepository> consoleUiRepository) : consoleUiRepository(consoleUiRepository) {}

void ConsoleUiServiceImpl::makeUiPrint() {
    std::cout << "ConsoleUiService: makeUiPrint" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
    consoleUiRepository->getSession();
}