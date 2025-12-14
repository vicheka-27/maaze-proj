#ifndef MAZE_SOLVER_HPP
#define MAZE_SOLVER_HPP

#include <iostream>
#include <vector>
#include <climits>

struct Stats {
    long long timeTaken = 0;
};

std::vector<std::pair<int,int>> shortPath(std::vector<std::vector<int>> &maze, 
                                         std::pair<int,int> &src, 
                                         std::pair<int,int> &dest, 
                                         Stats &stats);

#endif