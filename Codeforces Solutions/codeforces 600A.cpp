#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <math.h>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define pf printf
#define sf scanf
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define sq(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x));
#define abs(x) ((x)<0?-(x):(x))
#define maxe(a,n) (*max_element(a,a+n))
#define mine(a,n) (*min_element(a,a+n))
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,(b),sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define gcd(x,y) __gcd(abs(x),abs(y))
#define lcm(x,y) abs(x)/__gcd(abs(x),abs(y))*abs(y)
#define dist(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long int ll;
typedef unsigned long long int llu;

inline string trail_zero(string &str)
{
    int s;
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]!='0'){
            s=i; break;
        }
    }
    for(int i=s;i<str.size();i++){
        ret+=str[i];
    }
    return ret;
}
inline ll power(ll x,ll y)
{
    ll res=1;
    for(ll i=1;i<=y;i++){
        res*=x;
    }
    return res;
}
inline int string_int(string &str)
{
    int len=str.length();
    int num=0;
    for(int i=len-1,j=0;i>=0;i--,j++){
        num+=(str[i]-'0')*power(10,j);
    }
    return num;
}
inline int nCr(int n,int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else return (nCr(n-1,r)+nCr(n-1,r-1));
}
inline bool prime_check(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
inline bool leap_year(int year)
{
    if(year%400==0||(year%4==0&&year%100!=0))
        return true;
    else return false;
}

const double EPS = 1e-9;
const int SIZE = 20000005;
const int Size = 100005;
const int MOD = 1000000007;//1e9+7
const double PI = 2*acos(0.0);
const long long INF = 9876543210987654LL;
int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<string,int> msi;
typedef map<string,string> mss;
typedef set<int> si;
typedef set<ll> sl;
typedef set<string> ss;
typedef stack<int> sti;
typedef stack<ll> stl;
typedef stack<string> sts;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

/*================= NSU ===================/
/=============== Dragon_162 =============*/



   return 0;
}





