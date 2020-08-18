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
    int a,b;
    cin>>a>>b;
    if(a==0&&b==0) cout<<"NO"<<endl;
    else if(a==b) cout<<"YES"<<endl;
    else if(abs(a-b)==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

   return 0;
}




