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

int ara[ N ] , RMQ[ N ];
int block;

int GetID( int index ) {
    return ( index/block );
}
void Process( ) {
    for( int i = 0; i < block; i++ ) RMQ[i] = inf;
}
void SetBlock( int index , int val ) {
    int id = GetID( index );
    RMQ[id] = min( RMQ[id] , val );
}
int GetAns( int l , int r ) {
    int left = GetID( l );
    int right = GetID( r );
    int mn = inf;
    if( left == right ) {
        for( int i = l; i <= r; i++ ) mn = min( mn , ara[i] );
        return mn;
    }
    for( int i = l; i < (left+1)*block; i++ ) mn = min( mn , ara[i] );
    for( int i = left+1; i < right; i++ ) mn = min( mn , RMQ[i] );
    for( int i = right*block; i <= r; i++ ) mn = min( mn , ara[i] );
    return mn;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , q;
        scanf("%d %d",&n,&q);
        block = sqrt( n );
        Process( );
        for( int i = 0; i < n; i++ ) {
            scanf("%d",&ara[i]);
            SetBlock( i , ara[i] );
        }
        printf("Case %d:\n",tc);
        while( q-- ) {
            int l , r;
            scanf("%d %d",&l,&r);
            printf("%d\n",GetAns( l-1 , r-1 ) );
        }
    }
    return 0;
}
