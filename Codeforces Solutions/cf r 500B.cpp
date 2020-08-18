#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL a[ N ] , x;
int n;
map <LL,int> M;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> x;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i] , M[ a[i] ]++;
                if( M[ a[i] ] >= 2 ) return cout << "0" << endl,0;
        }
        for( int i = 1; i <= n; i++ ) {
                LL cur = (a[i]&x);
                M[a[i]]--;
                if( M[cur] >= 1 ) return cout << 1 << endl,0;
                M[a[i]]++;
        }
        set <LL> S;
        for( int i = 1; i <= n; i++ ) {
                S.insert( (a[i]&x) );
        }
        if( S.size() < n ) cout << 2 << endl;
        else cout << -1 << endl;
        return 0;
}






