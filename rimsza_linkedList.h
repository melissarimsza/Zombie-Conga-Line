// Linked List .h file


//importing the correct libraries and files
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "rimsza_node.h"

//using the std namespace
using namespace std;


template <typename T> class LinkedList {
    private:

    Node<T> *head, *tail;
    int listLength;

    //public member declaration
    public:

        LinkedList();

        void AddToFront(T newData);

        void AddToEnd(T newData);

        bool AddAtIndex(T newData, int index);

        void RemoveFromFront();

        void RemoveFromEnd();

        void RemoveTheFirst(T newData);

        void RemoveAllOf(T data);

        bool ElementsExist(T searchData);

        Node<T>* Find(T data);

        int IndexOfT(T data);

        T RetrieveFront();

        T RetrieveEnd();

        T Retrieve(int index);

        void PrintList();

        void Empty();

        int Length();
};

//LinkedList() is the default constructor for the LinkedList class
//sets the head and tail pointer to null and the list length to 0
template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
    listLength = 0;
}

//AddToFront() adds a new node to the front of the LinkedList
//takes in a piece of data and returns void
//Used in the engine action
template <typename T>
void LinkedList<T>::AddToFront(T newData) {
    //making a temporary node as an interator
    Node<T> *temp = new Node<T>();

    //first check if the list length is 0
    if (listLength == 0) {

        //add the data to temp and said it as the first node in the list
        temp->data = newData;
        head = temp;
    }
    else {

        //add the data to temp
        temp->data = newData;

        //set head after temp
        temp->next = head;

        //make temp the new head
        head = temp;
    }

    //increment the list length
    listLength++;
}

//AddToEnd() adds a new node to the end of the linked list
//takes in a piece of data and returns void
//used in the cabboose action
template <typename T>
void LinkedList<T>::AddToEnd(T newData) {

    //making temporary nodes for iterating and data storage
    Node<T> *added = new Node<T>();
    added->data = newData;
    Node<T> *temp = new Node<T>();

    //setting the iterator at the start of the list
    temp = head;

    //checking if the list has any nodes
    if (listLength == 0) {
        
        //make the first node at the head
        added->next = NULL;
        head = added;
    }
    else {

        //iterate through the list by moving temp
        while (temp->next != NULL) {
            temp = temp->next;
        }

        //when NULL is reached, add the node 
        temp->next = added;
    }

    //increment the length
    listLength++;
}

//AddAtIndex() adds a new node at a particular index in the linked list
//takes in a piece of data and an index and returns a bool
//Used in the Jump in the line
template <typename T>
bool LinkedList<T>::AddAtIndex(T newData, int index) {

    //creating temporary nodes for iteration and data storage
    Node<T> *previous = new Node<T>();
    Node<T> *current = new Node<T>();
    Node<T> *temp = new Node<T>();

    //assigning the iterator to the start of the linked list
    current = head;

    //iterate up to the index by passing pointers
    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    //assign the data and correct pointers to maintain the linked list
    temp->data = newData;
    previous->next = temp;
    temp->next = current;

    //increment the length
    listLength++;

    return true;
}

//RemoveFromFront() removes the head of the linked list
//does not take any parameters and returns void
template <typename T>
void LinkedList<T>::RemoveFromFront() {

    //creating the node
    Node<T> *temp = new Node<T>();

    //making the second node the head
    temp = head;
    head = head->next;

    //deleting the head
    delete temp;
}

//RemoveFromEnd() removes the tail node of the list
//takes in no parameters and returns void
template <typename T>
void LinkedList<T>::RemoveFromEnd() {

    //creating temporary nodes for iteration and storage
    Node<T> *current = new Node<T>();
    Node<T> *previous = new Node<T>();
    current = head;

    //iterate to the end of the linked list
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    //creating the new link before deleting the node
    tail = previous;
    previous->next = NULL;

    //decrementing the length
    listLength--;

    //delete the node
    delete current;
}

//RemoveTheFirst() takes in a piece of data and removes the first instance of that data found in the linked list
//used in You're Out! action
template <typename T>
void LinkedList<T>::RemoveTheFirst(T checkedData) {
    //creating temporary nodes for iteration and data storage
    Node<T> *current = new Node<T>();
    Node<T> *previous = new Node<T>();

    //set the iterator at the head
    current = head;

    //if the list is empty return
    if (listLength == 0) {
        return;
    }

    //iterate while the current data does not have the searched data and the end of the list hasn't been reached
    while (!(current->data == checkedData) && (current->next != NULL )) {
        previous = current;
        current = current->next;
    }  
    if (current->data == checkedData) {
        //if the desired data is reached bridge the link and delete the current
        if (current == head) {
            head = current-> next;
            delete current;
        }
        else {
            previous->next = current->next;
            delete current;
        }

        //decrement the length
        listLength--;
    }   
}

//RemoveAllOf() takes in a piece of data and removes all instances of it from the linked list
//Used in the Everyone out! action
template <typename T>
void LinkedList<T>::RemoveAllOf(T checkedData) {
    //call RemoveTheFirst() as many times as the linked list is all
    //basically removes the item the first time it is found, then starts from the begining
    for (int i = 0; i < listLength; i++) {
        this->RemoveTheFirst(checkedData);
    }     
}

//should be done
template <typename T>
bool LinkedList<T>::ElementsExist(T searchData) {
    Node<T> *temp = new Node<T>();
    temp = head;

    while (temp != NULL) {
        if (temp->data == searchData) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Fine() takes in a data piece and searches for it in the linked list
//returns a pointer to the node containing the searched data
template <typename T>
Node<T>* LinkedList<T>::Find(T inputData) {

    //making a temp node for iteration and setting it to the begining of the list
    Node<T> *temp = new Node<T>();
    temp = head;

    //iterate until the end of the list is reached
    while (temp != NULL) {
        //if the data is found return a pointer to it
        if (temp->data == inputData) {
            return *temp;
        }
        else {
            temp = temp->next;
        }
    }
}

//IndexOfT() takes in a pieve of data and returns the index of the node it is stored in
template <typename T>
int LinkedList<T>::IndexOfT(T inputData) {
    //set the index to 0
    int index = 0;

    //make a temporary node for iteration and set it to the head
    Node<T> *temp = new Node<T>();
    temp = head;

    //iterate throught the linked list
    while (temp != NULL) {

        //if the data matches return the index
        if (temp->data == inputData) {
            return index;
        }
        //otherwise increment the index counter
        else {
            index = index + 1;
            temp = temp->next;
        }
    }

    //if its not found return -1
    return -1;
}

//RetrieveFront() returns the first node in the linked list
template <typename T>
T LinkedList<T>::RetrieveFront() {
    return head->data;
}

//RetrieveEnd() returns the last node in the linked list
template <typename T>
T LinkedList<T>::RetrieveEnd() {
    return tail->data;
}

//Retrieve() returns the node at the index specified
template <typename T>
T LinkedList<T>::Retrieve(int index) {

    //make a temporary node for interation and point it at the head
    Node<T> *temp = new Node<T>();
    temp = head;

    //iterate through to the index
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    //return the correct data
    return temp->data;
}

//PrintList() takes in no parameters and prints the entire linked list
template <typename T>
void LinkedList<T>::PrintList() {

    //creating a temporary node for iteration and assign it to the head of the list
    Node<T> *temp = new Node<T>();
    temp = head;

    //iterate through and cout the data 
    for (int i = 0; i < listLength; i++) {
        cout << temp->data;
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }
}

//Empty() iterates through the list and deletes the nodes and data
template <typename T>
void LinkedList<T>::Empty() {

    //create a temporary node to use to iterate and set it to the head
    Node<T> *temp = new Node<T>();
    temp = head;

    //move while the node is not empty
    while (temp != NULL) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Length() returns the listLength value as an int
template <typename T>
int LinkedList<T>::Length() {
    return listLength;
}
