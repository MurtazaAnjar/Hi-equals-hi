cmake_minimum_required(VERSION 3.24)

project(hi_equals_hi)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(strcmp_test tests/strcmp_test.cpp src/strcmp.cpp)
add_executable(main main.cpp src/strcmp.cpp)

target_link_libraries(strcmp_test PRIVATE Catch2::Catch2WithMain)
