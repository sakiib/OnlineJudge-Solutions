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

LL a[ N ];
int n;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        a[n+1] = INF;
        if( n == 1 ) return cout << 1 << endl,0;
        int mx = 1 , i = 1;
        while( i < n ) {
                int k = i;
                for( int j = i+1; j <= n && k < n; j++ ) {
                        if( 2*a[k] >= a[j] ) {
                                cout << "in : " << i << " " << j << " " << k << endl;
                                mx = max( mx , j-i+1 );
                                k++;
                        }
                        else {
                                cout << "Out : " << i << " " << j << " " << k << endl;
                                //return 0;
                                i = j;
                                break;
                        }
                }
                //cout << i << endl;
        }
        cout << mx << endl;
        return 0;
}






