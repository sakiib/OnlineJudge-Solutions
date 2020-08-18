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

LL a[ 2*N ];
LL sum[ 2*N ];
int n;
LL ans;

LL solve( int id , LL tot ) {
        int lo = id+1 , hi = n;
        LL ret = 0;
        while( lo <= hi ) {
               int mid = ( lo+hi )/2;
               LL s = sum[n] - sum[mid-1];
               if( s == tot ) return tot;
               if( s < tot ) hi = mid-1;
               else lo = mid+1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i] , sum[i] += sum[i-1] + a[i];
        }
        for( int i = 1; i <= n; i++ ) {
                ans = max( ans , solve( i , sum[i] ) );
        }
        cout << ans << endl;
        return 0;
}






