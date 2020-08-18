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

int main( int argc, char const *argv[] ) {
    string s;
    cin >> s;
    int i = 0;
    int a = 0 , b = 0 , c = 0;
    while( i < s.size() && s[i] == 'a' ) a++ , i++;
    while( i < s.size() && s[i] == 'b' ) b++ , i++;
    while( i < s.size() && s[i] == 'c' ) c++ , i++;
    if( i != s.size() ) return printf("NO\n"),0;
    if( a == 0 || b == 0 ) return printf("NO\n"),0;
    if( c == a || c == b ) printf("YES\n");
    else printf("NO\n");
    return 0;
}

