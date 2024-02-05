cmake_minimum_required(VERSION 3.15)

project(dm LANGUAGES CXX)
add_executable(dm
    "src/mapper.cpp"
    "src/processor.cpp"
    "src/dm.cpp")
