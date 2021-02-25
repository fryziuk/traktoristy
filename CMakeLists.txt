cmake_minimum_required(VERSION 3.17)
project(hash_code)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash_code
        main.cpp
        io_handler.cpp
        )

target_include_directories(hash_code PUBLIC
        include)