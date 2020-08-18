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

const int base = 31;
LL p[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        p[0] = 31;
        for( int i = 1; i < 5005; i++ ) {
                p[i] = p[i-1] * base;
        }
        int t;
        cin >> t;
        while( t-- ) {
                unordered_map <LL,int> M;
                unordered_map <LL,int> A;
                string s;
                cin >> s;
                int len = s.size();
                for( int i = 0; i < len; i++ ) {
                        //string x = "";
                        LL Hash = 0;
                        int cnt = 0;
                        for( int j = i , k = 0; j < len; j++ , k++ ) {
                                Hash += ( p[k] * s[j] );
                                cnt++;
                                M[ Hash ]++;
                                A[ Hash ] = cnt;
                                //cout << "Hash : " << Hash << endl;
                        }
                }
                int ans = 0;
                for( auto x : M ) {
                        if( x.second >= 2 ) {
                            ans = max( ans , A[ x.first ] );
                        }
                }
                cout << ans << endl;
        }
        return 0;
}






