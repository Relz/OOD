CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(lw2)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_BUILD_TYPE Debug)

ADD_SUBDIRECTORY(googletest/googletest)

ADD_SUBDIRECTORY(LongInteger)
ADD_SUBDIRECTORY(LongIntegerTest)

ADD_EXECUTABLE(lw2 main.cpp LongInteger/LongInteger.h LongInteger/Digit.h LongInteger/DigitExtensions.h LongInteger/DigitExtensions.cpp)
