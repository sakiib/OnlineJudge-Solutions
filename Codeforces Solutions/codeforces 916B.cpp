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

LL val[ 100 ];
LL n , k;

bool Check( LL s ) {
    LL taken = 0 , temp = n;
    for( LL i = s; i >= 0;i-- ) {
        if( val[i] <= temp ) {
            while( val[i] <= temp ){
                temp -= val[i];
                taken++;
            }
        }
        if( temp <= 0 ) break;
    }
    return ( temp == 0 && taken == k );
}
LL Fix( ) {
    LL ret = 0;
    for( LL i = 63; i >= 0; i-- ) {
        if( Check(i) ) {
            ret = i;
        }
    }
    return ret;
}
void calc( ) {
    val[0] = 1LL;
    for( LL i = 1; i <= 63; i++ ) {
        val[i] = val[i-1]*2LL;
    }
}
int main( int argc, char const *argv[] ) {
    calc( );
    cin >> n >> k;
    LL x = Fix( );
    cout << x << endl;
    return 0;
}

