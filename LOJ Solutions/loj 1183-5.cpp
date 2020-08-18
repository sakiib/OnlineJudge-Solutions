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

int Tree[ 4*N ] , Lazy[ 4*N ];

int gcd( int a , int b ) {
    if( b == 0 ) return a;
    return gcd( b , a % b );
}
void Build( int node , int b , int e ) {
    if( b > e  ) return;
    if( b == e ) {
        Tree[node] = Lazy[node] = 0;
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
    Lazy[node] = Lazy[left] + Lazy[right];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != -1 ) {
        Tree[node] = Lazy[node] * (e-b+1);
        if( b != e ) {
            Lazy[2*node] = Lazy[node];
            Lazy[2*node+1] = Lazy[node];
        }
        Lazy[node] = -1;
    }
}
void Update( int node , int b , int e ,int i , int  j , int val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] = val * (e-b+1);
        if( b != e ) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j ,val );
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
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , -1 , sizeof( Lazy ) );
        int n , q;
        scanf("%d%d",&n,&q);
        Build( 1 , 1 , n );
        printf("Case %d:\n",tc);
        while( q-- ) {
            int op;
            scanf("%d",&op);
            if( op == 1 ) {
                int l , r , val;
                scanf("%d%d%d",&l,&r,&val);
                Update( 1 , 1 , n , l+1 , r+1 , val );
            }
            else {
                int l , r;
                scanf("%d%d",&l,&r);
                int sum = Query( 1 , 1 , n , l+1 , r+1 );
                int tot = (r-l+1);
                if( sum%tot == 0 ) printf("%d\n",(sum/tot));
                else {
                    int g = gcd( sum , tot );
                    sum /= g , tot /= g;
                    if( tot == 1 ) printf("%d\n",sum);
                    else printf("%d/%d\n",sum,tot);
                }
            }
        }
    }
    return 0;
}
