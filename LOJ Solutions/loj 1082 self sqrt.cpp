#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int ara[ N ];
int BLOCK[ 550 ];
int n;
int block_size;

void init( int block_size ) {
    for( int i = 1; i <= block_size; i++ ) BLOCK[i] = inf;
}
int Block_ID( int id ) {
    int pos = ( (id+block_size-1)/block_size );
    return pos;
}
void setblock( int id , int num ) {
    int pos = Block_ID( id );
    BLOCK[pos] = min( BLOCK[pos] , num );
}
int getmin( int l , int r ) {
    int block_a = Block_ID( l );
    int block_b = Block_ID( r );
    if( block_a == block_b ) {
        int mn = inf;
        for( int i = l; i <= r; i++ ) mn = min( mn , ara[i] );
        return mn;
    }
    int mn = inf;
    for( int i = l; ; i++ ) {
        int pos = Block_ID( i );
        if( pos != block_a ) break;
        mn = min( mn , ara[i] );
    }
    for( int i = block_a+1; i < block_b; i++ ) {
        mn = min( mn , BLOCK[i] );
    }
    int f = block_size*( block_b-1 );
    for( int i = f+1; i <= r; i++ ) {
        mn = min( mn , ara[i] );
    }
    return mn;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , q;
        scanf("%d %d",&n,&q);

        block_size = sqrt( n );
        init( block_size );

        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
            setblock( i , ara[i] );
        }
        printf("Case %d:\n",tc);
        while( q-- ) {
            int l , r;
            scanf("%d %d",&l,&r);
            printf("%d\n",getmin( l , r ) );
        }
    }
    return 0;
}






