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

string a , b;
int n;
int ans;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        cin >> a >> b;
        if( a == b ) return cout << 0 << endl,0;
        int len = a.size();
        if( len == 1 ) return cout << 1 << endl,0;
        for( int i = 0; i < len/2-1; i++ ) {
                if( a[i] == b[i] && a[len-1-i] == b[len-1-i] ) continue;
                int add = 2;
                string s = "";
                s += ( a[i] );
                s += ( a[len-1-i] );
                s += ( b[i] );
                s += ( b[len-1-i] );
                sort( s.begin() , s.end() );
                do {
                        int cnt = 0;
                        if( s[0] != s[2] ) cnt++;
                        if( s[1] != s[3] ) cnt++;
                        //cout << s[0] << s[1] << endl;
                        //cout << s[2] << s[3] << endl;
                        add = min( add , cnt );

                } while( next_permutation( s.begin() , s.end() ) );
                ans += add;
                cout <<i << " " << ans << " " << add << endl;
        }
        if( len&1 ) if( a[len/2] != b[len/2] ) ans++;
        cout << ans << endl;
        return 0;
}
