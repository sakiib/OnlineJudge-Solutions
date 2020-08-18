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

LL a , b;
int len;
vector <int> num;
LL dp[16][20][20][20][20][20];

void calc( LL x ) {
        num.clear();
        while( x ) {
                num.push_back( x%10 ) , x /= 10;
        }
        reverse( num.begin() , num.end() );
        len = num.size();
}
LL solve( LL x ) {
        calc( x );
        memset( dp , -1 , sizeof(dp) );
        return go( x );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        while( cin >> a >> b ) {
                if( a == 0 && b == 0 ) break;
                cout << solve( b ) - solve( a-1 ) << endl;
        }
        return 0;
}






