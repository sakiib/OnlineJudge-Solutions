#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;


int main( int argc , char const *argv[] ) {
        Fast_IO;
        H.GeneratePower();
        int n , m , q;
        cin >> n >> m >> q;
        string s , t;
        cin >> s >> t;
        H.Initialize( s );
        H.BuildHash();
        pair <LL,LL> P = H.GetHash( t );
        while( q-- ) {
                int l , r;
                cin >> l >> r;
                --l , --r;
                int ans = 0;
                for( int i = l; i+m-1 <= r; i++ ) {
                        if( H.GetFHash( i , i+m-1 ) == P ) ans++;
                }
                cout << ans << endl;
        }
        return 0;
}







