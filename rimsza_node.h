//rimsza_node.h file

//including the correct libraries and files
#pragma once
#ifndef RIMSZA_NODE_H
#define RIMSZA_NODE_H
#include <iostream>
#include <vector>
#include <string>

template <typename T> class LinkedList;

template <typename T> class Node {
    //declaring public members
    public:

        T data;
        Node *next;

        //defualt constructor, takes in no parameters
        Node();
};

template <typename T>

//Node() is the default constructor for the node class
//sets the data to NULL
Node<T>::Node() {
    data = '\0';
    next = NULL;
}

#endif
