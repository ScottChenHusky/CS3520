//
//  LinkedList.cpp
//  ASGN5
//
//  Created by Scott Chen on 3/25/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//
#include <iostream>
#include "LinkedList.hpp"
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    this->length = 0;
    this->next = NULL;
}

template <class T>
LinkedList<T>::LinkedList(T value) {
    this->length = 1;
    this->value = value;
    this->next = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    if (this->next != NULL) {
        delete this->next;
    }
    this->value = other.value;
    this->next = other.next;
    this->length = other.length;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        if (this->next != NULL) {
            delete this->next;
        }
        this->value = other.value;
        this->next = other.next;
        this->length = other.length;
        
    }
    return *this;
}

template <class T>
T& LinkedList<T>::front() {
    if (this->length == 0) {
        string s = "List is empty, there is nothing to return";
        throw s;
    } else {
        return this->value;
    }
}

template <class T>
T& LinkedList<T>::back() {
    if (this->length == 0) {
        string s = "List is empty, there is nothing to return";
        throw s;
    } else {
        return this->at(this->length - 1);
    }
}

template <class T>
void LinkedList<T>::pop_front() {
    if (this->length == 0) {
        throw "List is empty, there is nothing to pop";
    } else {
        this->length -= 1;
        this->value = this->next->value;
        this->next = this->next->next;
    }
}

template <class T>
void LinkedList<T>::pop_back() {
    if (this->length == 0) {
        throw "List is empty, there is nothing to pop";
    } else {
        if (this->length == 1) {
            *this = *(new LinkedList);
            this->length = 0;
        } else {
            LinkedList* head = this;
            LinkedList* end = this->next;
            while(end->next != NULL) {
                head = end;
                end = end->next;
            }
            delete end;
            head->next = NULL;
            this->length -= 1;
        }
    }
}

template <class T>
void LinkedList<T>::push_front(T value) {
    LinkedList<T>* temp = new LinkedList<T>(*this);
    this->value = value;
    this->next = temp;
    this->length += 1;
}

template <class T>
void LinkedList<T>::push_back(T value) {
    LinkedList<T>* ptr = this;
    int idx = this->length;
    while (idx > 1) {
        ptr = ptr->next;
        idx -= 1;
    }
    LinkedList<T>* newNode = new LinkedList<T>(value);
    ptr->next = newNode;
    this->length += 1;
}

template <class T>
void LinkedList<T>::insert(int idx, T value) {
    if (idx > this->length) {
        std::string s = "Index out of bound, please choose index between 0 and length";
        throw s;
    } else {
        LinkedList<T>* ptr = this;
        
        while(idx > 1) {
            ptr = ptr->next;
            idx--;
        }
        
        if (idx == 0) {
            this->push_front(value);
        } else {
            LinkedList<T>* temp = new LinkedList<T>(value);
            temp->next = ptr->next;
            ptr->next = temp;
            this->length += 1;
        }
    }
}

template <class T>
void LinkedList<T>::remove(int idx) {
    if (idx >= this->length || idx < 0) {
        std::string s = "Index out of bound, please choose index between 0 and length";
        throw s;
    }
    
    if (idx == 0) {
        this->pop_front();
    } else {
        LinkedList* ptr = this;
        while(idx > 1) {
            ptr = ptr->next;
            idx--;
        }
        LinkedList* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        this->length -= 1;
    }
    
}

template <class T>
bool LinkedList<T>::find(T value) {
    LinkedList<T>* ptr = this;
    while(ptr != NULL) {
        if (ptr->value == value) {
            return true;
        } else {
            ptr = ptr->next;
        }
    }
    return false;
}

template <class T>
int LinkedList<T>::size() {
    return this->length;
}

template <class T>
T& LinkedList<T>::at(int idx) {
    if (idx < 0 || idx >= this->length) {
        std::string s = "Index out of bound, please choose index between 0 and length";
        throw s;
    }
    
    LinkedList<T>* ptr = this;
    while(idx > 0) {
        ptr = ptr->next;
        idx--;
    }
    return ptr->value;
}

template <class T>
T& LinkedList<T>::operator[] (int idx) {
    return this->at(idx);
}

