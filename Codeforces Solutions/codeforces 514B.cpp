#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

int main( ) {
        IO;
        int n;
        cin >> n;
        string s;
        cin >> s;
        map <char,string> M;
        M[ '2' ] = "2" , M[ '3' ] = "3" , M[ '4' ] = "322";
        M[ '5' ] = "5" , M[ '6' ] = "53" , M[ '7' ] = "7";
        M[ '8' ] = "7222" , M[ '9' ] = "7332";
        string ans = "";
        for( int i = 0; i < s.size(); i++ ) {
                if( s[i] != '1' || s[i] != '0' ) ans += M[ s[i] ];
        }
        sort( ans.rbegin() , ans.rend() );
        cout << ans << endl;
        return 0;
}







