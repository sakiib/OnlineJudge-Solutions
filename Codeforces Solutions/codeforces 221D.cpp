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
int l = 1 , r = 0;
unordered_map <int,int> cnt;
int sum = 0;

struct data {
    int l , r , idx;
    bool operator <( const data &q ) const {
        int block_a = l / block;
        int block_b = q.l / block;
        if( block_a == block_b ) return ( r < q.r );
        return ( block_a < block_b );
    }
} Q[ N ];

void Add( int idx ) {
    if( cnt[ ara[idx] ] == ara[idx] ) sum--;
    cnt[ ara[idx] ] ++;
    if( cnt[ ara[idx] ] == ara[idx] ) sum++;
}
void Remove( int idx ) {
    if( cnt[ ara[idx] ] == ara[idx] ) sum--;
    cnt[ ara[idx] ] --;
    if( cnt[ ara[idx] ] == ara[idx] ) sum++;
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
    scanf("%d%d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    for( int i = 1; i <= q; i++ ) {
        int l , r;
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].idx = i;
    }
    MO();
    for( int i = 1; i <= q; i++ ) {
        printf("%d\n",ans[i]);
    }
    return 0;
}

