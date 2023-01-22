#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

int main() {
    std::string project_name;
    std::string directory;

    std::cout << "Enter the name of your project: ";
    std::getline(std::cin, project_name);
    std::cout << "Enter the directory where you want to create the project: ";
    std::getline(std::cin, directory);

    // check for special characters and spaces in project name
    if (project_name.find_first_of("!@#$%^&*()[]{}<>,.?/\\\"\' ") != std::string::npos) {
        std::cout << "Error: Project name cannot contain special characters or spaces." << std::endl;
        return 1;
    }

    // create directory
    std::cout << "Creating directory..." << std::endl;
    std::filesystem::create_directory(directory + "/" + project_name);
    std::cout << "Directory created." << std::endl;

    // create main.cpp file
    std::cout << "Creating main.cpp file...\n";
    std::ofstream main_file(directory + "/" + project_name + "/main.cpp");
    main_file << "#include <iostream>" << std::endl << std::endl;
    main_file << "int main() {" << std::endl;
    main_file << "    std::cout << \"This is placeholder code for the C++ project maker.\";" << std::endl;
    main_file << "    return 0;" << std::endl;
    main_file << "}" << std::endl;
    main_file.close();
    std::cout << "main.cpp file created." << std::endl;

    // create makefile
    std::cout << "Creating makefile...\n";
    std::ofstream makefile(directory + "/" + project_name + "/makefile");
    makefile << "CC = g++" << std::endl;
    makefile << "CFLAGS = -std=c++17" << std::endl << std::endl;
    makefile << project_name + ".exe: main.cpp" << std::endl;
    makefile << "    $(CC) $(CFLAGS) -o " + project_name + ".exe main.cpp" << std::endl;
    makefile.close();
    std::cout << "makefile created." << std::endl;

    return 0;
}
