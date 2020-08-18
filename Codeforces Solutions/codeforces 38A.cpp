#include<bits/stdc++.h>
using namespace std;
int ara[10001];
int main()
{
    int n,time,from,to,ans=0;
    cin>>n;
    ara[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>ara[i];
        ara[i]=ara[i]+ara[i-1];
    }
     cin>>from>>to;
     cout<<ara[to]-ara[from]<<endl;
     return 0;
}

