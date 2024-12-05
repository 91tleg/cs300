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
            list.display();
        }
        else if (choice == 2)
        {
            std::string analysisName;
            std::cout << "Enter a name to save the analysis as: ";
            std::cin >> analysisName;
            analysis.saveAnalysis(analysisName);
        }
        else if (choice == 3)
        {
            std::string fileName;
            std::cout << "Enter the name of the analysis file to load: ";
            std::cin >> fileName;
            // analysis.loadData(fileName);
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
