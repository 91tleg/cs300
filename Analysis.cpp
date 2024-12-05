#ifndef ANALYSIS_CPP
#define ANALYSIS_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "Analysis.h"
#include "LinkedList.h"
#include "Node.h"

LinkedList Analysis::loadData(const std::string& tempFile, const std::string& gasFile) 
{
    LinkedList list;
    std::ifstream tempStream(tempFile);
    std::ifstream gasStream(gasFile);

    if (!tempStream.is_open()) 
    {
        std::cerr << "Error opening " << tempFile << std::endl;
        return list;
    }
    if (!gasStream.is_open()) 
    {
        std::cerr << "Error opening " << gasFile << std::endl;
        return list;
    }

    // First pass: read temperature data and store it in the linked list
    int year;
    double temperature;
    while (tempStream >> year >> temperature)
    {
        list.addNode(year, temperature, 0.0, 0.0); // Default CO2 and CH4 levels to 0.0
    }
    tempStream.close();

    // Second pass: read gas data and update the linked list
    double co2, ch4;
    while (gasStream >> year >> co2 >> ch4) {
        Node* existingNode = list.findNodeByYear(year);
        if (existingNode) {
            existingNode->carbonDioxideLevel = co2;
            existingNode->methaneLevel = ch4;
        } else {
            list.addNode(year, 0.0, co2, ch4); // Default temperature to 0 if year not found in the temp file
        }
    }
    gasStream.close();
    return list;
}

void Analysis::saveAnalysis(const std::string &fileName)
{
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        std::cerr << "Error saving analysis." << std::endl;
        return;
    }

    Node *curr = list.getHead();
    while (curr)
    {
        outFile << curr->year << " " << curr->globalTemperature << " " << curr->methaneLevel << " " << curr->carbonDioxideLevel << std::endl;
        curr = curr->next;
    }

    std::cout << "Analysis saved to " << fileName << std::endl;
}

// Calculate the correlation coefficient for each greenhouse gas in the dataset.
// Use Pearson correlation coefficient to find the correlation between temp and gas.
double Analysis::calculateCorrelation()
{
    return 0;
}



#endif