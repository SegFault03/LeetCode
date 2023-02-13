#include<bits/stdc++.h>
using namespace std;

int fun(int high, int low)
{
    long long int n, flag1, flag2;
    n = (low-high)+1;
    flag1 = n%2;
    flag2 = low%2;
    float temp = (float(n)/2);
    return flag1==flag2?ceil(float(n)/2):floor(float(n)/2);
}

int main(){
    cout<<fun(3,7);
}