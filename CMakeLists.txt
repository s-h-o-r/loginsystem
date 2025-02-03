cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
project(loginsystem CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(LoginSystemLib STATIC
    src/login_system.h
    src/login_system.cpp
    src/user.h
    src/user.cpp
    src/singup_system.h
    src/singup_system.cpp
)

target_link_libraries(LoginSystemLib PRIVATE Threads::Threads)

set(SRC
    src/main.cpp
    src/app.h
    src/app.cpp
)

add_executable(loginsystem
    ${SRC}
)

target_link_libraries(loginsystem PRIVATE LoginSystemLib Threads::Threads)

find_package(Catch2 REQUIRED)

add_executable(login_tests
    test/tests.cpp
)

target_link_libraries(login_tests PRIVATE Catch2::Catch2WithMain LoginSystemLib)
