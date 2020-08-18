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

int n , q;
int ara[ N ];
int Sum[ N ];
int block;

int GetID( int index ) {
    return ( index/block );
}
void SetBlock( int index , int val ) {
    int id = GetID( index );
    Sum[id] += val;
}
void Update( int index , int val ) {
    int id = GetID( index );
    Sum[id] += val;
}
int GetSum( int l , int r ) {
    int left = GetID( l ) , right = GetID( r );
    int sum = 0;
    if( left == right ) {
        for( int i = l; i <= r; i++ ) sum += ara[i];
        return sum;
    }
    for( int i = l; i < (left+1)*block; i++ ) sum += ara[i];
    for( int i = left+1; i < right; i++ ) sum += Sum[i];
    for( int i = right*block; i <= r; i++ ) sum += ara[i];
    return sum;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d %d",&n,&q);
        block = sqrt( n );
        for( int i = 0; i < n; i++ ) {
            scanf("%d",&ara[i]);
            SetBlock( i , ara[i] );
        }
        printf("Case %d:\n",tc);
        while( q-- ) {
            int op;
            scanf("%d",&op);
            if( op ==1 ) {
               int pos;
               scanf("%d",&pos);
               printf("%d\n",ara[pos]);
               Update( pos , -ara[pos] );
               ara[pos] = 0;
            }
            else if( op == 2 ) {
               int pos , val;
               scanf("%d %d",&pos,&val);
               Update( pos , val );
               ara[pos] += val;
            }
            else {
                int l , r;
                scanf("%d %d",&l,&r);
                printf("%d\n",GetSum( l , r ) );
            }
        }
        memset( Sum , 0 , sizeof(Sum) );
    }
    return 0;
}

