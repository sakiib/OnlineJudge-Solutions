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

const int mod = (1<<30);
int NOD[ 1000005 ];

void calc( ) {
    for( int i = 1; i <= 1000005; i++ ) {
        for( int j = i; j <= 1000005; j += i ) {
            NOD[j]++;
        }
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int a , b , c;
    scanf("%d %d %d",&a,&b,&c);
    int ans = 0;
    FOR( i , 1 , a ) {
        FOR( j , 1 , b ) {
            FOR( k , 1 , c ) {
                ans = (ans%mod+NOD[i*j*k]%mod)%mod;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}



