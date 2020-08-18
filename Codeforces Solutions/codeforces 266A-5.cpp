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
    int n , t;
    cin >> n >> t;
    string str;
    cin >> str;
    int i = 0;
    while( t-- ) {
        for( i = 0; i < str.size()-1;  ) {
            if( str[i] == 'B' && str[i+1] == 'G' ) swap( str[i],str[i+1]), i++;
            i++;
        }
    }
    cout << str << endl;
    return 0;
}

