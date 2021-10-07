cmake_minimum_required(VERSION 3.16)
project(Speuren-Met-Krul)

set(CMAKE_CXX_STANDARD 20)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

file(GLOB_RECURSE SOURCE src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

file(GLOB_RECURSE TESTS src/*.cpp tests/*.cpp)
list(FILTER TESTS EXCLUDE REGEX ".*src/main.cpp$")
add_executable(${PROJECT_NAME}_Tests ${TESTS})
target_link_libraries(${PROJECT_NAME}_Tests ${CONAN_LIBS})
