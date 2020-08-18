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
int Binary_search(int low,int high,int baki);
int main()
{
    int n,time,left;
    cin>>n>>time;
    left=240-time;
    cout<<Binary_search(1,n,left)<<endl;;
    return 0;
}

int Binary_search(int low,int high,int baki)
{
    int mid,trial;
    while(low<high)
    {
      mid=(low+high)/2;
      trial=5*mid*(mid+1)/2;
      if(trial<baki) low=mid;
      else high=mid;
    }
   return low;
}



