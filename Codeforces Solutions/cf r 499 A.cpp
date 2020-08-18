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

int n , k , len;
string s;

void go( int prev , int taken , int cost ) {
        if( taken == k ) {
                cout << cost << endl;
                exit(0);
        }
        for( int i = prev+1; i < len; i++ ) {
                int d = s[i] - s[prev];
                if( d > 1 ) go( i , taken+1 , cost+(s[i]-'a'+1) );
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k >> s;
        sort( s.begin() , s.end() );
        len = n;
        for( int i = 0; i < len; i++ ) go( i , 1 , (s[i]-'a'+1) );
        return cout << -1 << endl,0;
        return 0;
}






