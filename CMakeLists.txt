cmake_minimum_required(VERSION 3.26)
project(cpp_gtest)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})


file(GLOB CPP_SOURCES
        "mysql/*.cpp"
        "account/controller/*.cpp"
        "account/entity/*.cpp"
        "account/repository/*.cpp"
        "account/service/*.cpp"
        "account/service/response/*.cpp"
        "account/service/request/*.cpp"
        "board/controller/*.cpp"
        "board/controller/request/*.cpp"
        "board/controller/response/*.cpp"
        "board/service/*.cpp"
        "board/entity/*.cpp"
        "board/entity/manager/*.cpp"
        "board/repository/*.cpp"
        "board/service/response/*.cpp"
        "board/service/response/*.cpp"
        "board/service/request/*.cpp"
        "ui/console/user_keyboard/*.cpp"
        "*.cpp"
)

add_executable(
        cpp_gtest
        ${CPP_SOURCES}
        ${MAIN_SOURCES}
        ui/console/controller/ConsoleUiControllerCommand.h
        ui/console/controller/ConsoleUiController.cpp
        ui/console/controller/ConsoleUiController.h
        ui/console/service/ConsoleUiServiceImpl.cpp
        ui/console/service/ConsoleUiServiceImpl.h
        ui/console/service/ConsoleUiService.h
        ui/console/repository/ConsoleUiRepositoryImpl.cpp
        ui/console/repository/ConsoleUiRepositoryImpl.h
        ui/console/repository/ConsoleUiRepository.h
        account/controller/request/AccountLoginRequestForm.cpp
        account/controller/request/AccountLoginRequestForm.h
        account/controller/response/AccountLoginResponseForm.cpp
        account/controller/response/AccountLoginResponseForm.h
        account/service/request/AccountLoginRequest.cpp
        account/service/request/AccountLoginRequest.h
        account/service/response/AccountLoginResponse.cpp
        account/service/response/AccountLoginResponse.h
)

target_include_directories(cpp_gtest PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(cpp_gtest PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})