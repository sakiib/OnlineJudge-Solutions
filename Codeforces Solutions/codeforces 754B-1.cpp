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
char a[100][100];
int main()
{
    int i,j;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        cin>>a[i][j];
      }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
         {
            if((a[i][j]+a[i][j+1]+a[i][j+2])==('.'+'x'+'x')) {cout<<"YES"; return 0;}
            if((a[i][j]+a[i+1][j]+a[i+2][j])==('.'+'x'+'x')) {cout<<"YES"; return 0;}
            if((a[i][j]+a[i+1][j+1]+a[i+2][j+2])==('.'+'x'+'x')) {cout<<"YES"; return 0;}
            if((a[i][j]+a[i+1][j-1]+a[i+2][j-2])==('.'+'x'+'x')) {cout<<"YES"; return 0;}
         }
    }
    cout<<"NO";
   return 0;
}




