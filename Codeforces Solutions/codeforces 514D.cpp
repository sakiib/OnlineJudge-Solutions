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

LL n , m , k;
LL ara[ N ][ 10 ] , Tree[ 5*N ][ 10 ];

inline void Build( int id , LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node][id] = ara[b][id];
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)>>1;
    Build( id , left , b , mid );
    Build( id , right , mid+1 , e );
    Tree[node][id] = max( Tree[left][id] , Tree[right][id] );
}
inline LL Query( int id , LL node , LL b , LL e , LL i , LL j ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node][id];
    LL left = 2*node , right = 2*node+1 , mid = (b+e)>>1;
    LL q1 = Query( id , left , b , mid , i , j );
    LL q2 = Query( id , right , mid+1 , e , i , j );
    return max( q1 , q2 );
}
inline LL Tot( LL l , LL r ) {
    LL ret = 0;
    for( int i = 1; i <= m; i++ ) {
        ret += Query( i , 1 , 1 , n , l , r );
    }
    return ret;
}
inline bool Check( LL len ) {
    for( LL i = 1; i+len-1 <= n; i++ ) {
        if( Tot( i , i+len-1 ) <= k ) return true;
    }
    return false;
}
int main( int argc, char const *argv[] ) {
    scanf("%lld %lld %lld", &n , &m , &k );
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            scanf("%lld", &ara[i][j] );
        }
    }
    for( int i = 1; i <= m; i++ ) {
        Build( i , 1 , 1 , n );
    }
    LL lo = 0 , hi = n , ans = -1;
    while( lo <= hi ) {
        LL mid = ( lo+hi )>>1;
        if( Check( mid ) ) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    if( ans == - 1 ) {
        for( int i = 1; i <= m; i++ ) printf("0 ");
        printf("\n");
        return 0;
    }
    for( int i = 1; i+ans-1 <= n; i++ ) {
        if( Tot( i , i+ans-1 ) <= k ) {
            for( int j = 1; j <= m; j++ ) {
                printf("%lld ", Query( j , 1 , 1 , n , i , i+ans-1 ) );
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}
