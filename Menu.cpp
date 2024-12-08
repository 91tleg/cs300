#include <iostream>
#include <string>
#include <fstream>
#include "Analysis.h"
#include "LinkedList.h"
#include "Visualization.h"

int main()
{
    LinkedList list;
    Analysis analysis;
    Visualization viz;
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
            std::string path1 = std::filesystem::current_path().string() + "/temperatureData.txt";
            std::string path2 = std::filesystem::current_path().string() + "/gasData.txt";

            //std::string path1 = "./temperatureData.txt";
            //std::string path2 = "./gasData.txt";

            std::cout << path1 << std::endl;
            std::cout << path2 << std::endl;
            list = analysis.loadData(path1, path2);

            //list = analysis.loadData("/Users/ella/Documents/cs300-main/temperatureData.txt", "/Users/ella/Documents/cs300-main/gasData.txt");

            analysis.calculateCorrelation(list);
            std::cout << "Correlation coefficient between methane and temperature: " << analysis.getCH4Correlation() << std::endl;
            std::cout << "Correlation coefficient between carbon dioxide and temperature: " << analysis.getCO2Correlation() << std::endl;
            // visulization
            // In choice 1 after calculating correlation:
            viz.createTimeSeriesPlot(list);
            viz.createScatterPlot(list, analysis.getCH4Correlation(), analysis.getCO2Correlation());
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
