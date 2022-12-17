#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int>track;
    vector<int>ele_set;
    int size;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(!track.count(val))
        {
            ele_set.push_back(val);
            track[val]=ele_set.size()-1;
            return true;
        }
        else
        return false;
    }
    
    bool remove(int val) {
        if(track.count(val))
        {
            int idx = track[val];
            ele_set[idx] = ele_set.back();
            ele_set.pop_back();
            track[ele_set[idx]]=idx;
            track.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int upper = ele_set.size()-1, lower = 0;
        int range = upper-lower+1;
        int randn = (rand()%range) + lower;
        return ele_set[randn];
    }
};

int main()
{
 RandomizedSet* obj = new RandomizedSet();
 bool param_1 = obj->insert(1);
 param_1 = obj->insert(2);
 param_1 = obj->insert(3);
 param_1 = obj->remove(1);
 param_1 = obj->insert(4);
 param_1 = obj->insert(5);
 param_1 = obj->remove(1);
 param_1 = obj->insert(6);
 param_1 = obj->remove(3);
//  bool param_2 = obj->remove(1);
 int param_3 = obj->getRandom();
 cout<<obj->getRandom();
 cout<<obj->getRandom();
 cout<<obj->getRandom();
 cout<<obj->getRandom();
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */