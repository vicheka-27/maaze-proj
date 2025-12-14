#include "test_cases.hpp"
#include <iostream>
#include "visualizer.hpp"

int main(){
    int choice;
    
    while(true) {
        displayMenu();
        std::cin >> choice;
        
        if(choice >= 1 && choice <= 5) {
            runPredefinedTest(choice);
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        } else if(choice == 6) {
            std::cout << "\n" << GREEN << "Thank you for using Maze Solver!" << RESET << "\n\n";
            break;
        } else {
            std::cout << RED << "Invalid choice! Please try again." << RESET << "\n";
        }
    }
    
    return 0;
}