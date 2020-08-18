#include<bits/stdc++.h>
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
    int n,ara[200005],i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    for(i=1;i<=n/2;i+=2)
    {
      swap(ara[i],ara[n+1-i]);
    }
    for(i=1;i<=n;i++)
    {
        cout<<ara[i]<<" ";
    }
    cout<<endl;
   return 0;
}




