cmake_minimum_required(VERSION 3.14)

project(myBigInt)

set(
    myBigInt_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include"
)

set(
    myBigInt_SOURCE_DIR  "${PROJECT_SOURCE_DIR}/src"
)

set(
    myBigInt_BINARY_DIR "${PROJECT_BINARY_DIR}/bin"
)

add_library(
    mybigint STATIC
)
target_sources(mybigint PRIVATE
    "${myBigInt_SOURCE_DIR}/myBigInt.cpp"
)

target_include_directories( mybigint PUBLIC
"${myBigInt_INCLUDE_DIR}"
)
