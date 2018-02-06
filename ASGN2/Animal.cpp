//
//  Animal.cpp
//  ASGN2
//
//  Created by Scott Chen on 1/26/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//

#include <iostream>
#include "Animal.hpp"
#include <string.h>

Animal::Animal() {
    std::string s = "";
    this->age = new int(0);
    this->fname = "";
    this->lname = new char[0];
    std::cout << "The animal is created by default constructor" << std::endl;
    this->nicknames[0] = "";
    this->nicknames[1] = "";
    this->nicknames[2] = "";
    this->nicknames[3] = "";
}

Animal::~Animal() {
    // delte age pointer
    delete this->age;
    this->age = NULL;
    // delte lname pointer
    delete[] this->lname;
    this->lname = NULL;
    // delete pointers in feedVector
    this->clearFeedVector();
    std::cout << "The animal is deleted" << std::endl;
}

Animal::Animal(string first, char* last, int* age) {
    this->fname = first;
    char* temp = new char[strlen(last)];
    for (int i = 0; i < strlen(last); i++) {
        temp[i] = last[i];
    }
    this->lname = temp;
    this->age = new int(*age);
    std::cout << "The animal is created: " << fname << " " << lname <<
    " " << *age << std::endl;
}

Animal::Animal(const Animal& other) {
    this->fname = other.fname;
    // delete lname pointer
    delete[] this->lname;
    this->lname = NULL;
    string otherLastName = other.lname;
    char* temp = new char[otherLastName.length()];
    for (int i = 0; i < otherLastName.length(); i++) {
        temp[i] = otherLastName[i];
    }
    this->lname = temp;
    // delete age pointer
    delete this->age;
    this->age = new int(*other.age);
    this->clearFeedVector();
    this->copyFeedVector(other.feedVector);
    for (int i = 0; i < 4; i++) {
        this->nicknames[i] = other.nicknames[i];
    }
    std::cout << "The animal is created by copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    this->fname = other.fname;
    // delete lname pointer
    delete[] this->lname;
    this->lname = NULL;
    string otherLastName = other.lname;
    char* temp = new char[otherLastName.length()];
    for (int i = 0; i < otherLastName.length(); i++) {
        temp[i] = otherLastName[i];
    }
    this->lname = temp;
    // delete lname pointer
    delete this->age;
    this->age = new int(*other.age);
    // delete pointers in feedVector
    this->clearFeedVector();
    this->copyFeedVector(other.feedVector);
    for (int i = 0; i < 4; i++) {
        this->nicknames[i] = other.nicknames[i];
    }
    std::cout << "The animal is created by = operator" << std::endl;
    return *this;
}

bool Animal::operator==(const Animal& other) {
    string thisLastName = this->lname;
    string otherLastName = other.lname;
    
    return (*this->age == *other.age) &&
    (this->fname.compare(other.fname) == 0) &&
    (thisLastName.compare(otherLastName) == 0);
}

Animal Animal::operator+(const Animal& other) {
    Animal newAnimal;

    newAnimal.fname = this->fname + other.fname;

    string s1 = this->lname;
    string s2 = other.lname;
    string s = s1 + s2;
    char* temp = new char[s.length() + 1];
    for (int i = 0; i <= s.length(); i++) {
        temp[i] = s[i];
    }
    newAnimal.lname = temp;

    newAnimal.age = new int (*this->age + *other.age);
    return newAnimal;

}

ostream& operator<<(ostream& output, const Animal& other) {
    return output << other.fname << " " << other.lname << ": " << *other.age;
}

istream& operator>>(istream& input, Animal& other) {
    input >> other.fname;
    string last;
    input >> last;
    char* temp = new char[last.length()];
    // delete lname pointer
    delete[] other.lname;
    other.lname = NULL;
    for (int i = 0; i < last.length(); i++) {
        temp[i] = last[i];
    }
    other.lname = temp;
    int newAge;
    input >> newAge;
    // delete age pointer
    delete other.age;
    other.age = new int(newAge);
    return input;
}

void Animal::operator++() {
    int currentAge = *this->age;
    // delete age pointer
    delete this->age;
    this->age = new int(currentAge + 1);
}

string Animal::getFirstName() {
    return this->fname;
}

char* Animal::getLastName() {
    char* result = new char[strlen(this->lname)];
    strncpy(result, this->lname, strlen(this->lname));
    return result;
}

int* Animal::getAge() {
    int* result = new int(*this->age);
    return result;
}

void Animal::setFirstName(string firstName) {
    this->fname = firstName;
}

void Animal::setLastName(char* lastName) {
    // delete lname pointer
    delete this->lname;
    this->lname = NULL;
    
    char* temp = new char[strlen(lastName)];
    for (int i = 0; i < strlen(lastName); i++) {
        temp[i] = lastName[i];
    }
    this->lname = temp;
}

void Animal::setAge(int* age) {
    // delete age pointer
    delete this->age;
    this->age = new int(*age);
}

void Animal::addNickName(const char* nickName) {
    for (int i = 0; i < 4; i++) {
        string nickname = this->nicknames[i];
        if (nickname.compare("") == 0) {
            this->nicknames[i] = nickName;
            return;
        }
    }
    std::cout << "This animal alread has 4 nicknames" << std::endl;
}

void Animal::feed(int* carllories) {
    this->feedVector.push_back(new int(*carllories));
}

vector<int*> Animal::getFeedVector() {
    vector<int*> result;
    for (int i = 0; i < this->feedVector.size(); i++) {
        result.push_back(new int(*this->feedVector[i]));
    }
    return result;
}

char** Animal::getNickNames() {
    char** result;
    result = new char*[4];
    for (int i = 0; i < 4; i++) {
        string s = this->nicknames[i];
        char* temp = new char[s.length()];
        for (int j = 0; j < s.length(); j++) {
            temp[j] = s[j];
        }
        result[i] = temp;
    }
    return result;
}

void Animal::clearFeedVector() {
    for (int i = 0; i < this->feedVector.size(); i++) {
        // delete feed pointer
        delete this->feedVector.back();
        this->feedVector.back() = NULL;
    }
    this->feedVector.clear();
}

void Animal::copyFeedVector(const vector<int*>& other) {
    for (int i = ((int) other.size() - 1); i >= 0; i--) {
        this->feedVector.push_back(new int(*other[i]));
    }
}

