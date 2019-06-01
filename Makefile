all: statexam

statexam: stattest.cpp stats.cpp stats.h
	g++ -o statexam stattest.cpp stats.cpp stats.h -o statexam
