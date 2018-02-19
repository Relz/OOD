CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(lw5)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(
		lw5 main.cpp
		IShape.h
		Shape.h
		Point.h
		Rectangle.h
		Triangle.h
		Parser.h
		Circle.h
		Creator/ShapeCreator.h
		Creator/RectangleCreator.h
		Creator/TriangleCreator.h
		Creator/CircleCreator.h
		LongInteger/Digit.h
		LongInteger/DigitExtensions.cpp
		LongInteger/DigitExtensions.h
		LongInteger/LongInteger.h MathHelper.h Printer.h Visitor.h)
