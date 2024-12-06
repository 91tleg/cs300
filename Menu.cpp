#include <iostream>
#include <string>
#include "Analysis.h"
#include "LinkedList.h"
#include "Visualization.h"

int main()
{
    LinkedList list;
    Analysis analysis;
    int choice = 0;

    while (choice != 4)
    {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Create new data analysis" << std::endl;
        std::cout << "2. Save current analysis" << std::endl;
        std::cout << "3. Load previous analyses" << std::endl;
        std::cout << "4. Exit program" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            list = analysis.loadData("temperatureData.txt", "gasData.txt");
            analysis.calculateCorrelation(list);
            std::cout << "Correlation coefficient between methane and temperature: " << analysis.getCH4Correlation() << std::endl;
            std::cout << "Correlation coefficient between carbon dioxide and temperature: " << analysis.getCO2Correlation() << std::endl;
            // visulization
    
        }
        else if (choice == 2)
        {
            std::string analysisName;
            std::cout << "Enter a name to save the analysis as: ";
            std::cin >> analysisName;
            analysis.saveAnalysis(analysisName, list);
        }
        else if (choice == 3)
        {
            std::string fileName;
            std::cout << "Enter the name of the analysis file to load: ";
            std::cin >> fileName;
            std::ifstream corrStream(fileName);
            double CH4Correlation, CO2Correlation;
            corrStream >> CH4Correlation >> CO2Correlation;
            std::cout << "Correlation coefficient between methane and temperature: " << CH4Correlation << std::endl;
            std::cout << "Correlation coefficient between carbon dioxide and temperature: " << CO2Correlation << std::endl;
            // visualization
        }
        else if (choice == 4)
        {
            std::cout << "Exiting program." << std::endl;
        }
        else
        {
            std::cout << "Invalid choice..." << std::endl;
        }
    }

    return 0;
}
