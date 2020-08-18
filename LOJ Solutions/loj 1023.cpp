/*
    Author       :  Jan
    Problem Name :  Permutation
    Algorithm    :  Permutation
    Complexity   :
*/
#include<bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define pb push_back
#define sz size()
#define cl clear()
#define CLR(a) memset(a,false,sizeof(a))

int n,top,N, K;
char st[30];
bool fl[26];

void call(int top)
{
    if(top==n)
    {
        if(N==K)
            return;
        N++;
        st[top]=0;
        puts(st);
    }
    int i;

    for(i=0;i<n;i++)
    {
        if(!fl[i] && N<K)
        {
            fl[i]=true;
            st[top]=i+65;
            call(top+1);
            fl[i]=false;
        }
    }
}

void process()
{
    CLR(fl);
    N=0;
    call(0);
}

int cases, caseno;

int main()
{
  //  freopen("d.in","r",stdin);
  //  freopen("d.ans","w",stdout);

    scanf("%d", &cases);
    while( cases--)
    {
        scanf("%d %d",&n, &K);
        printf("Case %d:\n", ++caseno);
        process();
    }
    return 0;
}
