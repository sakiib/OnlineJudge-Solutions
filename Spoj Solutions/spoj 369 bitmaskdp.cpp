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

int dp[51][20][20][20][2];
vector <int> num;
int len , mx;

void calc( string n ) {
        num.clear();
        for( int i = 0; i < n.size(); i++ ) {
                num.push_back( n[i]-'0' );
        }
        len = num.size();
}
int go( int pos , int t , int s , int n , int chk ) {
        if( t > mx || s > mx || n > mx ) return 0;
        if( pos >= len ) return ( t > 0 && t == s && s == n );
        int ret = 0;
        if( dp[pos][t][s][n][chk] != -1 ) return dp[pos][t][s][n][chk];
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( pos+1 , t+(i==3) , s+(i==6) , n+(i==9) , 1 );
                        if( ret >= mod ) ret -= mod;
                }
        }
        else {
                for( int i = 0; i < num[pos]; i++ ) {
                        ret += go( pos+1 , t+(i==3) , s+(i==6) , n+(i==9) , 1 );
                        if( ret >= mod ) ret -= mod;
                }
                ret += go( pos+1 , t+(num[pos]==3) , s+(num[pos]==6) , n+(num[pos]==9) , 0 );
                if( ret >= mod ) ret -= mod;
        }
        return dp[pos][t][s][n][chk] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                string a , b;
                cin >> a >> b;
                memset( dp , -1 , sizeof(dp) );
                calc( b );
                mx = len/3;
                int ans = go( 0 , 0 , 0 , 0 , 0 );
                memset( dp , -1 , sizeof(dp) );
                calc( a );
                mx = len/3;
                ans -= go( 0 , 0 , 0 , 0 , 0 );
                if( ans < 0 ) ans = (ans+mod)%mod;
                int th = 0 , sx = 0 , ni = 0;
                for( int i = 0; i < a.size(); i++ ) {
                    if( a[i] == '3' ) th++;
                    if( a[i] == '6' ) sx++;
                    if( a[i] == '9' ) ni++;
                }
                if( th == sx && sx == ni && th > 0 ) ans --;
                if( ans < 0 ) ans = (ans+mod)%mod;
                cout << ans << endl;
        }
        return 0;
}






