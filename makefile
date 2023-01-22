CC = g++
CFLAGS = -std=c++17

project.exe: main.cpp
	$(CC) $(CFLAGS) -o project.exe main.cpp
