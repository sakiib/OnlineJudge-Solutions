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

char str[ N ] , s[ 10 ];
int ara[ N ] , Tree[ 4*N ] , Lazy[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
       Tree[node] = 0;
       Lazy[node] = 0;
       return;
    }
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
    Lazy[node] = Lazy[left] + Lazy[right];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] += ( Lazy[node] );
        if( b != e ) {
            Lazy[ 2*node ] += Lazy[node];
            Lazy[ 2*node+1 ] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] += 1;
        if( b != e ) {
        Lazy[ 2*node ] += 1;
        Lazy[ 2*node+1 ] += 1;
        }
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    Update( left , b , mid , i , j );
    Update( right , mid+1 , e , i , j );
    Tree[node] = Tree[left] + Tree[right];
}
int Query( int node , int b , int e , int pos ) {
    Propagate( node , b , e );
    if( pos > e || pos < b ) return 0;
    if( b == e && b == pos ) return Tree[node];
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    int q1 = Query( left , b , mid , pos );
    int q2 = Query( right , mid+1, e , pos );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%s",str);
        int len = strlen( str );
        Build( 1 , 1 , len );
        printf("Case %d:\n",tc);
        int q;
        scanf("%d",&q);
        while( q-- ) {
            scanf("%s",s);
            if( s[0] == 'I' ) {
                int l , r;
                scanf("%d%d",&l,&r);
                Update( 1 , 1 , len , l , r );
            }
            else {
                int pos;
                scanf("%d",&pos);
                int tot = Query( 1 , 1 , len , pos );
                --pos;
                if( tot%2 == 0 ) {
                    printf("%c\n",str[pos]);
                }
                else {
                    if( str[pos] == '1' ) printf("0\n");
                    else printf("1\n");
                }
            }
        }
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , 0 , sizeof( Lazy ) );
    }
    return 0;
}

