cmake_minimum_required(VERSION 3.16)

project(CDN_Task C)

include(CTest)

add_subdirectory(CDN_DNS/src)
add_subdirectory(Wildcard_DNS/src)
