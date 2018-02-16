PROJECT(LongInteger)

SET(SOURCE_FILES
		LongInteger.h
		Digit.h DigitExtensions.h DigitExtensions.cpp)

ADD_LIBRARY(LongInteger SHARED ${SOURCE_FILES})
SET_TARGET_PROPERTIES(LongInteger PROPERTIES LINKER_LANGUAGE CXX)
