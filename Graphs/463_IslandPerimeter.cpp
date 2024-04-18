#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
  // Perimeter (initially 0)
  int p = 0;
  
  // Number of rows in the grid
  int r = grid.size();
  
  // Number of columns in the grid (based on the first row's size)
  int c = grid[0].size();
  
  // Queue to store coordinates of land cells to explore
  queue<pair<int, int>> queue;

  // Find a starting land cell
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 1) {
        // Mark the cell as visited and add it to the queue
        grid[i][j] = 2;
        queue.push({i, j});
        break; // Exit after finding the first land cell (potential optimization)
      }
    }
    // Exit outer loop if a land cell is found (potential optimization)
    if (!queue.empty()) {
      break;
    }
  }

  // If no land is found, the grid is all water (perimeter 0)
  if (queue.empty()) {
    return 0;
  }

  // Explore connected land cells using BFS
  while (!queue.empty()) {
    int i = queue.front().first;
    int j = queue.front().second;
    queue.pop();

    // Check neighbors for perimeter calculation
    if (i - 1 < 0 || (i - 1 >= 0 && grid[i - 1][j] == 0)) {
      p += 1; // Out of bounds or water neighbor contributes to perimeter
    }
    if (j - 1 < 0 || (j - 1 >= 0 && grid[i][j - 1] == 0)) {
      p += 1; // Out of bounds or water neighbor contributes to perimeter
    }
    if (j + 1 == c || (j + 1 < c && grid[i][j + 1] == 0)) {
      p += 1; // Out of bounds or water neighbor contributes to perimeter
    }
    if (i + 1 == r || (i + 1 < r && grid[i + 1][j] == 0)) {
      p += 1; // Out of bounds or water neighbor contributes to perimeter
    }

    // Check unvisited neighbor land cells and add them to the queue
    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
      grid[i - 1][j] = 2; // Mark as visited
      queue.push({i - 1, j});
    }
    if (i + 1 < r && grid[i + 1][j] == 1) {
      grid[i + 1][j] = 2; // Mark as visited
      queue.push({i + 1, j});
    }
    if (j + 1 < c && grid[i][j + 1] == 1) {
      grid[i][j + 1] = 2; // Mark as visited
      queue.push({i, j + 1});
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
      grid[i][j - 1] = 2; // Mark as visited
      queue.push({i, j - 1});
    }
  }

  return p;
}

int main(){
}