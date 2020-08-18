#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<typename T>
using orderset = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update> ;

char s[ 10 ];

int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    while( n-- ) {
       orderset <int> St;
       scanf("%s",s);
       int val;
       if( s[0] == 'I' ) {
         scanf("%d",&val);
         St.insert( val );
       }
       else if( s[0] == 'D' ) {
         scanf("%d",&val);
         St.erase( val );
       }
       else if( s[0] == 'C' ) {
         scanf("%d",&val);
         int ans = St.order_of_key( val );
         printf("%d\n",ans);
       }
       else {
         scanf("%d",&val);
         val--;
         if( St.find_by_order( val ) != St.end( ) ) {
            int ans = *St.find_by_order( val );
            printf("%d\n",ans);
         }
         else printf("invalid\n");
       }
    }
    return 0;
}

