#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        stack.push_back(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++) {
            int temp = asteroids[i];
            if (stack.size()>0 && temp < 0 && stack.back() >= 0) {
                while (stack.size() > 0) {
                    if (temp < 0 && stack.back() >= 0) {
                        if (abs(temp) == abs(stack.back())) {
                            stack.pop_back();
                            break;
                        } else if (abs(temp) > abs(stack.back())) {
                            stack.pop_back();
                            if (stack.size() == 0) {
                                stack.push_back(temp);
                                break;
                            }
                        } else
                            break;
                    } else {
                        stack.push_back(temp);
                        break;
                    }
                }
            } else
                stack.push_back(temp);
        }
        return stack;
    }

int main(){
}