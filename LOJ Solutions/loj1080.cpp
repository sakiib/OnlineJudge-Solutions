#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
char str[ SZ ] , ch[5];
int tree[ 4*SZ ] , lazy[ 4*SZ ];
int len;

void propagate( int node , int b , int e ) {
        if( lazy[node] != 0 ) {
                tree[node] += lazy[node];
                if( b != e ) {
                        lazy[2*node] += lazy[node] , lazy[2*node+1] += lazy[node];
                }
                lazy[node] = 0;
        }
}
int query( int node , int b , int e , int pos ) {
        propagate( node , b , e );
        if( pos > e || pos < b || b > e ) return 0;
        if( b == e && b == pos ) return tree[node];
        int left = 2*node , right = left+1 , mid = (b+e)/2;
        return query( left , b , mid , pos ) + query( right , mid+1 , e , pos );
}
void update( int node , int b , int e , int i , int j , int v ) {
        propagate( node , b , e );
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] += v;
                if( b != e ) lazy[2*node] += v , lazy[2*node+1] += v;
                return;
        }
        int left = 2*node , right = left+1 , mid = (b+e)/2;
        update( left , b , mid , i , j , v ) , update( right , mid+1 , e , i , j , v );
        tree[node] = tree[left] + tree[right];
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s",str);
                len = strlen( str );
                int q;
                scanf("%d",&q);
                printf("Case %d:\n",tc);
                for( int i = 1; i <= q; i++ ) {
                        scanf("%s",ch);
                        if( ch[0] == 'I' ) {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                update( 1 , 1 , len , l , r , +1 );
                        }
                        else {
                                int pos;
                                scanf("%d",&pos);
                                int res = query( 1 , 1 , len , pos );
                                int x = str[pos-1]-'0';
                                if( res%2 == 0 ) printf("%d\n",x);
                                else printf("%d\n",x^1);
                        }
                }
                memset( tree , 0 , sizeof(tree) ) , memset( lazy , 0 , sizeof(lazy) );
        }
        return 0;
}
