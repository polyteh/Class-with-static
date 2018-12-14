cmake_minimum_required(VERSION 3.1)
# This is a comment !

set(CMAKE_CXX_STANDARD 14)
project(class_test)
set(SRCS 	
			Transport.h
			Transport.cpp
	)
add_executable(class_test class_test.cpp ${SRCS})
