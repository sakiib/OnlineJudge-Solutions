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

LL n , h , a , b , k;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> h >> a >> b >> k;
        while( k-- ) {
                LL ta , fa , tb , fb;
                cin >> ta >> fa >> tb >> fb;
                LL ans = abs( ta - tb );
                if( fa > b && fb > b && ta != tb ) {
                        ans += ( fa-b+fb-b );
                }
                else if( fa < a && fb < b && ta != tb ) {
                        ans += ( a-fa+a-fb );
                }
                else ans += abs( fa-fb );
                cout << ans << endl;
        }
        return 0;
}
