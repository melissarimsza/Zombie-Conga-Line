/*
     Author: Melissa Rimsza
     Date: 04/23/2021
     Description: CSE 240 Assignment 6
     Usage: Uses a node and linked lsit class to create a conga line of zombies identified by a color and letter
            Iterates through a number of rounds specified by the user
            Everytime a round is done, a random action is done to the zombie conga line
            Actions:
                Engine - Adds a random zombie to the front
                Caboose - Adds a random zombie to the end
                Jump in the line - adds a random zombie at a random position in the line
                Everyone out - picks a random letter and removes all instances of that letter from the line
                You're out - picks a random color and removes the first instance of that letter from the line
                Brains - adds a zombie with a random letter to the front and end of the line
                Rainbow brains - adds a random letter to the front of the line and adds one of each color to the end
            The Linked list and nodes are templated so any object or data type can be stored in them
*/

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <random>
#include "rimsza_linkedList.h"
#include "rimsza_node.h"
#include "rimsza_zombie.h"

using namespace std;

void actionChoice(LinkedList<Zombie> passedList, int randomChoice);
char letterChoice();

int main(int argc, char *argv[]) {

    //makes rand() give different numbers each time
    srand ((unsigned) time(0));

    //declare input and input checking variables
    int initChoice;
    int recurringChoice = 1;
    int numRounds;
    bool goodChoice = false;

    char temp;
    char temp2;
    int randIndex;
    int randomChoice;

    //printing interface elements
    cout << "*********************************" << endl;
    cout << "Welcome to the zombie conga line!" << endl;
    cout << "*********************************" << endl;
    cout << endl;
    cout << "Are you ready to party?" << endl;
    cout << "1. Yes!" << endl;
    cout << "2. No :(" << endl;
    cout << endl;

    //checks to make sure the user put in a valid input (1 or 2)
    while (goodChoice == false) {
        cin >> initChoice;
        if (initChoice == 1|| initChoice == 2) {
            goodChoice = true;
        }
        else {
            cout << "Please enter 1 or 2!" << endl;
        }
    }

    goodChoice = false;

    if (initChoice == 1) {

        //making a new linked list object
        LinkedList<Zombie> myLinkedList = LinkedList<Zombie>();
        
        //rainbow brains action to create the initial list
        myLinkedList.AddToFront('C');
        myLinkedList.AddToEnd('R');
        myLinkedList.AddToEnd('G');
        myLinkedList.AddToEnd('B');
        myLinkedList.AddToEnd('C');
        myLinkedList.AddToEnd('M');
        myLinkedList.AddToEnd('Y');

        while (recurringChoice == 1) {
            //get how many rounds the user would like to do actions for
            cout << "How many rounds would you like to do?" << endl;
            cin >> numRounds;
            
            for (int i = 1; i <= numRounds; i++) {
                //get random letters and an index to use in the actions
                temp = letterChoice();
                temp2 = letterChoice();
                randIndex = (rand() % myLinkedList.Length()) + 1;

                //get a random nuber to determine which action is done
                int randomChoice = rand() % 6;

                //for all the actions print this interface with information about the line
                cout << "*******************" << endl;
                cout << "The zombie conga keeps on dancing!" << endl;
                cout << "Round: " << i << endl;
                cout << "Current party: " << endl;;
                myLinkedList.PrintList();
                cout << endl;
                cout << "*******************" << endl;

                //determine which action is called based on the random number
                switch (randomChoice) {
                    case 0:
                        //Engine adds a random lettered zombie to the front
                        cout << "Engine!" << endl;
                        myLinkedList.AddToFront(temp);
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 1:
                        //Caboose adds a random lettered zombie to the end
                        cout << "Caboose!" << endl;
                        myLinkedList.AddToEnd(temp);
                        cout << "The party line is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 2:
                        //Jump in the line adds a random lettered zombie at a random index in the line
                        cout << "Jump in the line!" << endl;
                        myLinkedList.AddAtIndex(temp, randIndex);
                        cout << "The party line is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 3:
                        //Everyone Out removes all of one type of zombie
                        cout << "Everyone out!" << endl;
                        myLinkedList.RemoveAllOf(temp);
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 4:
                        //You're done removes the first instance of one of the letters from the line
                        cout << "You're done!" << endl;
                        myLinkedList.RemoveTheFirst(temp);
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 5:
                        //Brains adds a random lettered zombie to the front and end of the line
                        cout << "Brains!" << endl;
                        myLinkedList.AddToFront(temp);
                        myLinkedList.AddToEnd(temp2);
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    case 6:
                        //Rainbow brains adds a random lettered zombie to the front of the line
                        //then adds on of each color to the end
                        cout << "Rainbow brains!" << endl;
                        temp = letterChoice();
                        myLinkedList.AddToFront(temp);
                        myLinkedList.AddToEnd('R');
                        myLinkedList.AddToEnd('G');
                        myLinkedList.AddToEnd('B');
                        myLinkedList.AddToEnd('C');
                        myLinkedList.AddToEnd('M');
                        myLinkedList.AddToEnd('Y');
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                    default:
                        //rainbow brains same as above
                        cout << "Rainbow brains!" << endl;
                        temp = letterChoice();
                        myLinkedList.AddToFront(temp);
                        myLinkedList.AddToEnd('R');
                        myLinkedList.AddToEnd('G');
                        myLinkedList.AddToEnd('B');
                        myLinkedList.AddToEnd('C');
                        myLinkedList.AddToEnd('M');
                        myLinkedList.AddToEnd('Y');
                        cout << "The party is now:" << endl;
                        myLinkedList.PrintList();
                        cout << endl;
                        break;
                }
                cout << "*******************" << endl;
                cout << endl;
            }

            //after the rounds ask the user if they want to play again
            cout << "That's all the rounds! Do you want to party again?" << endl;
            cout << "1. Yes!" << endl;
            cout << "2. No :(" << endl;

            cin >> recurringChoice;
        }

        //free the memory
        myLinkedList.Empty();

    }
    else {
        cout << "Thanks for partying!" << endl;
    }

    cout << "Thanks for partying!" << endl;

    return 0;
}

//actionChoice() takes in a linkedlist object and a random number
//it uses the random number to determine which zombie action to call on the linked list
void actionChoice(LinkedList<Zombie> passedList, int randNum) {

    //get random letters and an index to use in the actions
    char temp = letterChoice();
    char temp2 = letterChoice();
    int randIndex = (rand() % passedList.Length()) + 1;

    //determine which action is called based on the random number
    switch (randNum) {
        case 0:
            //Engine adds a random lettered zombie to the front
            cout << "Engine!" << endl;
            passedList.AddToFront(temp);
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 1:
            //Caboose adds a random lettered zombie to the end
            cout << "Caboose!" << endl;
            passedList.AddToEnd(temp);
            cout << "The party line is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 2:
            //Jump in the line adds a random lettered zombie at a random index in the line
            cout << "Jump in the line!" << endl;
            passedList.AddAtIndex(temp, randIndex);
            cout << "The party line is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 3:
            //Everyone Out removes all of one type of zombie
            cout << "Everyone out!" << endl;
            passedList.RemoveAllOf(temp);
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 4:
            //You're done removes the first instance of one of the letters from the line
            cout << "You're done!" << endl;
            passedList.RemoveTheFirst(temp);
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 5:
            //Brains adds a random lettered zombie to the front and end of the line
            cout << "Brains!" << endl;
            passedList.AddToFront(temp);
            passedList.AddToEnd(temp2);
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        case 6:
            //Rainbow brains adds a random lettered zombie to the front of the line
            //then adds on of each color to the end
            cout << "Rainbow brains!" << endl;
            temp = letterChoice();
            passedList.AddToFront(temp);
            passedList.AddToEnd('R');
            passedList.AddToEnd('G');
            passedList.AddToEnd('B');
            passedList.AddToEnd('C');
            passedList.AddToEnd('M');
            passedList.AddToEnd('Y');
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
        default:
            //rainbow brains same as above
            cout << "Rainbow brains!" << endl;
            char temp = letterChoice();
            passedList.AddToFront(temp);
            passedList.AddToEnd('R');
            passedList.AddToEnd('G');
            passedList.AddToEnd('B');
            passedList.AddToEnd('C');
            passedList.AddToEnd('M');
            passedList.AddToEnd('Y');
            cout << "The party is now:" << endl;
            passedList.PrintList();
            cout << endl;
            break;
    }
}


//letterChoice() generates a random letter to be used in actionChoice
char letterChoice() {

    //gets a random integer between 1 and 7
    int randomLetter = (rand() % 6 + 1);

    //determines which letter return based on the number
    switch (randomLetter) {
        case 1:
            return 'R';
            break;
        case 2: 
            return 'G';
            break;
        case 3:
            return 'B';
            break;
        case 4:
            return 'C';
            break;
        case 5:
            return 'M';
            break;
        case 6:
            return 'Y';
            break;
        default:
            return 'Y';
    }
}
