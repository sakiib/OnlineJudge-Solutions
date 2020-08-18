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

int ara[ N ] , Tree[ 4*N ] ,  Lazy[ 4*N ];


vector <int> isprime( 10*N , true );

void sieve( ) {
    isprime[0] = false , isprime[1] = false;
    for( int i = 4; i <= 10*N; i+=2 ) {
        isprime[i] = false;
    }
    int sq = sqrt( 10*N );
    for( int i = 3; i <= sq; i+=2 ) {
        if( isprime[i] ) {
            for( int j = i*i ; j <= 10*N; j+=2*i ) {
                isprime[j] = false;
            }
        }
    }
}
void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b ==  e ) {
        if( isprime[ ara[b] ] ) Tree[node] = 1;
        else Tree[node] = 0;
        Lazy[node] = 0;
        return;
    }
    int left = 2*node ; int right = 2*node+1; int mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
    Lazy[node] = Lazy[left] + Lazy[right];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        if( isprime[ Lazy[node] ] ) Tree[node] = (e-b+1);
        else Tree[node] = 0;
        if( b != e ) {
            Lazy[2*node] = Lazy[node];
            Lazy[2*node+1] = Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int i , int j , int val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        if( isprime[ val ] ) Tree[node] = (e-b+1);
        else Tree[node] = 0;
        if( b != e ) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = Tree[left] + Tree[right];
}
int Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    int t; sieve();
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , q;
        scanf("%d%d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        Build( 1 , 1 , n );
        printf("Case %d:\n",tc);
        while( q-- ) {
            int op;
            scanf("%d",&op);
            if( op == 0 ) {
                int l , r , val;
                scanf("%d%d%d",&l,&r,&val);
                Update( 1 , 1 , n , l , r , val );
            }
            else {
                int l , r;
                scanf("%d%d",&l,&r);
                printf("%d\n",Query( 1 , 1 , n , l , r ) );
            }
        }
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , 0 , sizeof( Lazy ) );
    }
    return 0;
}

