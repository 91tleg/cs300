#ifndef NODE_H
#define NODE_H
#

struct Node
{
    int year;
    double globalTemperature;
    double methaneLevel;
    double carbonDioxideLevel;
    Node *next;

    Node(int yr, double temp, double ch4, double co2)
    {
        year = yr;
        globalTemperature = temp;
        methaneLevel = ch4;
        carbonDioxideLevel = co2;
        next = nullptr;
    }
};

#endif