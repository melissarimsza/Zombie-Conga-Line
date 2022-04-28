//zombie .cpp
#include "rimsza_zombie.h"
#include <string>
#include <iostream>
#include "termcolor.hpp"


//Zombie(char) is the class constrcutor
//takes in a char and sets it to the Zombie letter
Zombie::Zombie(char newLetter) {
    letter = newLetter;
}

//Zombie() is the default constructor for the zombie class
//sets the letter by getting a random number and coding the number to an apropriate character
Zombie::Zombie() {

    //makes sure the random numbers are different everytime
    //srand(time(NULL));

    //getting the random number
    int randNum = rand() % 7 + 1;

    //assigning the letter based on the random number
    switch (randNum) {
        case 1:
            letter = 'R';
            break;
        case 2:
            letter = 'G';
            break;
        case 3: 
            letter = 'B';
            break;
        case 4: 
            letter = 'C';
            break;
        case 5:
            letter = 'M';
            break;
        case 6:
            letter = 'Y';
            break;
        case 7:
            letter = 'K';
            break;
        default:
            letter = 'B';
    }
}

//to_String() returns a Zombie object's information (letter) in the format 
void Zombie::to_String() {
    cout << "[" << letter << "]";
}

//getLetter() returns the Zombie's letter as a char
char Zombie::getLetter() {
    return this->letter;
}

//setLetter(char) changes the Zombie object's letter, returns void
void Zombie::setLetter(char newLetter) {
    letter = newLetter;
}

//operator==(Zombie) overrides the == operator for the zombie class
bool Zombie::operator==(Zombie other) {
    //compares the letter of the original zombie to the passed in zombie
    //if the letters match return true
    if (other.letter == getLetter()) {
        return true;
    }
    //otherwise return false
    else {
        return false;
    }
}

//overrides the << operator for the Zombie class
std::ostream &operator<<(std::ostream&out, Zombie outputZom) {
    //determines which color to make the output based on the letter
    if (outputZom.getLetter() == 'R') {
        out <<  termcolor::red << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
    else if (outputZom.getLetter() == 'G') {
        out <<  termcolor::green << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
    else if (outputZom.getLetter() == 'B') {
        out <<  termcolor::blue << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
    else if (outputZom.getLetter() == 'C') {
        out <<  termcolor::cyan << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
    else if (outputZom.getLetter() == 'M') {
        out <<  termcolor::magenta << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
    else if (outputZom.getLetter() == 'Y') {
        out <<  termcolor::yellow << "[" << outputZom.getLetter()  << "]" << termcolor::reset;
        return out;
    }
}

