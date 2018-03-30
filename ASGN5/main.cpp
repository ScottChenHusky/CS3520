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
using namespace std;

int main(int argc, const char * argv[]) {
    
    // test default constructor
    LinkedList<int> l1;
    
    // test size of empty list
    cout << l1.size() << endl;
    
    // try get the first element from empty list
    try {
        l1.front();
    } catch (string e) {
        // should print out nothing to return.
        cout << e << endl;
    }
    
    // try get the last element from empty list
    try {
        l1.back();
    } catch (string e) {
        // should print out nothing to return.
        cout << e << endl;
    }
    
    // test push front
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    // should get 3
    cout << "size expected = 3; getting: " << l1.size() << endl;

    // front should be 3 from [3, 2, 1]
    cout << "front expected = 3; getting: " << l1.front() << endl;

    // back should be 1 from [3, 2, 1]
    cout << "back expected = 1; getting: " << l1.back() << endl;

    l1.push_back(-1);
    l1.push_back(-2);
    l1.push_back(-3);
    
    // should get 6
    cout << "size expected = 6; getting: " << l1.size() << endl;
    
    // front should be 3 from [3, 2, 1, -1, -2, -3]
    cout << "front expected = 3; getting: " << l1.front() << endl;
    
    // back should be -3 from [3, 2, 1, -1, -2, -3]
    cout << "back expected = -3; getting: " << l1.back() << endl;
    
    l1.pop_front();
    // should get 5
    cout << "size expected = 5; getting: " << l1.size() << endl;
    
    // front should be 2 from [2, 1, -1, -2, -3]
    cout << "front expected = 2; getting: " << l1.front() << endl;
    
    // back should be -3 from [2, 1, -1, -2, -3]
    cout << "back expected = -3; getting: " << l1.back() << endl;
    
    l1.pop_back();
    
    // should get 4
    cout << "size expected = 4; getting: " << l1.size() << endl;
    
    // front should be 2 from [2, 1, -1, -2]
    cout << "front expected = 2; getting: " << l1.front() << endl;
    
    // back should be -2 from [2, 1, -1, -2]
    cout << "back expected = -2; getting: " << l1.back() << endl;
    
    l1.insert(0, 9);
    
    // should get 5
    cout << "size expected = 5; getting: " << l1.size() << endl;
    
    // front should be 9 from [9, 2, 1, -1, -2]
    cout << "front expected = 9; getting: " << l1.front() << endl;
    
    // back should be -2 from [2, 1, -1, -2]
    cout << "back expected = -2; getting: " << l1.back() << endl;
    
    l1.remove(0);
    
    // should get 4
    cout << "size expected = 4; getting: " << l1.size() << endl;
    
    // front should be 2 from [2, 1, -1, -2]
    cout << "front expected = 2; getting: " << l1.front() << endl;
    
    // back should be -2 from [2, 1, -1, -2]
    cout << "back expected = -2; getting: " << l1.back() << endl;
    
    // testing find
    if (l1.find(-2)) {
        cout << "should be printed out " << "find -2" << endl;
    } else {
        cout << "shouldn't be printed out " << "can't find -2" << endl;
    }
    
    if (l1.find(-5)) {
        cout << "shouldn't be printed out " << "find -5" << endl;
    } else {
        cout << "should be printed out " << "can't find -5" << endl;
    }
    
    // testing at
    for (int i = 0; i < l1.size(); i++) {
        cout << "at " << i << ": " << l1.at(i) << endl;
    }
    
    // testing []
    for (int i = 0; i < l1.size(); i++) {
        cout << "[" << i << "]: " << l1[i] << endl;
    }
    
    return 0;
}
