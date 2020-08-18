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

const int Base1 = 31;
const int Base2 = 53;
const LL Mod = MOD;
char str[ 2*N ] , a[ 30 ];
int bad;
int B[ 2*N ] = {0};

int main( int argc, char const *argv[] ) {
    scanf("%s %s %d",str,a,&bad);
    for( int i = 0; i < strlen( a ); i++ ) if( a[i] == '0' ) B[i] = 1;
    int len = strlen( str );
    set < pair<LL,LL> > S;
    for( int i = 0; i < len; i++ ) {
        LL Hash1 = 0 , Hash2 = 0 , b = 0;
        for( int j = i; j < len; j++ ) {
            if( B[ str[j]-'a'] == 1 ) b++;
            if( b > bad ) break;
            Hash1 = Hash1*Base1+str[j];
            Hash1 %= Mod;
            Hash2 = Hash2*Base2+str[j];
            Hash2 %= Mod;
            S.insert( {Hash1,Hash2} );
        }
    }
    printf("%lld\n",(LL)(S.size()));
    return 0;
}

