#include <iostream>

int fibonacci(int idx, int num1, int num2) {
    if (idx == 25) {
        return 0;
    }
    int next = num1 + num2;
    std::cout << next << std::endl;
    return fibonacci(idx + 1, num2, next);
};

int main() {
    int num1 = 1;
    int num2 = 1;
    
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    
    fibonacci(2, num1, num2);
    
    return 0;
}
