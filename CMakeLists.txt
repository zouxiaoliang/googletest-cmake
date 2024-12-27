cmake_minimum_required(VERSION 3.5)

project(googletest-cmake LANGUAGES CXX C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/external)

include(ExternalProject)

function(main)
    ExternalProject_Add(
        googletest
        PREFIX ${EXTERNAL_INSTALL_LOCATION}
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        UPDATE_DISCONNECTED TRUE
    )

    add_library(thirdparty_gtest INTERFACE)
    add_dependencies(thirdparty_gtest googletest)
    target_include_directories(thirdparty_gtest INTERFACE
        ${EXTERNAL_INSTALL_LOCATION}/include
    )
    target_link_libraries(thirdparty_gtest PUBLIC INTERFACE ${EXTERNAL_INSTALL_LOCATION}/lib/libgtest.a)

    add_library(thirdparty_gmock INTERFACE)
    add_dependencies(thirdparty_gmock googletest)
    target_include_directories(thirdparty_gmock INTERFACE ${EXTERNAL_INSTALL_LOCATION}/include)
    target_link_libraries(thirdparty_gmock INTERFACE ${EXTERNAL_INSTALL_LOCATION}/lib/libgmock.a)
endfunction(main)

function(test)
    set(MAIN_SOURCES main.cpp)
    add_executable(googletest-example ${MAIN_SOURCES})
    target_link_libraries(googletest-example thirdparty_gtest thirdparty_gmock)
endfunction(test)

main()
test()
