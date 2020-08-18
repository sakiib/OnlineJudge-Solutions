#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;

#define endl         '\n'
#define EPS          1e-6
#define F            first
#define S            second
#define PI           acos(-1.0)
#define pb           push_back
#define mp           make_pair
#define pp           pop_back
#define SQ(x)        (((x)*(x)))
#define CU(x)        ((x)*(x)*(x))
#define ii           pair<int,int>
#define iii          pair<int,ii>
#define clr(V)       V.clear()
#define sz(V)        V.size()
#define All(V)       V.begin(),V.end()
#define SORT(V)      sort( V.begin(), V.end() )
#define REV(V)       sort( V.rbegin(), V.rend() )
#define MEM(a,x)     memset( a, x, sizeof(a) )
#define RIGHTMOST    __builtin_ctzll
#define POPCOUNT     __builtin_popcountll
#define LEFTMOST(x)  ( 63-__builtin_clzll((x)) )
#define CLR(a,n)     for(int i=0;i<n;i++) a[i].clear()
#define debug(x)     cerr << "X is : " << x << endl
#define FOR(i,a,b)   for( int i = a; i <= b; i++ )
#define ROF(i,a,b)   for( int i = b; i >= a; i-- )
#define REP(i,a)     for( int i = 0; i < a; i++ )
#define Read         freopen( "input.txt", "r", stdin )
#define Write        freopen( "output.txt", "w", stdout )
#define PQ(x)        priority_queue< x, vector<x>, greater<x> >
#define Unique(a)    sort(All(a)), a.erase(unique(All(a)), a.end())
#define UB(a,key)    upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)    lower_bound( a.begin(), a.end(), key )-a.begin()

LL BigMod( LL b , LL p , LL mod ) {
    if( p == 0 ) return 1;
    LL x = BigMod( b , p/2 , mod );
    x = (x*x)%mod;
    if( p&1 ) x = (b*x)%mod;
    return x%mod;
}
inline LL bigmod ( LL a, LL p, LL m ) {
    LL res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res%m;
}
LL Bigmod(LL b,LL p,LL mod) {
    if(p==0) return 1;
    LL x=bigmod(b,p/2,mod);
    x=(x*x)%mod;
    if(p%2==1) x=(b*x)%mod;
    return x;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        LL x , y;
        scanf("%lld %lld",&x,&y);
        double res = y*(log10(x));
        res -= (int)(res);
        double ans = pow(10,res);
        ans = ans*100;
        cout <<(int)(ans) <<"...";
        printf("%03lld\n",BigMod( x , y , 1000) );
    }
    return 0;
}


