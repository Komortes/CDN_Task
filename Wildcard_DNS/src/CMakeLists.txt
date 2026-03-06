cmake_minimum_required(VERSION 3.10)
project(Wildcard_DNS C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Wildcard_DNS 3_task.c Trie.c)

target_compile_options(Wildcard_DNS PRIVATE -Wall -Wextra -Wpedantic)

if(BUILD_TESTING)
    add_test(NAME Wildcard_DNS_tests COMMAND Wildcard_DNS)
endif()
