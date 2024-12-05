#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include "Node.h"

class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    void addNode(int yr, double temp, double ch4, double co2);
    Node* findNodeByYear(int year);
    Node* getHead();
    void display();
    LinkedList& operator=(const LinkedList& other);

private:
    Node* head;
};

#include "LinkedList.cpp"
#endif