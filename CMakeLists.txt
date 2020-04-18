cmake_minimum_required(VERSION 3.0.0)
project(I2Cpi VERSION 0.1.0)

include(CTest)
enable_testing()
 
add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/I2Clinux.cpp)

if (NOT TARGET I2C)
    add_subdirectory (${PROJECT_SOURCE_DIR}/I2C)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} I2C)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)