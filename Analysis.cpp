#ifndef ANALYSIS_CPP
#define ANALYSIS_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "Analysis.h"
#include "LinkedList.h"
#include "Node.h"

Analysis::Analysis()
{
    CH4Correlation = CO2Correlation = 0.0;
}

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

    // Read temperature data and store it in the linked list
    int year;
    double temperature;
    while (tempStream >> year >> temperature)
    {
        list.addNode(year, temperature, 0.0, 0.0); // Default CO2 and CH4 levels to 0.0
    }
    tempStream.close();

    // Read gas data and update the linked list
    double CO2, CH4;
    while (gasStream >> year >> CO2 >> CH4) {
        Node* existingNode = list.findNodeByYear(year);
        if (existingNode) {
            existingNode->CO2Level = CO2;
            existingNode->CH4Level = CH4;
        } else {
            list.addNode(year, 0.0, CO2, CH4); // Default temperature to 0.0
        }
    }
    gasStream.close();
    return list;
}

void Analysis::saveData(const std::string &fileName, LinkedList &list)
{
    std::ofstream outFile(fileName);
    if (!outFile)
    {
        std::cerr << "Error..." << std::endl;
        return;
    }
    Node* curr = list.getHead();
    while (curr)
    {
        outFile << curr->year << " " << curr->globalTemperature << " " << curr->CH4Level << " " << curr->CO2Level << std::endl;
        curr = curr->next;
    }
    outFile.close();
    std::cout << "Data saved to " << fileName << std::endl;
}

void Analysis::saveAnalysis(const std::string &fileName, LinkedList &list)
{
        std::ofstream outFile(fileName);
    if (!outFile)
    {
        std::cerr << "Error: Failed to open file \"" << fileName << "\" for writing." << std::endl;
        return;
    }

    outFile << CH4Correlation << CO2Correlation << std::endl;

    if (outFile.fail())
    {
        std::cerr << "Error: Failed to write to file \"" << fileName << "\"." << std::endl;
        outFile.close();
        return;
    }

    outFile.close();
    std::cout << "Correlations saved to \"" << fileName << "\" successfully." << std::endl;
}

// Calculate the correlation coefficient for each greenhouse gas in the dataset using Pearson correlation coefficient
void Analysis::calculateCorrelation(LinkedList &list)
{
    Node* curr = list.getHead();

    double sumTemp = 0, sumCH4 = 0, sumCO2 = 0;
    double sumTempSq = 0, sumCH4Sq = 0, sumCO2Sq = 0;
    double sumTempCH4 = 0, sumTempCO2 = 0;
    int count = 0;

    while (curr)
    {
        double temp = curr->globalTemperature;
        double CH4 = curr->CH4Level;
        double CO2 = curr->CO2Level;

        sumTemp += temp;
        sumCH4 += CH4;
        sumCO2 += CO2;
        sumTempSq += temp * temp;
        sumCH4Sq += CH4 * CH4;
        sumCO2Sq += CO2 * CO2;
        sumTempCH4 += temp * CH4;
        sumTempCO2 += temp * CO2;

        curr = curr->next;
        ++count;
    }
    CH4Correlation = (count * sumTempCH4 - sumTemp * sumCH4) / (std::sqrt(count * sumTempSq - sumTemp * sumTemp) * std::sqrt(count * sumCH4Sq - sumCH4 * sumCH4));

    CO2Correlation = (count * sumTempCO2 - sumTemp * sumCO2) / (std::sqrt(count * sumTempSq - sumTemp * sumTemp) * std::sqrt(count * sumCO2Sq - sumCO2 * sumCO2));
}

double Analysis::getCH4Correlation()
{
    return CH4Correlation;
}

double Analysis::getCO2Correlation()
{
    return CO2Correlation;
}

#endif
