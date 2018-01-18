#include <iostream>
#include <fstream>

int main() {

    int temp = 0;
    int result = 0;

    std::cout << "Please enter integers: " << std::endl;
    while (!std::cin.eof())
    {
        if (!std::cin) {
            std::cout << "The result is: " << result << std::endl;
            std::cout << "Input is not integer(s), exit program!!" <<std::endl;
            return 0;
        } else {
            std::cin >> temp;
        }
        
        result += temp;
        temp = 0;
    }

    std::cout << std::endl;
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
