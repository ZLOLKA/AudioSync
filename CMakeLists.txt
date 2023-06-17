cmake_minimum_required(VERSION 3.26)

project(AudioSync VERSION 0.1 LANGUAGES CXX)

file(GLOB src_files 
    "./src/**/*.cpp" 
    "./src/*.cpp" 
    "./main.cpp"
)

add_executable(AudioSync ${src_files})

target_include_directories(AudioSync PUBLIC "include/")
target_compile_options(AudioSync PUBLIC 
    -pedantic-errors -Werror -Wall -Wextra -Wpedantic -Wpedantic-macros
)

# Include yaml-cpp as static lib
add_subdirectory("third-party/yaml-cpp")
target_link_libraries(AudioSync PUBLIC yaml-cpp)

