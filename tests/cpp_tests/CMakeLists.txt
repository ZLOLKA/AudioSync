enable_testing()

file(GLOB tests_files
    "./tests/cpp_tests/gTests/**/*_tests.cpp"
    "./tests/cpp_tests/gTests/*_tests.cpp"
)

add_executable(${test_target_name} ${tests_files})

add_subdirectory("third-party/googletest")

target_link_libraries(${test_target_name} PUBLIC
    AudioSyncLib
    GTest::gtest_main
    GTest::gmock_main
    yaml-cpp
)
target_include_directories(${test_target_name} PUBLIC
    "./include/"
    "./tests/cpp_tests/gMocks/"
)
target_compile_definitions(${test_target_name} PUBLIC
    NOEXCEPT_MODE=${NOEXCEPT_MODE}
)

include(GoogleTest)
gtest_discover_tests(${test_target_name})

