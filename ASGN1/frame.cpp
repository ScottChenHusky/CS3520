#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

/**
 * This program reads in lines of text from the file named frame_input.txt 
 * (in the same folder as the executable) until end of file, 
 * and then prints the text that was read in with a square frame 
 * of * characters around the text, horizontally separated by at least one 
 * space. If the input file cannot be opened or read, 
 * the program prints File error to standard error and exits.
 */
int main() {
    int lineNumber = 0;
    long longest = 0;
    std::string line;
    std::ifstream f;
    std::map<int, std::string> file;

    // open the file
    f.open("frame_input.txt");

    // exit the program, if failed to open.
    if (!f) {
        std::cout << "Can't find the file. Exit." << std::endl;
        return 0;
    }

    // read line and keep tracking of the longest line.
    while (std::getline(f, line)) {
        if (line.length() > longest) {
            longest = line.length();
        }

        file[lineNumber] = line;
        lineNumber += 1;
    }
   

    // print the first line of *
    if (lineNumber > 0) { 
        std::cout << "*" << std::setw(longest + 3.0) << 
        std::setfill('*') << "*" << std::endl;
    }

    // print the contents with *
    int i = 0;
    while (i < lineNumber) {
        std::cout << "* " << file[i] << 
        std::setw(longest + 2.0 - file[i].length()) << 
        std::setfill(' ') << " *" << std::endl;
        i++;
    }
    
    // print the last line of *
    if (lineNumber > 0) {
        std::cout << "*" << std::setw(longest + 3.0) <<
        std::setfill('*') << "*" << std::endl;
    }
    return 0;
}



