#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;

LL ara[ N ];
LL A[ N ] = {0};
LL add[ N ] = {0};
struct query {
    LL l , r, val;
} Q[ N ];

int main( int argc , char const *argv[] ) {
   LL n , m ,k;
   cin >> n >> m >>k;
   for( int i = 1; i <= n; i++ ) {
       cin >> ara[i];
   }
   for( int i = 1; i <= m; i++ ) {
       cin >> Q[i].l >> Q[i].r >> Q[i].val;
   }
   for( int i = 1; i <= k; i++ ) {
       LL u , v;
       cin >> u >> v;
       A[ v+1 ] --;
       A[ u ] ++;
   }
   for( int i = 1; i <= N; i++ ) {
       A[i] += A[i-1];
   }
   for( int i = 1; i <= m; i++ ) {
       add[ Q[i].r+1 ] -= (Q[i].val * A[i]);
       add[ Q[i].l ] += (Q[i].val * A[i]);
   }
   for( int i = 1; i <= N; i++ ) {
       add[i] += add[i-1];
   }
   for( int i = 1; i <= n; i++ ) {
       cout << ara[i]+add[i] <<" ";
   }
   cout << endl;
   return 0;
}
