cmake_minimum_required(VERSION 3.10)  
project(CDN_DNS C) 

set(CMAKE_C_STANDARD 99)  

add_executable(CDN_DNS dns.c Reader.c Trie.c)  
