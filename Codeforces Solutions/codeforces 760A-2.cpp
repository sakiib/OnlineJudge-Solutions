#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n,m,ans;
    cin>>n>>m;
    ans=month[n-1]-(7-m+1);
    if(ans%7==0) cout<<ans/7+1;
    else cout<<ans/7+2;
}
