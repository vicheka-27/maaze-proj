#include "visualizer.hpp"
#include <vector>
#include <iomanip>

void printMazeWithPath(std::vector<std::vector<int>> &maze, std::vector<std::pair<int,int>> &path, 
                       std::pair<int,int> src, std::pair<int,int> dest) {
    std::vector<std::vector<char>> display(maze.size(), std::vector<char>(maze[0].size()));
    for(int i=0; i<maze.size(); i++){
        for(int j=0; j<maze[0].size(); j++){
            display[i][j] = (maze[i][j]==1) ? '.' : 'X';
        }
    }

    for(auto &cell : path){
        display[cell.first][cell.second] = '*';
    }
    display[src.first][src.second] = 'S';
    display[dest.first][dest.second] = 'E';

    std::cout << "\n" << BOLD << CYAN << "=== Final Solution ===" << RESET << "\n\n";
    for(int i=0; i<display.size(); i++){
        std::cout << "  ";
        for(int j=0; j<display[0].size(); j++){
            char c = display[i][j];
            if(c == 'S') {
                std::cout << GREEN << BOLD << c << RESET << "  ";
            } else if(c == 'E') {
                std::cout << RED << BOLD << c << RESET << "  ";
            } else if(c == '*') {
                std::cout << YELLOW << c << RESET << "  ";
            } else if(c == 'X') {
                std::cout << MAGENTA << c << RESET << "  ";
            } else {
                std::cout << WHITE << c << RESET << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\n  " << BOLD << "Legend: " << RESET;
    std::cout << GREEN << BOLD << "S" << RESET << "=Start, ";
    std::cout << RED << BOLD << "E" << RESET << "=End, ";
    std::cout << YELLOW << "*" << RESET << "=Path, ";
    std::cout << WHITE << "." << RESET << "=Open, ";
    std::cout << MAGENTA << "X" << RESET << "=Wall\n";
}

void printStats(Stats &stats) {
    std::cout << "\n  " << BOLD << "Time Taken: " << RESET << std::fixed << std::setprecision(3) 
         << stats.timeTaken / 1000.0 << " ms\n\n";
}