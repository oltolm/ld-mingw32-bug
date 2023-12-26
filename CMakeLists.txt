cmake_minimum_required(VERSION 3.19)
project(playground VERSION 0.0.1 LANGUAGES C CXX)

add_library(mylib SHARED src/mylib.c src/mylib.def)

add_executable(myexe src/myexe.c)

target_link_options(myexe PRIVATE -municode)
target_compile_features(myexe PRIVATE c_std_11)
target_compile_options(myexe PRIVATE -fno-omit-frame-pointer)
target_link_libraries(myexe PRIVATE mylib)

include(ctest)

add_test(NAME test_build COMMAND "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}")
set_tests_properties(test_build PROPERTIES FIXTURES_SETUP test_fixture)

add_test(NAME "test ld" COMMAND myexe)
set_tests_properties("test ld" PROPERTIES FIXTURES_REQUIRED test_fixture)
