//
//  LinkedList.cpp
//  ASGN5
//
//  Created by Scott Chen on 3/25/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//
#include <iostream>
#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList() {}

template <class T>
LinkedList<T>::~LinkedList() {  
    delete this->next;
}

template <class T>
LinkedList<T>::LinkedList(T value) {
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
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        if (this->next != NULL) {
            delete this->next;
        }
        this->value = other.value;
        this->next = other.next;
        
    }
    return *this;
}

template <class T>
T& LinkedList<T>::front() {
    return this->value;
}

template <class T>
T& LinkedList<T>::back() {
    LinkedList<T>* ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    T* result = &(ptr->value);

    return *result;
}

template <class T>
void LinkedList<T>::pop_front() {
    *this = *(this->next);
}

template <class T>
void LinkedList<T>::pop_back() {
    if (this->next == NULL) {
        *this = NULL;
    } else {
        LinkedList* head = this;
        LinkedList* end = this->next;
        while(end->next != NULL) {
            head = end;
            end = end->next;
        }
        delete end;
        head->next = NULL;
    }
}

template <class T>
void LinkedList<T>::push_front(T value) {
    LinkedList<T>* temp = new LinkedList<T>(*this);
    this->value = value;
    this->next = temp;
}

template <class T>
void LinkedList<T>::push_back(T value) {
    LinkedList<T>* ptr = this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    LinkedList<T>* newNode = new LinkedList<T>(value);
    ptr->next = newNode;
}

template <class T>
void LinkedList<T>::insert(int idx, T value) {
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
    }
}

template <class T>
void LinkedList<T>::remove(int idx) {
    if (idx >= this->size() || idx < 0) {
        return;
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
    int i = 1;
    LinkedList<T>* ptr = this;
    while(ptr->next != NULL) {
        ptr = ptr->next;
        i += 1;
    }
    return i;
}

template <class T>
T& LinkedList<T>::at(int idx) {
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

