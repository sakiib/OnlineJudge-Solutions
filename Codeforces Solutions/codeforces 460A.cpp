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

map <char,int> M;

int main( int argc, char const *argv[] ) {
    string str;
    cin >> str;
    int n;
    cin >> n;
    if( str.size() < n ) {
        cout <<"impossible"<<endl;
        return 0;
    }
    set <char> S;
    for( auto x : str ) {
        M[x]++;
        S.insert( x );
    }
    if( (int)(S.size() >= n ) ) {
        cout <<0 <<endl;
        return 0;
    }
    int k = (int)S.size();
    int cnt = 0;
    for( auto x : str ) {
        if( M[x] > 1 ) {
            M[x]--;
            k++;
            cnt++;
        }
        if( k == n ) break;
    }
    if( k == n ) cout <<cnt <<endl;
    else cout << "impossible" <<endl;
    return 0;
}

