//
//  main.cpp
//  ASGN5
//
//  Created by Scott Chen on 3/25/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

int main(int argc, const char * argv[]) {

    LinkedList<int> list(3);
    std::cout << list.size() << std::endl;
    
    return 0;
}
