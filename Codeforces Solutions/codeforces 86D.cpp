#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int block = 450;

int l = 1 , r = 0 , n , q;
LL ans[ 2*N ];
int cnt[ 10*N ] , a[ 2*N ];
LL sum;

struct data {
        int l , r , idx;
        data(){}
        data( int l , int r , int idx ):l(l), r(r), idx(idx){}
        bool operator <( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
        }
} Q[ 2*N ];

void Add( int id ) {
        sum -= ( 1LL * cnt[ a[id] ] * cnt[ a[id] ] * a[id] );
        cnt[ a[id] ]++;
        sum += ( 1LL * cnt[ a[id] ] * cnt[ a[id] ] * a[id] );
}
void Remove( int id ) {
        sum -= ( 1LL * cnt[ a[id] ] * cnt[ a[id] ] * a[id] );
        cnt[ a[id] ]--;
        sum += ( 1LL * cnt[ a[id] ] * cnt[ a[id] ] * a[id] );
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
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= q; i++ ) scanf("%d %d",&Q[i].l,&Q[i].r) , Q[i].idx = i;
        MO( );
        for( int i = 1; i <= q; i++ ) printf("%lld\n",ans[i]);
        return 0;
}






