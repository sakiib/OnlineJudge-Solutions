#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[100001],i,mx=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
        if(ara[i]>mx) mx=ara[i];
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=(mx-ara[i]);
    }
    cout<<sum;
}
