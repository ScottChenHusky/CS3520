#include <iostream>

/**
 * The main function of fizzbuzz.
 * Which pritns numbers between 1 and 100
 * if the number is multiple of 3, prints "Fizz"
 * if the number is multiple of 5, prints "Buzz"
 * if the number is mutiple of both 3 and 5, prints "FizzBuzz"
 */
int main() {

    for(int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            if (i % 5 == 0) {
                std::cout << "FizzBuzz" << std::endl;
            } else {
                std::cout << "Fizz" << std::endl;
            }
        } else if (i % 5 == 0) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
        
    }
    
    return 0;
}
