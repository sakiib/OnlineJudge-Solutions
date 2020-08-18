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

map <char,int> cnt;

int main( int argc, char const *argv[] ) {
    string s;
    cin >> s;
    for( auto x : s ) cnt[x]++;
    int odd = 0;
    for( char i = 'a'; i <= 'z'; i++ ) {
        if( cnt[i]%2 == 1 ) odd++;
    }
    if( odd == 3 && s.size()%2 == 1 ) puts("YES");
    else if( odd == 2 && s.size()%2 == 0 ) puts("YES");
    else puts("NO");
    return 0;
}
