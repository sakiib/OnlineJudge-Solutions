#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1000000007;

int A[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n , a , b;
        cin >> n >> a >> b;
        for( int i = 1; i <= n; i++ ) cin >> A[i];
        int ans = 0;
        for( int i = 1 , j = n; i <= n/2; i++ , j-- ) {
                if( A[i] != 2 && A[j] != 2 ) {
                        if( A[i] != A[j] ) return cout << -1 << endl,0;
                        continue;
                }
                if( A[i] == 2 && A[j] == 2 ) ans += ( 2 * min( a , b ) );
                else if( A[i] == 2 ) {
                        if( A[j] == 0 ) ans += a;
                        else ans += b;
                }
                else {
                        if( A[i] == 0 ) ans += a;
                        else ans += b;
                }
        }
        if( n&1 ) {
                if( A[n/2+1] == 2 ) ans += min( a , b );
        }
        cout << ans << endl;
        return 0;
}







