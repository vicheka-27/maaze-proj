#include "maze_solver.hpp"
#include <vector>
#include <climits>
#include <chrono>

// Edge-case helpers
static bool hasAnyOpenCell(const std::vector<std::vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int v : row) if (v == 1) return true;
    }
    return false;
}

bool isSafe(std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visited, int r, int c) {
    return r >= 0 && r < maze.size() &&
           c >= 0 && c < maze[0].size() &&
           maze[r][c] == 1 &&
           !visited[r][c];
}

void shortpath(std::vector<std::vector<int>> &maze, std::vector<std::vector<bool>> &visited,
               int i, int j, int x, int y, int &min_distance, int distance,
               std::vector<std::pair<int,int>> &currentPath,
               std::vector<std::pair<int,int>> &shortestPath) {

    if (i == x && j == y) {
        if (distance < min_distance) {
            min_distance = distance;
            shortestPath = currentPath; 
        }
        return;
    }

    visited[i][j] = true;
    currentPath.push_back({i,j});

    // 4-directional movement
    if(isSafe(maze, visited, i+1, j))
        shortpath(maze, visited, i+1, j, x, y, min_distance, distance+1, currentPath, shortestPath);
    if(isSafe(maze, visited, i-1, j))
        shortpath(maze, visited, i-1, j, x, y, min_distance, distance+1, currentPath, shortestPath);
    if(isSafe(maze, visited, i, j-1))
        shortpath(maze, visited, i, j-1, x, y, min_distance, distance+1, currentPath, shortestPath);
    if(isSafe(maze, visited, i, j+1))
        shortpath(maze, visited, i, j+1, x, y, min_distance, distance+1, currentPath, shortestPath);

    visited[i][j] = false;
    currentPath.pop_back();
}

std::vector<std::pair<int,int>> shortPath(std::vector<std::vector<int>> &maze, std::pair<int,int> &src, std::pair<int,int> &dest, Stats &stats) {
    // Basic edge cases
    if(maze.size()==0)
        return {};
    if(src.first == dest.first && src.second == dest.second) {
        return {src};
    }
    if(maze[src.first][src.second]==0 || maze[dest.first][dest.second]==0)
        return {};
    if(!hasAnyOpenCell(maze))
        return {};

    int row = maze.size(), col = maze[0].size();
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col,false));

    int min_distance = INT_MAX;
    std::vector<std::pair<int,int>> currentPath, shortestPath;

    auto start = std::chrono::high_resolution_clock::now();
    
    shortpath(maze, visited, src.first, src.second, dest.first, dest.second, 
              min_distance, 0, currentPath, shortestPath);
    
    auto end = std::chrono::high_resolution_clock::now();
    stats.timeTaken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return shortestPath;
}