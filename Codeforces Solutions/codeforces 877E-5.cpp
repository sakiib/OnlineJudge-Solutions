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

vector <int> graph[ 2*N ];
int Time = 0;
int Start[ 2*N ] , Finish[ 2*N ] , Lazy[ 2*4*N ], Tree[ 2*4*N ];
char comm[ 10 ];

void dfs( int s , int p ) {
    Start[s] = ++Time;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == p ) continue;
        dfs( next , s );
    }
    Finish[s] = Time;
}
void Build( int node , int b , int e , int pos , int val ) {
    if( pos > e || pos < b || b > e ) return;
    if( b == e && b == pos ) {
        Tree[node] = val;
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid , pos , val );
    Build( right , mid+1 , e , pos , val );
    Tree[node] = Tree[left] + Tree[right];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] = (e-b+1)-Tree[node];
        if( b != e ) {
            Lazy[2*node] ^= 1;
            Lazy[2*node+1] ^= 1;
        }
        Lazy[node] = 0;
    }
}
int Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b || b > e ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
void Update( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b || b > e ) return;
    if( i <= b && j >= e ) {
        Tree[node] = (e-b+1)-Tree[node];
        if( b != e ) {
            Lazy[2*node] ^= 1;
            Lazy[2*node+1] ^= 1;
        }
        return;
    }
     int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
     Update( left , b , mid , i , j );
     Update( right , mid+1 , e , i , j );
     Tree[node] = Tree[left] + Tree[right];
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 2; i <= n; i++ ) {
        int val;
        scanf("%d",&val);
        graph[ i ].push_back( val );
        graph[ val ].push_back( i );
    }
    dfs( 1 , 0 );
    for( int i = 1; i <= n; i++ ) {
        int cur;
        scanf("%d",&cur);
        Build( 1 , 1 , n , Start[i] , cur );
    }
    int q , node;
    scanf("%d",&q);
    while( q-- ) {
        scanf("%s %d",comm,&node);
        if( comm[0] == 'p' ) Update( 1 , 1 , n , Start[node] , Finish[node] );
        else printf("%d\n",Query( 1 , 1 , n , Start[node] , Finish[node] ));
    }
    return 0;
}
