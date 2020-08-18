#include<bits/stdc++.h>
using namespace std;
set<string>myset;
int main()
{
    int n,m,tot,po,en,common=0;
    cin>>n>>m;
    tot=n+m;
    while(tot--)
    {
        string str;
        cin>>str;
        if(myset.count(str)==0) myset.insert(str);
        else common++;
    }
    n=n-(common)/2;
    m=m-(common+1)/2;
    if(n>m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
