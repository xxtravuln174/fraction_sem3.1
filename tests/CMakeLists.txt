include(FetchContent)

# Подтягиваем GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Исполняемый файл для тестов
add_executable(tests
    tests.cpp
    ${CMAKE_SOURCE_DIR}/src/fraction.cpp
)

target_link_libraries(tests PRIVATE gtest_main)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Добавляем тест для ctest
add_test(NAME run_tests COMMAND tests)
