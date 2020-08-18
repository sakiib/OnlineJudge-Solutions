#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define eps 1e-6
#define pi acos(-1)
#define mod 1e9+7
#define inf 2000000000LL
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
set<int>myseti;
set<string>mysets;
set<char>mysetc;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvecl;
vector<int>myveci;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;

int main()
{
    int n,time,left,i=1,count=0,tot;
    cin>>n>>time;
    tot=n;
    left=240-time;
    while(left>=0)
    {
      left=left-5*i;
      i++;
      if(left>=0) count++;
    }
    if(count>tot) cout<<tot<<endl;
    else
    cout<<count<<endl;
    return 0;
}



