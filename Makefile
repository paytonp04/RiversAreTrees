all: RiversAreTrees

RiversAreTrees: main.cpp definitions.cpp header.h
	g++ -g -Wall -std=c++11 main.cpp definitions.cpp -o outputExecutable
	./outputExecutable