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

LL Two[ 100 ] , Three[ 100 ] , Five[ 100 ];
vector <LL> V;

void calc( ) {
    Two[0] = Three[0] = Five[0] = 1;
    FOR( i , 1 , 63 ) Two[i] = Two[i-1]*2LL;
    FOR( i , 1 , 63 ) {
        Three[i] = Three[i-1]*3LL;
        if( Three[i] > INF ) break;
    }
    FOR( i , 1 , 63 ) {
        Five[i] = Five[i-1]*5LL;
        if( Five[i] > INF ) break;
    }
    FOR( i , 0 , 63 ) {
        FOR( j , 0 , 35 ) {
            FOR( k , 0 , 35 ) {
                LL val = Two[i]*Three[j]*Five[k];
                if( val > 0 && val <= INF ) V.pb( val );
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    calc( );
    SORT( V );
    printf("The 1500'th ugly number is %lld.\n",V[1499]);
    return 0;
}



