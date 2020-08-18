#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

inline LL phi( LL n ) { /// for larger N , sqrt(N) -> runtime , or pollard rho
        LL ans = n;
        for( LL i = 2; i*i <= n; i++ ) {
                if( n%i == 0) ans -= ans/i;
                while( n%i == 0) n /= i;
        }
        if( n > 1) ans -= ans/n;
        return ans;
}
int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        for( int i = 1; i <= 20; i++ ) {
                cout << i << " " << phi( i ) << endl;
        }
        return 0;
}






