cmake_minimum_required(VERSION 3.20)
project(c_transformer)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_ROOT "${CMAKE_SOURCE_DIR}")

add_executable(c_transformer tests/csv_handler.cpp)

target_include_directories(c_transformer PRIVATE include)

file(GLOB DATA_FILES "${CMAKE_SOURCE_DIR}/data/*")

file(COPY ${DATA_FILES}
     DESTINATION ${CMAKE_BINARY_DIR}/data)