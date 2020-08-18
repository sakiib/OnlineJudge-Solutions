#include <bits/stdc++.h>
using namespace std;

typedef long  long LL;
const int N = 2*100005;
int n , k;
LL ans;

struct item {
    int age , pore;
    item(){}
    item( int age , int pore ) : age(age) , pore(pore){}
    bool operator <( const item &q ) const {
        return ( (age-pore) < (q.age-q.pore) );
    }
} a[ 2*N ];

int main( int argc , char const *argv[] ) {
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i].age;
        for( int i = 1; i <= n; i++ ) cin >> a[i].pore;
        sort( a+1, a+n+1 );
        for( int i = 1; i <= n; i++ ) {
                if( i <= k ) ans += a[i].age;
                else ans += min( a[i].age , a[i].pore );
        }
        cout << ans << endl;
        return 0;
}
