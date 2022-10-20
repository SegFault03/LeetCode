#include<bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>freq;
        map<int,set<string>>track;
        vector<string>tempV;
       
        for(string i: words)
            freq[i]++;
        
        for(map<string,int>::iterator itr = freq.begin();itr!=freq.end();itr++)
            track[itr->second].insert(itr->first);
        
        bool flag = false;
        map<int,set<string>>::reverse_iterator itr = track.rbegin();

        while(itr!=track.rend()&&!flag)
        {
            for(set<string>::iterator temp=itr->second.begin();temp!=itr->second.end();temp++)
            {
                if(tempV.size()==k)
                {
                    flag = true;
                    break;
                }
                tempV.push_back(*temp);
            }
            itr++;
        }
        return tempV;
    }

int main(){
    vector<string>test{"the","day","is","sunny","the","the","the","sunny","is","is"};
    vector<string>out=topKFrequent(test,4);
    for(auto i: out)
    cout<<i<<" ";
}