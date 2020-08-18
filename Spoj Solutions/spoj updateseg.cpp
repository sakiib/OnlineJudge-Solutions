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

LL Tree[ 4*N ] , Lazy[ 4*N ];

void Propagate( LL node , LL b , LL e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] += Lazy[node];
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( LL node , LL b , LL e , LL i , LL j , LL val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] += val;
        if( b != e ) {
            Lazy[2*node] += val;
            Lazy[2*node+1] += val;
        }
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j  , val );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( LL node , LL b , LL e , LL pos ) {
    Propagate( node , b , e  );
    if( pos < b || pos > e ) return 0;
    if( b==e && b == pos ) return Tree[node];
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , pos );
    LL q2 = Query( right , mid+1 , e , pos );
    return q1+q2;
}
void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = Lazy[node] = 0;
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
    Lazy[node] = Lazy[left] + Lazy[right];
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL n , q;
        scanf("%lld%lld",&n,&q);
        Build( 1 , 1 , n );
        while( q-- ) {
            LL l , r , val;
            scanf("%lld%lld%lld",&l,&r,&val);
            l++ , r++;
            Update( 1 , 1 , n , l , r , val );
        }
        int k;
        scanf("%d",&k);
        while( k-- ) {
            LL pos;
            scanf("%lld",&pos);
            printf("%lld\n",Query( 1 , 1 , n , pos ) );
        }
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , 0 , sizeof( Lazy ) );
    }
    return 0;
}

