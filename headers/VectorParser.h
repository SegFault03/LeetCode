#include<bits/stdc++.h>
using namespace std;

class VectorParser
{
public:
    static vector<vector<int>> twoDArrayParser(string a)
    {
        vector<vector<int>>arr;
        vector<int>temp;
        if(a.length()==0) return vector<vector<int>>();
        int i = 1;
        int n = a.length();
        while(i<n-1)
        {
            if(a[i]=='[')
            {
                i++;
                temp.clear();
                string s="";
                while(a[i]!=']' && i<n-1)
                {
                    if(a[i]==',')
                    {
                        if(s.length()>0)
                        temp.push_back(stoi(s));
                        s = "";
                    }
                    else
                        s += a[i];
                    i++;
                }
                if(s.length()>0)
                temp.push_back(stoi(s));
                arr.push_back(temp);
            }
            i++;
        }
        return arr;
    }  

    static vector<int> oneDArrayParser(string a)
    {
        if(a.length()==0) return vector<int>();
        vector<int>arr;
        int i = 1, n = a.length();
        string s="";
        while(i<n-1)
        {
            if(a[i]==',')
            {
                if(s.length()>0)
                arr.push_back(stoi(s));
                s = "";
            }
            else
            s += a[i];
            i++;
        }
        arr.push_back(stoi(s));
        return arr;
    }

    static vector<string> convertToStringVector(string a)
    {
        if(a.length()==0) return vector<string>();
        if(a=="null") return vector<string>{"null"};
        vector<string>arr;
        int i = 1, n = a.length();
        string s="";
        while(i<n-1)
        {
            if(a[i]==',')
            {
                if(s.length()>0)
                arr.push_back(s);
                s = "";
            }
            else
            s += a[i];
            i++;
        }
        arr.push_back(s);
        return arr;
    }

    static void printtwoDArray(vector<vector<int>>a)
    {
        cout<<"[";
        for(int i=0;i<a.size();i++)
        {
            cout<<"[";
            for(int j=0;j<a[i].size();j++){
                if(j!=a[i].size()-1)
                cout<<j<<",";
                else
                cout<<j;
            }
            if(i!=a.size()-1)
            cout<<"],";
            else
            cout<<"]";
        }
        cout<<"]"<<endl;
    }

    static void printOneDArray(vector<int>a)
    {
        cout<<"[";
        for(auto x: a)
        cout<<x<<",";
        cout<<"]"<<endl;
    }
};
