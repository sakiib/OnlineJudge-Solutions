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
int odd;

int main( int argc, char const *argv[] ) {
    string s;
    cin >> s;
    for( auto x : s ) M[ x ]++;
    for( auto x : M ) {
        if( x.second%2 ) odd++;
    }
    if( odd <= 1 ) cout <<"YES"<<endl;
    else cout << "NO" << endl;
    return 0;
}

