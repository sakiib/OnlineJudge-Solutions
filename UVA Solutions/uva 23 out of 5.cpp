#include <bits/stdc++.h>
using namespace std;

int ara[ 10 ];
bool f;
bool used[ 10 ];

void solve( int taken , int cur ) {
    if ( taken > 5 ) return;
    if ( taken == 5 ) {
        if ( cur == 23 ) {
            f = true;
            return;
        }
    }
    for ( int j = 1; j <= 5; j++ ) {
        if ( !used[j] ) {
            used[j] = true;
            solve( taken+1 , cur+ara[j] );
            solve( taken+1 , cur-ara[j] );
            solve( taken+1 , cur*ara[j] );
            used[j] = false;
        }
    }
}
int main( int argc, char const *argv[] ) {
    while ( scanf("%d%d%d%d%d",&ara[1],&ara[2],&ara[3],&ara[4],&ara[5]) ) {
        if(ara[1] == 0 && ara[2] == 0 && ara[3] == 0 && ara[4] == 0 && ara[5] == 0) break;
        f = false;
        memset ( used , false, sizeof( used ) );
        for ( int i = 1; i <= 5; i++ ) {
            used[i] = true;
            solve( 1 , ara[i] );
            used[i] = false;
        }
        if ( f ) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
