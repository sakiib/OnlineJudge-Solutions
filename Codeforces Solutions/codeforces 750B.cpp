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
map<char,int>mymapci;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;

int main()
{
    int n,dist,total=0,bad=0;
    string str;
    cin>>n;
    while(n--)
    {
      cin>>dist>>str;
      if(total<0||total>20000||total==0&&str[0]!='S'||total==20000&&str[0]!='N')
      {
          bad=1;
          break;
      }
      if(str[0]=='S') total+=dist;
      if(str[0]=='N') total-=dist;
    }
    if(total!=0||bad==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}



