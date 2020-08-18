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

int ara[ N ];
int n , d;

struct data {
    int mx , mn;
};
data BLOCK[ block ];

void process( ) {
    for( int i = 0; i < block; i++ ) {
        BLOCK[i].mx = -inf;
        BLOCK[i].mn = inf;
    }
}
int GetID( int index ) {
    return ( index/block );
}
void SetBlock( int index , int val ) {
    int id = GetID( index );
    BLOCK[id].mx = max( BLOCK[id].mx , val );
    BLOCK[id].mn = min( BLOCK[id].mn , val );
}
pair <int,int> GetAns( int l , int r ) {
    int left = GetID( l ) , right = GetID( r );
    ii p = make_pair(-inf,inf);
    if( left == right ) {
        for( int i = l; i <= r; i++ ) {
            p.first = max( p.first , ara[i] );
            p.second = min( p.second , ara[i] );
        }
        return p;
    }
    for( int i = l; i < (left+1)*block; i++ ) {
        p.first = max( p.first , ara[i] );
        p.second = min( p.second , ara[i] );
    }
    for( int i = left+1; i < right; i++ ) {
        p.first = max( p.first , BLOCK[i].mx );
        p.second = min( p.second , BLOCK[i].mn );
    }
    for( int i = right*block; i <= r; i++ ) {
        p.first = max( p.first , ara[i] );
        p.second = min( p.second , ara[i] );
    }
    return p;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d %d",&n,&d);
        process( );
        for( int i = 0; i < n; i++ ) {
            scanf("%d",&ara[i]);
            SetBlock( i , ara[i] );
        }
        int lo = 0 , hi = d-1 , res = -inf;
        while( hi < n ) {
            ii ans = GetAns( lo , hi );
            int rmx = ans.first;
            int rmn = ans.second;
            res = max( res , abs( rmx-rmn ) );
            lo++ , hi++;
        }
        printf("Case %d: %d\n",tc,res);
    }
    return 0;
}

