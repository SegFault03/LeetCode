#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) 
{
    string str="";
    map<int,string>roman
    {{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
    {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
    map<int,string>::iterator itr;
    while(num>0)
    {
        itr = roman.upper_bound(num);
        itr--;
        str+=itr->second;
        num-=itr->first;
    }
    return str;     
}

int main(){
    cout<<intToRoman(58);
}