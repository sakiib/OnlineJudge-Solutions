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
int Start[ 2*N ] , Finish[ 2*N ] , Lazy[ 2*4*N ];

struct segment {
    int on , off;
} Tree[ 2*4*N ];

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
        ( val == 1 ? Tree[node].on = 1 : Tree[node].off = 1 );
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid , pos , val );
    Build( right , mid+1 , e , pos , val );
    Tree[node].on = Tree[left].on + Tree[right].on;
    Tree[node].off = Tree[left].off + Tree[right].off;
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        if( Lazy[node]%2 ) swap( Tree[node].on , Tree[node].off );
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
int Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b || b > e ) return 0;
    if( i <= b && j >= e ) return Tree[node].on;
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
void Update( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b || b > e ) return;
    if( i <= b && j >= e ) {
        swap( Tree[node].on , Tree[node].off );
        if( b != e ) {
            Lazy[2*node] += 1;
            Lazy[2*node+1] += 1;
        }
        return;
    }
     int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
     Update( left , b , mid , i , j );
     Update( right , mid+1 , e , i , j );
     Tree[node].on = Tree[left].on + Tree[right].on;
     Tree[node].off = Tree[left].off + Tree[right].off;
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
    int q;
    scanf("%d",&q);
    while( q-- ) {
        string comm;
        int node;
        cin >> comm >> node;
        if( comm == "pow" ) Update( 1 , 1 , n , Start[node] , Finish[node] );
        else printf("%d\n",Query( 1 , 1 , n , Start[node] , Finish[node] ));
    }
    return 0;
}

