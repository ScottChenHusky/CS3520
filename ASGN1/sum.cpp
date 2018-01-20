#include <iostream>
#include <fstream>

/**
 * This program reads whitespace-separated integers from standard input until 
 * end of-file or any stream error conditions are encountered, and then prints 
 * the sum of the integers. Note that on Linux you can use Ctrl+D to send 
 * end-of-file to standard input.
 */
int main() {

    int temp = 0;
    int result = 0;

    // ask the user to enter inputs.
    std::cout << "Please enter integers: " << std::endl;

    // keep reading inputs until the end-of-file or wrong inputs.
    while (!std::cin.eof())
    {
        if (!std::cin) {
            std::cout << "The result is: " << result << std::endl;
            std::cout << "Input is not integer(s), exit program!!" <<std::endl;
            return 0;
        } else {
            std::cin >> temp;
        }
        
        // mutate the result value.
        result += temp;
        temp = 0;
    }

    // print the final result.
    std::cout << std::endl;
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
