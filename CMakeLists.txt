cmake_minimum_required(VERSION 2.8)
project(InterfacePerformanceTest)

add_executable(${PROJECT_NAME}
    "main.cpp"
    InterfaceVersion1.h
    InterfaceVersion2.h
    InterfaceVersion3.h
    InterfaceVersion3b.h
    InterfaceVersion3c.h
    InterfaceVersion4.h
    InterfaceVersion4b.h)

