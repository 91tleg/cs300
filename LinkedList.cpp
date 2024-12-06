#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head)
    {
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }
}

void LinkedList::addNode(int yr, double temp, double CH4, double CO2)
{
    Node *newNode = new Node(yr, temp, CH4, CO2);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* LinkedList::findNodeByYear(int year)
{
    Node *current = head;
    while (current)
    {
        if (current->year == year)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::display()
{
    Node *curr = head;
    while (curr)
    {
        std::cout << "Year: " << curr->year << ", Global Temp: " << curr->globalTemperature << ", CH4 Level: " << curr->CH4Level << ", CO2 Level: " << curr->CO2Level << std::endl;
        curr = curr->next;
    }
}

void LinkedList::clear()
{
    while (head)
    {
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this == &other)
    {
        return *this;
    }
    if (!other.head)
    {
        head = nullptr;
        return *this;
    }

    clear();

    // Copy the first node to initialize the head
    head = new Node(other.head->year, other.head->globalTemperature, other.head->CO2Level, other.head->CH4Level);

    Node* current = head;
    Node* otherCurrent = other.head->next;
    while (otherCurrent)
    {
        current->next = new Node(otherCurrent->year, otherCurrent->globalTemperature, otherCurrent->CO2Level, otherCurrent->CH4Level);

        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return *this;
}

#endif