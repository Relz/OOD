CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(lw3)

SET(CMAKE_CXX_STANDARD 14)

ADD_EXECUTABLE(
		lw3 main.cpp
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
		Creator/CircleCreator.h)
