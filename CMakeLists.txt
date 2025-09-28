cmake_minimum_required(VERSION 3.10)
project(Fraction VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к заголовочным файлам
include_directories(include)

# Основное приложение
add_executable(fraction_app
    src/main.cpp
    src/fraction.cpp
)

set_target_properties(fraction_app PROPERTIES
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Тесты
enable_testing()
add_subdirectory(tests)
