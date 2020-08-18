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
int ara1[100],ara2[100];
int main()
{
    int n,i,num,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        ara1[num]++;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        ara2[num]++;
    }
    for(i=1;i<=5;i++)
    {
        if((ara1[i]+ara2[i])%2)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
           ans+=abs((ara1[i]-ara2[i])/2);
        }
    }
    printf("%d\n",ans/2);
    return 0;
}



