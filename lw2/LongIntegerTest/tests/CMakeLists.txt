INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

SET(SOURCE_FILES
		ConstructorTest.cpp
		AssignmentTest.cpp EquivalenceOperatorTest.cpp NotEquivalenceOperatorTest.cpp LessOperatorTest.cpp MoreOperatorTest.cpp PlusOperatorTest.cpp MinusOperatorTest.cpp MultiplicationOperatorTest.cpp DivisionOperatorTest.cpp CreateFromStringTest.cpp)

ADD_EXECUTABLE(LongIntegerTest ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(LongIntegerTest gtest gtest_main)
TARGET_LINK_LIBRARIES(LongIntegerTest LongInteger)
