CC = g++
CFLAGS = -std=c++17

project.exe: main.cpp
	$(CC) $(CFLAGS) -o bin/project.exe main.cpp

run:
	.\bin/project.exe