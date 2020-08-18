#include <bits/stdc++.h>
using namespace std;

int r , c;
string str[ 1005 ];
set < int > S;

int main( int argc , char const *argv[] ) {
    scanf("%d%d",&r,&c);
    for ( int i = 0; i < r; i++ ) {
        cin >> str[i];
        int dpos = str[ i ].find( 'S' );
        int cpos = str[ i ].find( 'G' );
        if ( cpos > dpos ) {
            puts("-1");
            return 0;
        }
        S.insert( dpos-cpos );
    }
    printf("%d\n",(int)(S.size()));
    return 0;
}
