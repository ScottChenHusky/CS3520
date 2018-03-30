//
//  LinkedList.hpp
//  ASGN5
//
//  Created by Scott Chen on 3/25/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T value);
    LinkedList(const LinkedList& other);
    LinkedList& operator= (const LinkedList& other);
    T& front();
    T& back();
    void pop_front();
    void pop_back();
    void push_front(T value);
    void push_back(T value);
    void insert(int idx, T value);
    void remove(int idx);
    bool find(T value);
    int size();
    T& at(int idx);
    T& operator[] (int idx);
    
private:
    int length;
    T value;
    LinkedList* next = NULL;
};

#endif /* LinkedList_hpp */
