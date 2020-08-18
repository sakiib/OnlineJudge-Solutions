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
    string str;
    cin >> str;
    bool f = true;

    for( int i = 0; i < str.size(); i++ ) {
        if( str[0] != '1' ) f = false;
        if( str.find("444") != string::npos ) f = false;
        if( str[i] != '1' && str[i] !='4' ) f = false;
    }
    if( f ) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}

