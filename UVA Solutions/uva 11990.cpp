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
#define RIGHTMOST    __builtin_ctzll
#define POPCOUNT     __builtin_popcountll
#define LEFTMOST(x)  ( 63-__builtin_clzll((x)) )
#define MEM(a,x)     memset( a, x, sizeof(a) )
#define CLR(a,n)     for(int i=0;i<n;i++) a[i].clear()
#define debug(x)     cerr << "X is : " << x << endl
#define FOR(i,a,b)   for( int i = a; i <= b; i++ )
#define ROF(i,a,b)   for( int i = b; i >= a; i-- )
#define REP(i,a)     for( int i = 0; i < a; i++ )
#define pb           push_back
#define mp           make_pair
#define SORT(V)      sort( V.begin(), V.end() )
#define REV(V)       sort( V.rbegin(), V.rend() )
#define pp           pop_back
#define SQ(x)        (((x)*(x)))
#define CU(x)        ((x)*(x)*(x))
#define ii           pair<int,int>
#define iii          pair<int,ii>
#define clr(V)       V.clear()
#define sz(V)        V.size()
#define All(V)       V.begin(),V.end()
#define Read         freopen( "input.txt", "r", stdin )
#define Write        freopen( "output.txt", "w", stdout )
#define PQ(x)        priority_queue< x, vector<x>, greater<x> >
#define Unique(a)    sort(All(a)), a.erase(unique(All(a)), a.end())
#define UB(a,key)    upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)    lower_bound( a.begin(), a.end(), key )-a.begin()

int n , q;
int pos[ 2*N ];
int ara[ 2*N ];
int Inv[ 2*N ];
int BIT[ 2*N ];

void Update( int idx , int val ) {
    for( ; idx <= 2*N; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
int Query( int idx ) {
    int ret = 0;
    for( ; idx > 0; idx -= ( idx & -idx ) ) {
        ret += BIT[idx];
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    while( scanf("%d %d",&n,&q) != EOF ) {
        FOR( i , 1 , n ) {
            scanf("%d",&ara[i]);
            pos[ara[i]] = i;
        }
        int tot = 0;
        ROF( i , 1 , n ) {
           Update( ara[i] , 1 );
           int res = Query( ara[i]-1 );
           tot += res;
           Inv[i] = res;
        }
        FOR( i , 1 , n ) printf("%d ",Inv[i]);
        while( q-- ) {
            int num;
            scanf("%d",&num);
            printf("%d\n",tot);
            int p = pos[num];
            int in = Inv[p];
            tot -= in;
        }
        MEM( BIT , 0 );
        MEM( pos , 0 );
    }
    return 0;
}



