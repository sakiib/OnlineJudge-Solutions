#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int block = 320;
int n , q;
int ara[ N ] , ans[ N ];
int sum = 0;
int l = 1 , r = 0;
int cnt[ 2*N ] , M[ 2*N ];

struct query {
    int l , r , idx;
    query(){}
    query( int _l , int _r , int _idx ) {
        l = _l , r = _r , idx = _idx;
    }
    bool operator <( const query &other ) const {
        int block_a = l/block;
        int block_b = other.l/block;
        if( block_a == block_b ) return ( r < other.r );
        return ( block_a < block_b );
    }
} Q[ 2*N ];

void Add( int idx ) {
    cnt[ ara[idx] ]++;
    M[ cnt[ara[idx]]]++;
    sum = max( sum , cnt[ ara[idx] ] );
}
void Remove( int idx ) {
    M[ cnt[ara[idx]] ]--;
    if( M[cnt[ ara[idx] ] ] <= 0 ) sum--;
    cnt[ ara[idx] ]--;
}
void MO( ) {
    sort( Q+1 , Q+q+1 );
    for( int i = 1; i <= q; i++ ) {
        while( l < Q[i].l ) Remove( l++ );
        while( l > Q[i].l ) Add( --l );
        while( r < Q[i].r ) Add( ++r );
        while( r > Q[i].r ) Remove( r-- );
        ans[ Q[i].idx ] = sum;
    }
}
int main( int argc, char const *argv[] ) {
    while( scanf("%d",&n) ) {
        if( n == 0 ) break;
        scanf("%d",&q);
        for( int i = 1; i <= n; i++ ) {
            int val;
            scanf("%d",&val);
            ara[i] = val+100000;
        }
        for( int i = 1; i <= q; i++ ) {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].idx = i;
        }
        MO( );
        for( int i = 1; i <= q; i++ ) {
            printf("%d\n",ans[i]);
        }
        memset( cnt , 0 , sizeof(cnt) );
        memset( M , 0 , sizeof(M) );
        sum = 0;
        l = 1 , r = 0;
    }
    return 0;
}

