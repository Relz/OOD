INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

SET(SOURCE_FILES
		ConstructorTest.cpp
		)

ADD_EXECUTABLE(LongIntegerTest ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(LongIntegerTest gtest gtest_main)
TARGET_LINK_LIBRARIES(LongIntegerTest LongInteger)
