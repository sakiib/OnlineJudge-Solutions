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

string s;

bool can_win( string s , int rem ) {
        //cout << s << " " << rem << endl;
        if( rem == 0 ) return 1;
        for( int i = 0; i < s.size(); i++ ) {
                int cur = rem - (s[i]-'0');
                string k = s;
                k.erase( k.begin()+i );
                if( cur%3 == 0 ) {
                       if( can_win( k , cur ) == 1 ) return 2;
                }
        }
        return 1;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> s;
                int tot = 0;
                cout << "Case " << tc << ": ";
                if( s.size() == 1 ) {
                        cout << "S" << endl;
                        continue;
                }
                for( int i = 0; i < s.size(); i++ ) tot += ( s[i] - '0' );
                if( can_win( s , tot ) == 1 ) cout << "T" << endl;
                else cout << "S" << endl;
        }
        return 0;
}






