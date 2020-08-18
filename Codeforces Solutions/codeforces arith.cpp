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

map <char,int> cnt;
int odd;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        string a , b;
        cin >> a >> b;
        for( auto c : a ) cnt[c]++;
        for( auto c : b ) cnt[c]++;
        for( char ch = 'a'; ch <= 'z'; ch++ ) if( cnt[ch]&1 ) odd++;
        if( odd > 1 ) cout << "NO" << endl;
        else cout << "YES" << endl;
        return 0;
}





