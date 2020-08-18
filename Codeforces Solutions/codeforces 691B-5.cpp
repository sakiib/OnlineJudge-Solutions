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

map <char,char> M;

void calc( ) {
    M[ 'A' ] = 'A' , M[ 'H' ] = 'H' , M[ 'I' ] = 'I';
    M[ 'M' ] = 'M' , M[ 'O' ] = 'O' , M[ 'S' ] = 'S';
    M[ 'T' ] = 'T' , M[ 'U' ] = 'U' , M[ 'V' ] = 'V';
    M[ 'W' ] = 'W' , M[ 'X' ] = 'X' , M[ 'Y' ] = 'Y';
    M[ 'Z' ] = 'Z';

    M[ 'b' ] = 'd' , M[ 'd' ] = 'b' , M[ 'i' ] = 'i';
    M[ 'l' ] = 'l' , M[ 'm' ] = 'm' , M[ 'n' ] = 'n';
    M[ 'o' ] = 'o' , M[ 'p' ] = 'q' , M[ 's' ] = 's';
    M[ 'u' ] = 'u' , M[ 'v' ] = 'v' , M[ 'w' ] = 'w';
    M[ 'x' ] = 'x' , M[ 'y' ] = 'y' , M[ 'z' ] = 'z';
}
int main( int argc, char const *argv[] ) {
    calc( );
    string str;
    cin >> str;
    int len = str.size();
    for( int i = 0; i < len/2; i++ ) {

    }
    return 0;
}

