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

string a , b;
int n;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        cin >> a >> b;
        if( a == b ) return cout << 0 << endl,0;
        int len = a.size();
        if( len == 1 ) return cout << 1 << endl,0;
        int ans = 0;
        for( int i = 0; i < len/2; i++ ) {
                char c1 = a[i] , c2 = a[len-1-i];
                char d1 = b[i] , d2 = b[len-1-i];
                if ( (c1 == d1 && c2 == d2) || (c1 == d2 && c2 == d1) || (c1 == c2 && d1 == d2) ) ans += 0;
                else if ( c1 == d1 || c1 == d2 || c2 == d1 || c2 == d2 || d1 == d2 ) ans += 1;
                else ans += 2;
        }
        if( len&1 && a[len/2] != b[len/2] ) ans++;
        cout << ans << endl;
        return 0;
}
