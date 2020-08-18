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

int m , d , len;
char a[ 2005 ] , b[ 2005 ];
vector <int> num;
LL dp[2005][2][2005];

LL go( int pos , int chk , int rem , string s ) {
        if( pos >= len ) {
                cout << s << endl;
                return ( rem%m == 0 );
        }
        if( dp[pos][chk][rem] != -1 ) return dp[pos][chk][rem];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        if( !(pos&1) && ( i == d ) ) continue;
                        string k = s;
                        k += ( i + '0' );
                        ret += go( pos+1 , 1 , ( rem*10+i )%m , k );
                }
        }
        else {
               for( int i = 0; i < num[pos]; i++ ) {
                      if( !(pos&1) && ( i == d ) ) continue;
                      string k = s;
                      k += ( i + '0' );
                      ret += go( pos+1 , 1 , ( rem*10+i )%m , k );
               }
               if( (pos&1) && num[pos] == d ) {
                    string k = s;
                    k += ( num[pos] + '0' );
                    ret += go( pos+1 , 0 , ( rem*10+num[pos] )%m , k );
               }

        }
        return dp[pos][chk][rem] = ret;
}
LL solve( char *s ) {
        len = strlen( s );
        num.clear();
        for( int i = 0; i < len; i++ ) num.push_back( s[i]-'0' );
        memset( dp , -1 , sizeof(dp) );
        return go( 0 , 0 , 0 , "" );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&m,&d);
        scanf("%s %s",a,b);
        LL ans = solve( b );
        cout << "***********" << endl;
        ans -= solve( a );
        printf("Ans : %lld\n",ans);
        return 0;
}






