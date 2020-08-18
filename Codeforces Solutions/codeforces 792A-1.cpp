#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
using namespace std;
ll ara[200005];
int main()
{
    ll n,i,dist=2000000001,count=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    sort(ara,ara+n);
    for(i=0;i<n-1;i++)
    {
       if(abs(ara[i+1]-ara[i])<dist)
        dist=abs(ara[i+1]-ara[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if(abs(ara[i+1]-ara[i])==dist)
            count++;
    }
    cout<<dist<< " " <<count<<endl;
    return 0;
}
