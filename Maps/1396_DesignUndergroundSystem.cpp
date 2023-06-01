#include<bits/stdc++.h>
using namespace std;
//CORRECT@SegFault03
class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>customers;
    unordered_map<string,unordered_map<string,pair<double,double>>>stations;  
    UndergroundSystem() {
      
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string source = customers[id].first;
        int startTime = customers[id].second;
        customers.erase(id);
        if(stations[source].find(stationName)==stations[source].end())
        stations[source][stationName] = {t-startTime,1};
        else{
        stations[source][stationName].first+=(t-startTime);
        stations[source][stationName].second+=1;
        } 
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = stations[startStation][endStation].first / stations[startStation][endStation].second;
        return avg;
    }
};

int main(){
    UndergroundSystem *ob = new UndergroundSystem();
    ob->checkIn(2,"A",3);
    ob->checkIn(3,"A",5);
    ob->checkIn(4,"C",6);
    ob->checkOut(2,"B",7);
    ob->checkOut(3,"B",10);
    ob->checkOut(4,"A",12);
 double param_3 = ob->getAverageTime("A","B");
 double param_4 = ob->getAverageTime("C","A");
 cout<<param_3<<" "<<param_4;
}