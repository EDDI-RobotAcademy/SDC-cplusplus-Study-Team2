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
        "board/controller/*.cpp"
        "board/service/*.cpp"
        "board/entity/*.cpp"
        "board/repository/*.cpp"
        "board/manager/*.cpp"
        "board/service/response/*.cpp"
        "board/service/response/*.cpp"
        "board/service/request/*.cpp"
        "ui/console/service/*.cpp"
        "ui/console/user_keyboard/*.cpp"
        "ui/console/window/*.cpp"
        "ui/console/controller/*.cpp"
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