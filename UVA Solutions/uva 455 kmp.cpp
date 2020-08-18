#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int Failure[ N ];

void Failure_Function( string pattern , int lp ) {
        Failure[0] = Failure[1] = 0;
        for( int i = 2; i <= lp; i++ ) {
                int j = Failure[i-1];
                while( true ) {
                        if( pattern[j] == pattern[i-1] ) {
                                Failure[i] = j+1;
                                break;
                        }
                        if( j == 0 ) {
                                Failure[i] = 0;
                                break;
                        }
                        j = Failure[j];
                }
        }
}

int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >> s;
                int len = s.size();
                Failure_Function( s , len );
                int ans = len;
                for( int i = 2; i <= len; i++ ) {
                        if( Failure[i] != 0 && ( i%( i - Failure[i] ) == 0 ) ) {
                                //cout << i << " " << i/( i - Failure[i] ) << endl;
                                int k = i/( i - Failure[i] );
                                int x = len/k;
                                ans = min( ans , x );
                        }
                }
                cout << ans << endl;
        }
        return 0;
}






