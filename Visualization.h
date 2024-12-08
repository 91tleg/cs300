#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "LinkedList.h"
#include <SFML/Graphics.hpp>

class Visualization
{
public:
    Visualization();
    ~Visualization();

    void createTimeSeriesPlot(LinkedList &list);
    void createScatterPlot(LinkedList &list, double correlationCH4, double correlationCO2);
};

#endif
