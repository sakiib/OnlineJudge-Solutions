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
vector<LL>myvec;
int main()
{
    LL n,k,i,sq,j=0;
    cin>>n>>k;
    sq=sqrt(n);
    for(i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            {
              myvec.push_back(i);
              myvec.push_back(n/i);
            }
            else
            {
              myvec.push_back(i);
            }
        }
    }
    sort(myvec.begin(),myvec.end());
    if(k>myvec.size()) cout<<-1<<endl;
    else cout<<myvec[k-1]<<endl;
    return 0;
}




