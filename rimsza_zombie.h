//zombie .h

//importing libraries and files and checking for duplicates
#pragma once
#ifndef RIMSZA_ZOMBIE_H
#define RIMSZA_ZOMBIE_H
#include <iostream>
#include <vector>
#include <string>
#include "termcolor.hpp"

//using the std namespace
using namespace std;

class Zombie {
    //zombie class contains one private variable, a letter
    private:
        char letter;

    //public members
    public:
        //Zombie constructor takes in a char to initialize zombie object
        Zombie(char newLetter);

        //defualt zombie constructor randomly decides the char for letter when making zombie object
        Zombie();

        //prints the Zombie object with apropriate formatting
        void to_String();

        //returns the letter as a char
        char getLetter();

        //takes in a char to set the zombie letter. returns void
        void setLetter(char newLetter);

        //overriding the == operator for the zombie class
        bool operator==(Zombie);

        //declaring friendhsip and overridiing the << operator for the zombie class
        friend std::ostream &operator<<(std::ostream&out, Zombie);

        //~Zombie();
};

#endif