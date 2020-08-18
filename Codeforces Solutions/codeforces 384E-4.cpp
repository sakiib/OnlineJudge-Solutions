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

LL n , m;
LL ara[ 2*N ];
LL Start[ 2*N ] , Finish[ 2*N ] , Level[ 2*N ];
LL Time = 0;
LL Tree[ 2*4*N ] , Lazy[ 2*4*N ];

vector <int> graph[ 2*N ];

void Propagate( LL node , LL b , LL e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] += ( Lazy[node] );
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
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( LL node , LL b , LL e , LL pos ) {
    Propagate( node , b , e );
    if( pos > e || pos < b ) return 0LL;
    if( b == e && b == pos ) return Tree[node];
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , pos );
    LL q2 = Query( right , mid+1 , e , pos );
    return ( q1+q2 );
}
void dfs( int s , int p ) {
    Start[s] = ++Time;
    Level[s] = Level[p]+1;
    for( int i = 0; i < graph[ s ].size(); i++ ){
        int next = graph[ s ][ i ];
        if( next == p ) continue;
        dfs( next , s );
    }
    Finish[ s ] = Time;
}
int main( int argc, char const *argv[] ) {
    scanf("%lld %lld",&n,&m);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld", &ara[i]);
    }
    for( int i = 1; i <= n-1; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    dfs( 1 , 0 );
    while( m-- ) {
        int op;
        scanf("%d",&op);
        if( op == 1 ) {
            int pos , val;
            scanf("%d %d",&pos,&val);
            int from = Start[pos] , to = Finish[pos];
            if( Level[pos]&1 ) Update( 1 , 1 , n , from , to , +val );
            else Update( 1 , 1 , n , from , to , -val );
        }
        else {
            int pos;
            scanf("%d",&pos);
            int x = Start[pos];
            LL ans = Query( 1 , 1 , n , x );
            if( Level[pos]&1 ) printf("%lld\n",ara[pos]+ans);
            else printf("%lld\n",ara[pos]-ans);
        }
    }
    return 0;
}


