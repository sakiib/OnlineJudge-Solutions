#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
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
int pos[600010],sp[600010];
double mn,mx,l,h;
double low,high,mid;

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      cin>>pos[i];
    }
    for(i=1;i<=n;i++)
    {
      cin>>sp[i];
    }
    low=0.0;high=100000000000.0;
    while(high-low>eps)
    {
      mid=(high+low)/2.0;
      mn=inf;mx=-inf;
      for(i=1;i<=n;i++)
      {
          l=pos[i]-mid*sp[i];
          h=pos[i]+mid*sp[i];
          mn=min(mn,h);
          mx=max(mx,l);
      }
      if(mx<=mn) high=mid;
      else low=mid;
    }
    cout<<setprecision(12)<<low<<endl;;
    return 0;
}


