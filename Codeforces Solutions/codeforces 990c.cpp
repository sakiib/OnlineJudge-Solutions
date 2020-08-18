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

map <LL,LL> OP , CL;
LL balance , ans;

void process( string s ) {
        LL op = 0 , cl = 0;
        for( int i = 0; i < s.size(); i++ ) {
                if( s[i] == '(' ) op++;
                else {
                        if( op ) op--;
                        else cl++;
                }
        }
        if( op && cl ) return;
        if( op == 0 && cl == 0 ) balance++;
        if( op ) OP[ op ]++;
        if( cl ) CL[ cl ]++;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >> s;
                process( s );
        }
        ans = balance * balance;
        for( auto x : OP ) ans += ( x.second * CL[ x.first ] );
        cout << ans << endl;
        return 0;
}






