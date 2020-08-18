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

LL a , b;
LL cnt[ 20 ] = {0};
LL ans = 0;

void solve( ) {
    for( int i = 9; i >= 0; i-- ) {
        if( cnt[i] >= 1 ) {
            cnt[i]--;
            LL temp = ans*10+i;
            for( int j = 0; j <= 9; j++ ) {
                for( int k = 1; k <= cnt[j]; k++ ) {
                    temp = temp*10+j;
                }
            }
            if( temp <= b ) {
                ans = ans*10+i;
                solve( );
            }
            else cnt[i]++;
            }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> a >> b;
    while( a ) {
        cnt[ a%10 ]++;
        a /= 10;
    }
    solve( );
    cout << ans << endl;
    return 0;
}

