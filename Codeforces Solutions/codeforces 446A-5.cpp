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

int main( int argc, char const *argv[] ) {
    int x , h , m;
    cin >> x >> h >> m;
    if( h%10 == 7 || m%10 == 7 ) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    while( true ){
        ans ++;
        m -= x;
        if( m < 0 ) {
            m += 60;
            h = (( h-1 )%24+24)%24;
        }
        if( h%10 == 7 || m%10 == 7 ) break;
    }
    cout << ans << endl;
    return 0;
}

