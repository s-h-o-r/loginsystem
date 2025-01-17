cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

project(loginsystem CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SRC
    src/main.cpp
)

add_executable(loginsystem
    ${SRC}
)

target_link_libraries(loginsystem PRIVATE Threads::Threads)