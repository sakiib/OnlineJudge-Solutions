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

int n;
int a[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        if( n < 3 ) return cout << "No" << endl,0;
        cout << "Yes" << endl;
        cout << n/2 << " ";
        for( int i = 1 , j = 2; i <= n/2; i++ , j += 2 ) cout << j << " ";
        cout << endl;
        cout << n-n/2 << " ";
        for( int i = 1 , j = 1; i <= n-n/2; i++ , j+= 2 ) cout << j << " ";
        cout << endl;
        return 0;
}






