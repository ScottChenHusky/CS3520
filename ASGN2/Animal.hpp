//
//  Animal.hpp
//  ASGN2
//
//  Created by Scott Chen on 1/26/18.
//  Copyright © 2018 Scott Chen. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

/**
 * To represent the Animal class
 */
class Animal {
public:
    /**
     * The constructor of animal
     */
    Animal();
    
    /**
     * The destructor of animal
     */
    ~Animal();
    
    /**
     * The constructor of animal
     * first: the first name of an animal in string
     * last: the last name of an animal in char*
     * age: the age of an animal which is a int*
     */
    Animal(string first, char* last, int* age);
    
    /**
     * The copy constructor of animal
     * other: the other animal which is const Animal&
     */
    Animal(const Animal& other);
    
    /**
     * Overload medthod of assign operation of animal
     * other: the other animal which is const Animal&
     * return: the animal&
     */
    Animal& operator=(const Animal& other);
    
    /**
     * Overload medthod of equality check operation of animal
     * other: the other animal which is const Animal&
     * return: true if they are equal, false otherwise
     */
    bool operator==(const Animal& other);
    
    /**
     * Overload medthod of + operation of animal
     * other: the other animal which is const Animal&
     * return: a new animal which has name is concatenation of the two animals
     *         and age is the sum of the age of the two animals
     */
    Animal operator+(const Animal& other);
    
    /**
     * Overload medthod of << operation of animal
     * prints out the animal first name, last name, and age
     */
    friend ostream& operator<<(ostream& output, const Animal& other);
    
    /**
     * Overload medthod of >> operation of animal
     * reads animal first name, last name, and age from console
     */
    friend istream& operator>>(istream& input, Animal& other);
    
    /**
     * Overload medthod of ++ operation of animal
     * ages the animal by adding 1 to its age.
     */
    void operator++();
    
    /**
     * get the first name of this animal
     */
    string getFirstName();
    
    /**
     * get the last name of this animal
     */
    char* getLastName();
    
    /**
     * get the age of this animal
     */
    int* getAge();
    
    /**
     * set first name for this animal
     * firstName: the new first name in string
     */
    void setFirstName(string firstName);
    
    /**
     * set last name for this animal
     * lastName: the new last name in char*
     */
    void setLastName(char* lastName);
    
    /**
     * set age for this animal
     * age: the new age in int*
     */
    void setAge(int* age);
    
    /**
     * add a nickname to the animal, if it has less than 4 nicknames.
     * nickName: the new nickname in const char*
     */
    void addNickName(const char* nickName);
    
    /**
     * to feed an animal by adding int* to the end of its feedVector
     * carllories: the carllories of the food in int*
     */
    void feed(int* carllories);
    
    /**
     * get the feedVector from this animal by returning a new object
     * return: vector<int*>
     */
    vector<int*> getFeedVector();
    
    /**
     * get all the nicknames of this animal
     * return: nicknames in char**
     */
    char** getNickNames();
    
    /**
     * to clear pointers in feedVector;
     */
    void clearFeedVector();
    
    /**
     * to copy pointers in feedVector;
     */
    void copyFeedVector(const vector<int*>& other);
    
private:
    // The first name of the animal
    string fname;
    // The last name of the animal
    char* lname;
    // The age of the animal
    int* age;
    // How many times and how much the animal has been fed
    vector<int*> feedVector;
    // Stores up to 4 nicknames for the animal
    const char* nicknames[4];

};

#endif /* Animal_hpp */
