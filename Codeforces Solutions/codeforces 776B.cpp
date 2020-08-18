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

int isprime(int x);

int main()
{

    int n,i;
    cin>>n;
    if(n<=2) cout<<1<<endl;
    else cout<<2<<endl;
    for(i=2;i<=n+1;i++)
    {
      cout<<2-isprime(i)<< " ";
    }
    cout<<endl;

    return 0;
}

int isprime(int x)//It works Fine
{
	for(int i=2;i*i<=x;i++)//checking for prime//
    {
		if(x%i==0) return 0;
	}
	return 1;
}



