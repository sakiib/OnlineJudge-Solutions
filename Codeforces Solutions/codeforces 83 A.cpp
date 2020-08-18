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

const int k = 30;
int n;
int a[ N ];
int mx[ N+5 ][ k ] , mn[ N+5 ][ k ];
int lg[ N ];

void Build_Table( ) {
        for( int i = 1; i <= n; i++ ) mx[i][0] = mn[i][0] = a[i];
        //for( int i = 2; i <= n; i++ ) lg[i] = lg[i/2] + 1;
        for( int j = 1; ( 1 << j ) <= n; j++ ) {
                for( int i = 1; i+( 1 << j )-1 <= n; i++ ) {
                        mn[i][j] = min( mn[i][j-1] , mn[ i+( 1 << (j-1)) ][j-1] );
                        mx[i][j] = max( mx[i][j-1] , mx[ i+( 1 << (j-1)) ][j-1] );
                }
        }
}
pair <int,int> Query( int l , int r ) {
        if( l > r ) swap( l , r );
        int k = log2(r-l+1);
        int MN = min( mn[l][k] , mn[ r-( 1 << k )+1 ][k] );
        int MX = max( mx[l][k] , mx[ r-( 1 << k )+1 ][k] );
        return { MN , MX };
}
int go( int l , int r ) {
        int lo = l , hi = r , ret = l;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                pair <int,int> res = Query( l , mid );
                if( res.first == res.second ) {
                        ret = mid;
                        lo = mid + 1;
                }
                else hi = mid - 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        Build_Table( );
        int i = 1;
        LL ans = 0;
        while( i <= n ) {
                int pos = go( i , n );
                int len = pos - i + 1;
                ans += ( 1LL * len * ( len + 1 )/2 );
                i = pos+1;
        }
        cout << ans << endl;
        return 0;
}
