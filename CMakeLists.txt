cmake_minimum_required(VERSION 3.26)
project(cpp_gtest)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)
find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

file(GLOB CPP_SOURCES
        class_test main.cpp
        board/controller/BoardController.cpp
        board/service/BoardServiceImpl.cpp
        board/entity/Board.cpp
        mysql/DbProcess.cpp
        board/repository/BoardRepositoryImpl.cpp
        board/manager/BoardManager.cpp
        board/service/response/BoardResponseList.cpp
        board/service/response/BoardResponseRead.cpp
        board/service/request/BoardRequestFormWrite.cpp
        ui/console/service/ConsoleUiServiceImpl.cpp
        ui/console/user_keyboard/user_keyboard_input.cpp
        ui/console/window/console_window.cpp
        ui/console/controller/ConsoleUiController.cpp
)

file(GLOB MAIN_SOURCES
        "*.cpp"
)

add_executable(
        cpp_gtest
        ${CPP_SOURCES}
        ${MAIN_SOURCES}

)

target_include_directories(cpp_gtest PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(cpp_gtest PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})