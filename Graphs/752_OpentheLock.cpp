#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

/**
 * This program utilizes Breadth-First Search (BFS) to find the minimum number of turns required to unlock a combination lock, considering a list of dead ends (combinations where the lock seizes).

Algorithm:

We maintain a queue to store combinations to be explored.
We keep track of visited combinations and the minimum number of turns needed to reach them using a map.
We start with the initial state ("0000") and explore its neighbors (all possible combinations reachable by rotating one wheel one step).
For each neighbor, we check if it's the target combination or a dead end.
If not, we add the neighbor to the queue with a step count one higher than the current combination.
We repeat steps 3-5 until the queue is empty.
If the target combination is found in the map, we return the corresponding number of turns.
If the loop finishes without finding the target, it's unreachable, and we return -1.
*/

bool isDeadEnd(string node, vector<string>& deadends) {
  // Check if the current combination is a dead end
  for (string deadend : deadends) {
    if (deadend == node) return true;
  }
  return false;
}

vector<string> getNeighbours(string &node) {
  // Generate all possible combinations by rotating each wheel one step (clockwise or counter-clockwise)
  vector<string> neighbours;
  for (int i = 0; i < node.size(); i++) {
    int num = node[i] - 48; // Convert char to int
    string t = node;

    if (num == 9) {
      t[i] = '0';
    } else {
      t[i] = (char)(49 + num); // Increment digit (clockwise)
    }
    neighbours.push_back(t);

    if (num == 0) {
      t[i] = '9';
    } else {
      t[i] = (char)(47 + num); // Decrement digit (counter-clockwise)
    }
    neighbours.push_back(t);
  }
  return neighbours;
}

int openLock(vector<string>& deadends, string target) {
  // BFS variables
  unordered_map<string, int> vis; // Stores visited combinations and their minimum steps
  queue<string> queue;
  queue.push("0000");
  vis["0000"] = 0; // Initial state has 0 steps

  while (!queue.empty()) {
    string node = queue.front();
    queue.pop();

    if (node == target || isDeadEnd(node, deadends)) continue;

    vector<string> neighbours = getNeighbours(node);
    for (string neighbour : neighbours) {
      if (vis.find(neighbour) == vis.end()) {
        // Unvisited neighbor - update steps and add to queue
        vis[neighbour] = vis[node] + 1;
        queue.push(neighbour);
      }
    }
  }

  // Check if target combination was found and return steps, otherwise unreachable
  return vis.count(target) ? vis[target] : -1;
}

int main() {
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  string target = "1234";
  cout << openLock(deadends, target);
  return 0;
}
