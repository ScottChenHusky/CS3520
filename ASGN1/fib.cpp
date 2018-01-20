#include <iostream>

/**
 * Funtion fibonacci takes in the fibonacci number index 
 * and two fibonacci numbers, returns the next fibonacci number.
 * @param idx: the idx of the fibonacci number will be returned.
 * @param num1: the first fibonacci number
 * @param num2: the second fibonacci number
 * @return: the next fibonacci number.
 */
int fibonacci(int idx, int num1, int num2) {
    if (idx == 25) {
        return 0;
    }
    int next = num1 + num2;
    std::cout << next << std::endl;
    return fibonacci(idx + 1, num2, next);
};

/**
 * This is the main funciton of fibonacci number
 * Which prints the fist 25 fibonacci numbers
 */
int main() {
    int num1 = 1;
    int num2 = 1;
    
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    
    fibonacci(2, num1, num2);
    
    return 0;
}
