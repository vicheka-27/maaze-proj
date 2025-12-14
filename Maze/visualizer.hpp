#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include "maze_solver.hpp"

// ANSI color codes for terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

void printMazeWithPath(std::vector<std::vector<int>> &maze, std::vector<std::pair<int,int>> &path, 
                       std::pair<int,int> src, std::pair<int,int> dest);
void printStats(Stats &stats);

#endif