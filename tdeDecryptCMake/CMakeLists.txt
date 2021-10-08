cmake_minimum_required(VERSION 3.0.0)
project(tdeDecrypt VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(tdeDecrypt decryptTDE.c)
#target_link_libraries(tdeDecrypt -static-libgcc)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
