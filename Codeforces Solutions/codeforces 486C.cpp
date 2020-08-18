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

int n , k;
string s;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k >> s;
        if( n%2 == 0 ) {
              string x = s.substr( 0 , n/2 );
              string y = s.substr( n/2 , n/2 );
              cout << x << " " << y << endl;

        }
        else {
                string x = s.substr( 0 , n/2 );
                string y = s.substr( n/2+1 , n/2 );
                cout << x << " " << y << endl;

        }
        return 0;
}






