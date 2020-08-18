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
int ara[100001]={0};
int main()
{
    int n,i,num,mx;
    cin>>n;
    mx=n;
    while(mx>0)
    {
        cin>>num;
        ara[num]=1;
        while(ara[mx]==1)
        {
            cout<<mx--<<" ";
        }
        cout<<endl;
    }
   return 0;
}




