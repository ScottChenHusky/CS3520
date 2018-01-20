#include <iostream>
#include <fstream>
#include <map>

/**
 * This program reads in lines of text from the file named reverse_input.txt 
 * (in the same folder as the executable) until end of file, 
 * and then prints each line in reverse order with the characters in each 
 * line reversed. If the input file cannot be opened or read, 
 * the program prints File error to standard error and exits.
 */
int main() {
    int lineNumber = 0;
    std::string line;
    std::ifstream f;
    std::map<int, std::string> reversed_file;

    // open the file
    f.open("reverse_input.txt");

    // exit the program if failed to open
    if (!f) {
        std::cout << "Can't find the file. Exit." << std::endl;
    }

    // read the file contents, and add each line to map with index
    while (std::getline(f, line)) {
        std::string reversed_val = "";
        for (long i = (line.length() - 1); i >= 0; i--) {
            reversed_val += line.at(i);
        }
        reversed_file[lineNumber] = reversed_val;
        lineNumber += 1;
    }
    
    // print contents in the map in the reverse order.
    while ((lineNumber -= 1) >= 0) {
        std::cout << reversed_file[lineNumber] << std::endl;
    }

    return 0;
}
