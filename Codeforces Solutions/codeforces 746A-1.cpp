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
    int a,b,c,ans=0;
    cin>>a>>b>>c;
    while(a>=1&&b>=2&&c>=4)
    {
       ans+=7;
       a--;b-=2;c-=4;
    }
    cout<<ans<<endl;
   return 0;
}




