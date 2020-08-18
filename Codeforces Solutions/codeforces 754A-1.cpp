#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double eps = 1e-6;
const int SIZE = 100000005;
const int Size = 100005;
const int MOD = 1000000007;
const double PI = 2*acos(0.0);
const long long INF = 214738360000;
typedef long long int LL;
typedef unsigned long long int LLU;

int main()
{
    int n,ara[10001],i,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
        sum+=ara[i];
    }
    if(sum==0) cout<<"NO"<<endl;
   return 0;
}




