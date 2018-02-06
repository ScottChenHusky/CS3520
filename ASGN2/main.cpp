//
//  main.cpp
//  ASGN2
//
//  Created by Scott Chen on 1/26/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Animal.hpp"
#include <string.h>

int main(int argc, const char * argv[]) {
    
    // create an animal using default constructor;
    Animal a1;
    
    // create an animal by specifying first name, last name, and age;
    char* lastName = new char[4];
    int* age = new int(5);
    strcpy(lastName, "last");
    Animal a2("first", lastName, age);
    delete[] lastName;
    delete age;

    // create an animal by copying the values from animal a2;
    Animal a3(a2);
    
    //compare a1 with a3, the result should be false: a1 != a3;
    if (a1 == a3) {
        std::cout << "a1 == a3" << std::endl;
    } else {
        std::cout << "a1 != a3" << std::endl;
    }
    
    // assign a1 with a3 using = operator;
    a1 = a3;

    //compare a1 with a3, the result should be true: a1 == a3;
    if (a1 == a3) {
        std::cout << "a1 == a3" << std::endl;
    } else {
        std::cout << "a1 != a3" << std::endl;
    }
    
    Animal a4 = a1 + a3;
    // print out a1
    std::cout << "a1 is: " << a1 << std::endl;
    // print out a3
    std::cout << "a3 is: " << a3 << std::endl;
    // print out a4
    std::cout << "a4 is a1 + a3: " << a4 << std::endl;
    
    // updating a4 value using cin >>
    std::cout << "Please enter: first_name, last_name age, age for a4: "
    << std::endl;
    std::cin >> a4;
    // print a4 with new value
    std::cout << a4 << std::endl;
    
    // add 1 to a4's age
    ++a4;
    std::cout << a4 << std::endl;
    
    // get a4's first name
    std::cout << a4.getFirstName() << std::endl;
    
    // get a4's last name
    std::cout << a4.getLastName() << std::endl;
    
    // get a4's age
    std::cout << *a4.getAge() << std::endl;
    
    // set a4's first name
    a4.setFirstName("hello");
    
    // set a4's last name
    char* newLastName = new char[5];
    strncpy(newLastName, "world", 5);
    a4.setLastName(newLastName);
    delete[] newLastName;
    
    // set a4's age
    int * newAge = new int(666);
    a4.setAge(newAge);
    delete newAge;
    
    // print out new a4 with values using setter
    std::cout << a4 << std::endl;
    
    // adding nicknames to a4
    const char* nickname = "scott";
    a4.addNickName(nickname);
    
    nickname = "chen";
    a4.addNickName(nickname);
    
    nickname = "yoyo";
    a4.addNickName(nickname);

    nickname = "skrskr";
    a4.addNickName(nickname);
    
    // a4 already has 4 nicknames, should not add this one.
    nickname = "homie";
    a4.addNickName(nickname);
    
    // print out a4's nicknames and free the pointers
    char** nicknames = a4.getNickNames();
    for (int i = 0; i < 4; i++) {
        std::cout << nicknames[i] << std::endl;
    }
    
    for (int i = 3; i >= 0; i--) {
        delete[] nicknames[i];
    }
    delete[] nicknames;
    
    
    // feed a4
    int* food0 = new int(0);
    int* food1 = new int(1);
    int* food2 = new int(2);
    int* food3 = new int(3);
    
    a4.feed(food0);
    a4.feed(food1);
    a4.feed(food2);
    a4.feed(food3);
    
    delete food0;
    delete food1;
    delete food2;
    delete food3;
    
    // get a4's feedVector and free the return vector memory 
    std::vector<int*> v = a4.getFeedVector();
    
    std::cout << "The vector size is: " << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << i << ": "<< *v[i] << std::endl;
        delete v[i];
        v[i] = NULL;
    }
    
    v.clear();
    std::cout << "After deleting pointers, The vector size is now: "
    << v.size() << std::endl;
    
    
    // Using copy constructor is an example of passing constant reference;
    // The reason to pass by reference is, object usually has large size,
    // passing py reference is technically passing an address,
    // which saves a lot memory
    Animal a8(a2);
}
