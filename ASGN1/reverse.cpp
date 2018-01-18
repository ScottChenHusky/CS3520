#include <iostream>
#include <fstream>
#include <map>


int main() {
    int lineNumber = 0;
    std::string line;
    std::ifstream f;
    std::map<int, std::string> reversed_file;

    f.open("reverse_input.txt");
    if (!f) {
        std::cout << "Can't find the file. Exit." << std::endl;
    }

    while (std::getline(f, line)) {
        std::string reversed_val = "";
        for (long i = (line.length() - 1); i >= 0; i--) {
            reversed_val += line.at(i);
        }
        reversed_file[lineNumber] = reversed_val;
        lineNumber += 1;
    }
    
    while ((lineNumber -= 1) >= 0) {
        std::cout << reversed_file[lineNumber] << std::endl;
    }

    return 0;
}
