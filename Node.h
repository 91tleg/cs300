#ifndef NODE_H
#define NODE_H

struct Node
{
    int year;
    double globalTemperature;
    double CH4Level;
    double CO2Level;
    Node *next;

    Node(int yr, double temp, double CH4, double CO2)
    {
        year = yr;
        globalTemperature = temp;
        CH4Level = CH4;
        CO2Level = CO2;
        next = nullptr;
    }
};

#endif