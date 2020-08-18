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

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        for(int i = 2; i <= 300; i++ ) {
                for( int j = 4; j <= 200; j++ ) {
                        cout << __gcd( i , j ) << " " << __gcd( i , abs(i-j) )<< endl;
                }
        }
        return 0;
}






