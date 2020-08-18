#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , q;
string s;
int tree[ 4*N ][ 30 ] , lazy[ 4*N ][ 30 ];
int cnt[ 30 ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node][s[b]-'a'+1] = 1;
                return;
        }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        build( left , b , mid ) , build( right , mid+1 , e );
        for( int i = 1; i <= 26; i++ ) tree[node][i] = tree[left][i] + tree[right][i];
}
void propagate( int node , int b , int e , int id ) {
        if( lazy[node][id] != -1 ) {
                tree[node][id] = lazy[node][id] * (e-b+1);
                if( b != e ) {
                        lazy[2*node][id] = lazy[node][id];
                        lazy[2*node+1][id] = lazy[node][id];
                }
                lazy[node][id] = -1;
        }
}
int query( int node , int b , int e , int i , int j , int id ) {
        propagate( node , b , e , id );
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node][id];
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        return ( query( left , b , mid , i , j , id ) + query( right , mid+1 , e , i , j , id ) );
}
void update( int node , int b , int e , int i , int j , int id , int mul ) {
        propagate( node , b , e , id );
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node][id] = mul * ( e-b+1 );
                if( b != e ) {
                        lazy[2*node][id] = mul;
                        lazy[2*node+1][id] = mul;
                }
                lazy[node][id] = -1;
                return;
        }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        update( left , b , mid , i , j , id , mul ) , update( right , mid+1 , e , i , j , id , mul );
        tree[node][id] = tree[left][id] + tree[right][id];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        cin >> n >> q >> s;
        s = " " + s;
        memset( lazy , -1 , sizeof(lazy) );
        build( 1 , 1 , n );

        //cout << tree[1][1] << " " << tree[1][2] << " " << tree[1][3] << endl;

        while( q-- ) {
                int l , r , type;
                cin >> l >> r >> type;
                int from = l;
                if( type == 0 ) from = r;
                if( type == 1 ) {
                        for( int i = 1; i <= 26; i++ ) cnt[i] = query( 1 , 1 , n , l , r , i );
                        for( int i = 1; i <= 26; i++ ) {
                                if( cnt[i] == 0 ) continue;
                                update( 1 , 1 , n , l , r , i , 0 );
                                update( 1 , 1 , n , from , from + cnt[i] - 1 , i , 1 );
                                from += cnt[i];
                        }
                }
                else {
                        for( int i = 1; i <= 26; i++ ) cnt[i] = query( 1 , 1 , n , l , r , i );
                        for( int i = 1; i <= 26; i++ ) {
                                if( cnt[i] == 0 ) continue;
                                update( 1 , 1 , n , l , r , i , 0 );
                                update( 1 , 1 , n , from - cnt[i] + 1 , from , i , 1 );
                                from -= cnt[i];
                        }
                }

                //cout << tree[1][1] << " " << tree[1][2] << " " << tree[1][3] << endl;
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= 26; j++ ) {
                        if( query( 1 , 1 , n ,  i , i , j ) > 0 ) {
                                 cout << (char)( j + 'a' - 1 );
                                 break;
                        }
                }
        }
        return 0;
}






