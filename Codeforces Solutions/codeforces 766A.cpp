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
map<char,int>mymap;
int main()
{
    int p,ans,i,bad=0;
    string a,b;
    cin>>a>>b;
    if(a==b) cout<<-1<<endl;
    else if(a.size()>b.size()) cout<<a.size()<<endl;
    else cout<<b.size()<<endl;
    /*for(i=0;i<a.size();i++)
    {
        mymap[a[i]]++;
    }
    for(i=0;i<b.size();i++)
    {
        mymap[b[i]]++;
    }
    map<char,int>:: iterator it;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
       //cout<<it->first<< " " <<it->second<<endl;
       if(it->second==2) bad++;
    }
    ans=max(a.size()-bad,b.size()-bad);
    cout<<ans<<endl;*/
   return 0;
}




