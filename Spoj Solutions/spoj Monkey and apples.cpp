#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

struct node {
        node *l , *r;
        LL cnt;
        node() : l(nullptr) , r(nullptr) , cnt(0) {}
        node( node *l , node *r , LL cnt ) : l(l), r(r) , cnt(cnt) {}
} *root;

typedef node* pnode;

inline void update( pnode &cur , LL b , LL e , LL i , LL j ) {
        if( i > e || j < b || b > e ) return;
        if( !cur ) cur = new node();
        if( cur -> cnt == ( e - b + 1 ) ) {
                return;
        }
        if( i == b && j == e ) {
                cur -> cnt = ( e - b + 1 );
                return;
        }
        LL mid = ( b + e ) >> 1;
        update( cur -> l , b , mid , i , min( j , mid ) );
        update( cur -> r , mid + 1 , e , max( mid + 1 , i ) , j );
        cur -> cnt = 0;
        if( cur -> l ) cur -> cnt += cur -> l -> cnt;
        if( cur -> r ) cur -> cnt += cur -> r -> cnt;
}
inline LL query( pnode &cur , LL b , LL e , LL i , LL j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) cur = new node();
        if( cur -> cnt == 0 ) {
                //cout << "go way : " << b << " " << e << endl;
               return 0;
        }
        if( cur -> cnt == ( e - b + 1 ) ) return cur -> cnt;
        LL mid = ( b + e ) >> 1;
        LL ret = 0;
        if( b == e ) return 0;
        return query( cur -> l , b , mid , i , min( j , mid ) ) +
               query( cur -> r , mid + 1 , e , i , max( mid + 1 , i ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        root = new node();
        int t;
        cin >> t;
        LL c = 0;
        for( int tc = 1; tc <= t; tc++ ) {
                int typ;
                cin >> typ;
                if( typ == 1 ) {
                        LL l , r;
                        cin >> l >> r;
                        LL ans = query( root , 1 , inf , l + c , r + c );
                        cout << ans << endl;
                        c = ans;
                }
                else {
                        LL l , r;
                        cin >> l >> r;
                        update( root , 1 , inf , l + c , r + c );
                }
        }
        return 0;
}









