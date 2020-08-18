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
    int n,ans;
    cin>>n;
    if(n%2==0)
    {
        ans=n/2;
        cout<<ans<<endl;
        for(int i=0;i<ans;i++)
        {
            cout<<2<< " ";
        }
        cout<<endl;
    }
    else
    {
        n=n-3;
        ans=n/2+1;
        cout<<ans<<endl;
        for(int i=0;i<ans-1;i++)
        {
            cout<<2<< " ";
        }
        cout<<3<<endl;
    }
    return 0;
}



