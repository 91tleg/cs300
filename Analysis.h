#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "Node.h"
#include "LinkedList.h"

class Analysis
{
public:
    LinkedList loadData(const std::string &tempFile, const std::string &gasFile);
    void saveAnalysis(const std::string &fileName);
    double calculateCorrelation();
    
private:
    LinkedList list;
};

#include "Analysis.cpp"
#endif