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

map <char,int> M;
set <char> S;

int main( int argc, char const *argv[] ) {
    int k;
    cin >> k;
    string s;
    cin >> s;

    for( auto x : s ) M[x]++ , S.insert( x );
    for( char i = 'a'; i <= 'z'; i++ ) {
        if( M[i] > 0 && M[i]%k != 0 ) {
            cout << -1 << endl;
            return 0;
        }
    }
    string ans = "";
    for( auto x : S ) {
        for( int i = 0; i < M[x]/k; i++ ) ans += x;
    }
    while( k-- ) cout << ans;
    return 0;
}

