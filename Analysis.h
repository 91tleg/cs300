#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "Node.h"
#include "LinkedList.h"

class Analysis
{
public:
    Analysis();
    LinkedList loadData(const std::string &tempFile, const std::string &gasFile);
    LinkedList loadData(const std::string &fileName);
    void saveData(const std::string &fileName, LinkedList &list);
    void saveAnalysis(const std::string &fileName, LinkedList &list);
    void calculateCorrelation(LinkedList &list);
    double getCH4Correlation();
    double getCO2Correlation();

private:
    double CH4Correlation;
    double CO2Correlation;
};

#endif