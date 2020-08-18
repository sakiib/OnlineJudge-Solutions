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

int n , k , mn = inf;
string s;
int cnt[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k >> s;
        for( int i = 0; i < s.size(); i++ ) cnt[ s[i]-'A'+1 ]++;
        for( int i = 1; i <= k; i++ ) mn = min( mn , cnt[i] );
        cout << mn*k << endl;
        return 0;
}






