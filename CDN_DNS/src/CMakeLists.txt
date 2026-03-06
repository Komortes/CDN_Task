cmake_minimum_required(VERSION 3.10)
project(CDN_DNS C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(CDN_DNS dns.c Reader.c Trie.c)

target_compile_options(CDN_DNS PRIVATE -Wall -Wextra -Wpedantic)

if(BUILD_TESTING)
    add_test(
        NAME CDN_DNS_smoke
        COMMAND CDN_DNS ${CMAKE_CURRENT_SOURCE_DIR}/../build/routing-data.txt
    )
endif()
