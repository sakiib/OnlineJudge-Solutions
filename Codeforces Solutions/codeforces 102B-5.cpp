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

string str;

void solve( string &s , int cnt ) {
    if( s.size() == 1 ) {
        cout << cnt << endl;
        exit(0);
    }
    LL val = 0;
    for( int i = 0; i < s.size(); i++ ) {
        val += ( s[i]-'0' );
    }
    string temp = "";
    while( val ) {
        temp += ( val%10 )+'0';
        val /= 10;
    }
    reverse( temp.begin() , temp.end() );
    solve( temp , cnt+1 );
}
int main( int argc, char const *argv[] ) {
    cin >> str;
    solve( str , 0 );
    return 0;
}

