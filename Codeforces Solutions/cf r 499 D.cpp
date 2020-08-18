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

int n , m;
int a[ N ] , cnt[ N ] = {0};

bool ok( int d ) {
        int cnt = 0;
        for( int i = 1; i <= m; ) {
                set <int> S;
                for( int j = i; j <= i+d-1; j++ ) S.insert( a[j] );
                if( S.size() == 1 ) cnt++ , i += d;
                else i++;
        }
        return ( cnt >= n );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m;
        for( int i = 1; i <= m; i++ ) {
                cin >> a[i] , cnt[ a[i] ]++;
        }
        sort( a+1 , a+m+1 );
        if( n > m ) return cout << 0 << endl,0;
        int lo = 1 , hi = m , ans = 0;
        while( lo <= hi ) {
                int mid = (lo+hi) >> 1;
                if( ok( mid ) ) {
                        ans = mid;
                        lo = mid+1;
                }
                else hi = mid-1;
        } return cout << ans << endl,0;
        return 0;
}






