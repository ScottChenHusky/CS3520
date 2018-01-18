#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

int main() {
    int lineNumber = 0;
    long longest = 0;
    std::string line;
    std::ifstream f;
    std::map<int, std::string> file;

    f.open("frame_input.txt");
    if (!f) {
        std::cout << "Can't find the file. Exit." << std::endl;
        return 0;
    }

    while (std::getline(f, line)) {
        if (line.length() > longest) {
            longest = line.length();
        }

        file[lineNumber] = line;
        lineNumber += 1;
    }
   
    if (lineNumber > 0) { 
        std::cout << "*" << std::setw(longest + 3.0) << 
        std::setfill('*') << "*" << std::endl;
    }

    int i = 0;
    while (i < lineNumber) {
        std::cout << "* " << file[i] << 
        std::setw(longest + 2.0 - file[i].length()) << 
        std::setfill(' ') << " *" << std::endl;
        i++;
    }
    
    if (lineNumber > 0) {
        std::cout << "*" << std::setw(longest + 3.0) <<
        std::setfill('*') << "*" << std::endl;
    }
    return 0;
}



