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

int isprime(int num);

int main()
{
    int n,ans,i;
    cin>>n;
    for(i=1;i<=1000;i++)
    {
        ans=n*i+1;
        if(!isprime(ans)) break;
    }
    cout<<i<<endl;
   return 0;
}

int isprime(int num)
{
    int i;
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0) return 0;
    }
    return 1;
}



