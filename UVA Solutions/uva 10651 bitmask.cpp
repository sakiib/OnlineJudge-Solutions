#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL INF = 1e18;

int setbit( int num , int idx , int val = 1 ) {
    return ( val ) ? ( num | ( 1 << idx ) ) : ( num &~ ( 1 << idx ) );
}
int getbit( int num , int idx ) {
    return  ( ( ( num >> idx ) & 1 ) == 1 );
}
int countbit( int num ) {
    int ret = 0;
    while( num ) {
        if( num&1 ) ret++;
        num >> 1;
    }
    return ret;
}

int dp[ 1 << 12 ];

int solve( int mask ) {
    if( dp[mask] != -1 ) return dp[mask];
    int ret = 0;
    for( int i = 0; i < 10; i++ ) {
        if( getbit( mask , i ) && getbit( mask , i+1 ) && !getbit( mask , i+2 ) ) {
            int tmask = mask;
            tmask = setbit( tmask , i+0 , 0 );
            tmask = setbit( tmask , i+1 , 0 );
            tmask = setbit( tmask , i+2 , 1 );
            ret = max( ret , 1+solve( tmask ) );
        }

        if( !getbit( mask , i ) && getbit( mask , i+1 ) && !getbit( mask , i+2 ) ) {
            int tmask = mask;
            tmask = setbit( tmask , i+0 , 1 );
            tmask = setbit( tmask , i+1 , 0 );
            tmask = setbit( tmask , i+2 , 0 );
            ret = max( ret , 1+solve( tmask ) );
        }
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        string s;
        cin >> s;
        int mask = 0 , cnt = 0;
        for( int i = 0; i < s.size(); i++ ) {
            if( s[i] == 'o' ) {
                mask = setbit( mask , i , 1 );
                cnt++;
            }
        }
        cout << mask << endl;
        memset( dp , -1 , sizeof(dp) );
        cout << cnt-solve( mask ) << endl;
    }
    return 0;
}

