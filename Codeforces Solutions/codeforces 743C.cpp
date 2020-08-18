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

LL n;

bool ok( int x , int y , int z ) {
    //cout << x << " " << y << " " << z << endl;
    LL num = x*y+y*z+z*x;
    LL denom = x*y*z;
    LL g = __gcd( num , denom );
    num /= g , denom /= g;
    return ( num == 2 && denom == n );
}
void Bruteforce( ) {
    for( int i = 1; i <= 100; i++ ) {
        for( int j = i+1; j <= 100; j++ ) {
            for( int k = j+1; k <= 100; k++ ) {
                if( ok( i , j , k ) ) cout << i << " " << j << " " << k << endl;
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    if( n == 1 ) {
        cout << -1 << endl;
        return 0;
    }
    //Bruteforce( );
    cout << n << " "<< n+1 << " " << n*(n+1) << endl;
    return 0;
}

