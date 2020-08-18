#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <iterator>
#include <sstream>
#include <numeric>
#include <fstream>
#include <vector>
#include <cctype>
#include <math.h>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf          printf
#define VI          vector <int>
#define QI          queue <int>
#define pii         pair <int, int>
#define pb          push_back
#define mp          make_pair
#define sz          size()
#define ins         insert
#define fi          first
#define se          second
#define inf         (1<<29)
#define MOD         100007
#define eps         1e-8
#define MAX         500000
typedef long long int LL;
typedef double db;
LL csum[MAX+10], dp[MAX+10][5];
LL srch[5];
int n;

LL calc(int pos, int idx)
{
    //cerr<<"Index : "<<idx<<endl;
    if(idx > 2) {return 1;}
    if(pos >= n) {return 0;}

    if(dp[pos][idx] != -1) return dp[pos][idx];
    LL ret = 0;
    if(csum[pos] == srch[idx]) {
    ret += calc(pos+1,idx+1);
    }
    ret += calc(pos+1,idx);

    return dp[pos][idx] = ret;
}

int main()
{

    int i, j;
    mem(dp, -1);

    sf(n);
    FRE(i,1,n)
    cin >> csum[i], csum[i] += csum[i-1];

    if(csum[n]%3)
    cout << 0 <<endl;
    else
    {
        srch[1] = csum[n]/3;
        srch[2] = 2*srch[1];
        srch[3] = 3*srch[1];
        cout << calc(1,1) << endl;
    }
    return 0;
}
