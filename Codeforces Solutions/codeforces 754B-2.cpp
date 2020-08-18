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
    int i,j;
    char str[100][100];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>str[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if((str[i][j]+str[i][j+1]+str[i][j+2])==('x'+'.'+'x'))//rows
            {
                cout<<"YES"<<endl; return 0;
            }
            if((str[i][j]+str[i+1][j]+str[i+2][j])==('x'+'x'+'.'))//columns
            {
                cout<<"YES"<<endl; return 0;
            }
            if((str[i][j]+str[i+1][j+1]+str[i+2][j+2])==('.'+'x'+'x'))//diagonal1
            {
                cout<<"YES"<<endl; return 0;
            }
            if((str[i][j]+str[i+1][j-1]+str[i+2][j-2])==('x'+'.'+'x'))//diagonal2
            {
                cout<<"YES"<<endl; return 0;
            }
        }
    }
    cout<<"NO"<<endl;
   return 0;
}




