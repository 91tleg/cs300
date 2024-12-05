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
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addNode(int yr, double temp, double ch4, double co2)
{
    Node *newNode = new Node(yr, temp, ch4, co2);
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

Node *LinkedList::getHead()
{
    return head;
}

void LinkedList::display()
{
    Node *curr = head;
    while (curr)
    {
        std::cout << "Year: " << curr->year << ", Global Temp: " << curr->globalTemperature << ", CH4 Level: " << curr->methaneLevel << ", CO2 Level: " << curr->carbonDioxideLevel << std::endl;
        curr = curr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this == &other)
    {
        return *this;
    }

    // Clear existing nodes in the current list
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Copy nodes from the other list
    if (!other.head)
    {
        head = nullptr;
        return *this;
    }

    // Copy the first node explicitly to initialize the head
    head = new Node(other.head->year, other.head->globalTemperature, 
                    other.head->carbonDioxideLevel, other.head->methaneLevel);

    Node* current = head;      // Pointer to traverse the current list
    Node* otherCurrent = other.head->next; // Pointer to traverse the other list

    while (otherCurrent)
    {
        // Create a new node and link it
        current->next = new Node(otherCurrent->year, otherCurrent->globalTemperature, 
                                 otherCurrent->carbonDioxideLevel, otherCurrent->methaneLevel);

        current = current->next;        // Move to the next node in the current list
        otherCurrent = otherCurrent->next; // Move to the next node in the other list
    }

    return *this;
}

#endif