cmake_minimum_required(VERSION 3.20.0)
project(qlogger VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -std=c++20")

file(GLOB QLOGGER_SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cc"
    "${PROJECT_SOURCE_DIR}/src/platform/*.cc"
)

file(GLOB QLOGGER_HEADERS_PRIVATE 
    "${PROJECT_SOURCE_DIR}/src/*.h"
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # target_compile_options(${PROJECT_NAME} PRIVAE "\EHsc")
endif()

# The include path to specify for building the library
set(QLOGGER_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}"
)

add_library(${PROJECT_NAME} SHARED ${QLOGGER_SOURCES} ${QLOGGER_HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${QLOGGER_INCLUDE_DIR}"
)
target_compile_options(${PROJECT_NAME} PUBLIC "-DQEXPORT")

# Build examples
file(GLOB SIMPLE_SOURCE
    "${PROJECT_SOURCE_DIR}/examples/simple.cc"
)

add_executable(simple ${SIMPLE_SOURCE})
target_include_directories(simple
    PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(simple PUBLIC ${PROJECT_NAME})

#Generate compiler commands for using clangd LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
