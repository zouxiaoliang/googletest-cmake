cmake_minimum_required(VERSION 3.5)

project(googletest-cmake LANGUAGES CXX C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

function(gtest)
    add_library(thirdparty_gtest INTERFACE)
    target_link_libraries(thirdparty_gtest INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/lib/libgtest.a)
    target_include_directories(thirdparty_gtest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
endfunction(gtest)
    add_library(thirdparty_gmock INTERFACE)
    target_link_libraries(thirdparty_gmock INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/lib/libgmock.a)
    target_include_directories(thirdparty_gmock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include)
function(gmock)

endfunction(gmock)
function(main)
    set(MAIN_SOURCES main.cpp)
    add_executable(googletest-example ${MAIN_SOURCES})
    target_link_libraries(googletest-example thirdparty_gtest thirdparty_gmock)
endfunction(main)


gtest()
gmock()

main()
