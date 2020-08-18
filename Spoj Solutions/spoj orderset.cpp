#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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


typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update> PBDS;

char s[ 10 ];

int main( int argc, char const *argv[] ) {
    PBDS S;
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
       int val;
       scanf("%s %d",s,&val);
       if( s[0] == 'I' ) S.insert( val );
       else if( s[0] == 'D' ) S.erase( val );
       else if( s[0] == 'K' ) {
         if( S.size() < val ) printf("invalid\n");
         else printf("%d\n",*S.find_by_order( val-1 ) );
       }
       else printf("%d\n",S.order_of_key( val ));
    }
    return 0;
}

