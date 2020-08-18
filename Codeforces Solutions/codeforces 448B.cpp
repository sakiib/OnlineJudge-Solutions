/********************************
*       Sakib Al-Amin           *
*   North South University      *
********************************/

/*
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <list>*/

#include <bits/stdc++.h>

using namespace std;

#define ll               long long int
#define llu              unsigned long long int
#define dll              long double
#define gcd(x,y)         __gcd( (x) , (y) )
#define lcm(x,y)         ( x )/__gcd( ( x ) , ( y ) )*( y )
#define mx3(a,b,c)       max(a,max(b,c))
#define mn3(a,b,c)       min(a,min(b,c))
#define mx4(a,b,c,d)     max(a,mx3(b,c,d))
#define mn4(a,b,c,d)     min(a,mn3(b,c,d))
#define mx5(a,b,c,d,e)   max(a,mx4(b,c,d,e))
#define mn5(a,b,c,d,e)   min(a,mn4(b,c,d,e))
#define mxe(a,n)         (*max_element(a,a+n))
#define mne(a,n)         (*min_element(a,a+n))
#define sum(a,n)         (accumulate(a,a+n,0))
#define CLR(a)           memset(a,0,sizeof(a))
#define SET(a)           memset(a,-1,sizeof(a))
#define all(a)           (a.begin(),a.end())
#define rall(a)          (a.rbegin(),a.rend())
#define SQ(x)            ((x)*(x))
#define CU(x)            ((x)*(x)*(x))
#define UB               upper_bound
#define LB               lower_bound
#define PB               push_back
#define F                first
#define S                second
#define endl             '\n'
#define N                puts("NO");
#define Y                puts("YES");

#define sc1(a)           scanf("%d",&a)
#define sc2(a,b)         scanf("%d%d",&a,&b)
#define sc3(a,b,c)       scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)     scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e)   scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define pf1(a)           printf("%d\n",a)
#define pf2(a,b)         printf("%d %d\n",a,b)
#define pf3(a,b,c)       printf("%d %d %d\n",a,b,c)
#define pf4(a,b,c,d)     printf("%d %d %d %d\n",a,b,c,d)
#define pf5(a,b,c,d,e)   printf("%d %d %d %d %d\n",a,b,c,d,e)

#define for1(i,n)        for( int i=1 ; i<=n  ; i++ )
#define for0(i,n)        for( int i=0 ; i<n   ; i++ )
#define rof0(i,n)        for( int i=n-1 ; i>=0; i-- )
#define rof1(i,n)        for( int i=n ; i>=1  ; i-- )
#define forab(i,a,b)     for( int i=a ; i<=b  ; i++ )
#define rofab(i,a,b)     for( int i=b ; i>=a  ; i-- )

#define Read             freopen("input.txt",  "r", stdin)
#define Write            freopen("output.txt", "w", stdout)

#define Fastread         ios_base :: sync_with_stdio(false); cin.tie(0)

int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[] = {1, 0, -1, 1, -1, 1, 0, -1};

const ll INF = 1LL*(1e10);
const ll MOD = 1LL*(1e9+7);
const int Size = 100010;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double PII = 2*acos(0.0);

typedef vector< int >         vi;
typedef vector< ll >          vl;
typedef vector< string >      vs;
typedef vector< char >        vc;
typedef set< int >            si;
typedef set< char >           sc;
typedef set< string >         ss;
typedef pair< int,int >       pii;
typedef pair< string,int >    psi;
typedef pair< string,string > pss;
typedef map< int,int >        mii;
typedef map< string,int >     msi;
typedef map< char,int >       mci;
typedef map< string,string >  mss;
typedef map< char,char >      mcc;
typedef queue< int >          qi;
typedef stack< int >          sti;
typedef priority_queue< int > pqi;

inline bool isp(int x) {
    if(x<2) return false;  int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {if(x%i==0) return false;} return true;
}
inline bool leap_year(int x) {
    if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true; return false;
}
inline int power(int x,int y) {
    int ret=1; for(int i=1;i<=y;i++) { ret*=x; }  return ret;
}
inline int st_int(string &str) {
    int num; stringstream st(str); st>>num; return num;
}
inline string int_st(int num) {
    string res; stringstream convert; convert<<num; res=convert.str(); return res;
}

vector<ll> prime;
vector<bool> isprime(1000000,true);
inline void sieve(){
    isprime[0]=false; isprime[1]=false;
    isprime[2]=true;  ll sq=sqrt(1000000);
    for(ll i=2;i<=sq;i++){
        if(isprime[i]){
            for(ll j=i;j*i<1000000;j++){
            isprime[i*j]=false;
            }
        }
    }
    for(ll i=2;i<=1000000;i++){
        if(isprime[i]) prime.push_back(i);
    }
}
//---------------------Let's Code----------------------


int main(int argc,char const *argv[]) {
    Fastread;
    string a,b;
    cin>>a>>b;
    int l=0;
    for0(i,a.size()) {
        if(a[i]==b[l]) {
            l++;
        }
    }
    if(l==b.size()) {
        puts("automaton"); return 0;
    }
    string x,y;
    x=a; y=b;
    sort all(x);
    sort all(y);
    cerr<<x<<endl;
    cerr<<y<<endl;
    if(x==y) {
        puts("array"); return 0;
    }
    mci M1;
    mci M2;
    for0(i,b.size()) {
        M1[b[i]]++;
    }
    for0(i,a.size()) {
        M2[a[i]]++;
    }
    mci :: iterator it;
    for(it=M1.begin();it!=M1.end();it++) {
        if(it->S<=M2[it->F]) continue;
        else {
            puts("need tree"); return 0;
        }
    }
    puts("both");
    return 0;
}

