#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <Windows.h>
#include "color_codes.h"

int main() {
    // set window title
    SetConsoleTitle("C++ Project Maker");

    std::string project_name;
    std::string directory;

    std::cout << Bright_Blue << "Enter the name of your project: " << Reset;
    std::getline(std::cin, project_name);
    std::cout << Bright_Blue << "Enter the directory where you want to create the project: " << Reset;
    std::getline(std::cin, directory);

    // check for special characters and spaces in project name
    if (project_name.find_first_of("!@#$%^&*()[]{}<>,.?/\\\"\' ") != std::string::npos) {
        std::cout << Red << "ERROR: Project name cannot contain special characters or spaces." << Reset << std::endl;
        return 1;
    }

    auto start_time = std::chrono::system_clock::now();

    // create directory
    std::cout << Bright_Blue << "Creating directory..." << Reset << std::endl;
    std::filesystem::create_directory(directory + "/" + project_name);
    std::cout << Green << "Directory created." << Reset << std::endl;

    // create main.cpp file
    std::cout << Bright_Blue << "Creating main.cpp file...\n" << Reset;
    std::ofstream main_file(directory + "/" + project_name + "/main.cpp");
    main_file << "#include <iostream>" << std::endl << std::endl;
    main_file << "int main() {" << std::endl;
    main_file << "    std::cout << \"This is placeholder code for the C++ project maker. Feel free to add on to this code, or delete this code and start from scratch.\";" << std::endl;
    main_file << "    return 0;" << std::endl;
    main_file << "}" << std::endl;
    main_file.close();
    std::cout << Green << "main.cpp file created." << Reset << std::endl;

    // create makefile
    std::cout << Bright_Blue << "Creating makefile...\n" << Reset;
    std::ofstream makefile(directory + "/" + project_name + "/makefile");
    makefile << "CC = g++" << std::endl;
    makefile << "CFLAGS = -std=c++17" << std::endl << std::endl;
    makefile << project_name + ".exe: main.cpp" << std::endl;
    makefile << "    $(CC) $(CFLAGS) -o " + project_name + ".exe main.cpp" << std::endl;
    makefile.close();
    std::cout << Green << "makefile created." << Reset << std::endl;

    auto end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    std::cout << Yellow << "Process finished in " << elapsed_seconds.count() << "s!" << Reset << std::endl;

    return 0;
}
