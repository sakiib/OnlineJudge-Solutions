#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int a1 , b1 , c1;
                scannf("%d %d %d",&a1,&b1,&c1);
                int a2 , b2 , c2;
                scannf("%d %d %d",&a2,&b2,&c2);
                int f0 , f1 , f2;
                scannf("%d %d %d",&f0,&f1,&f2);
                int g0 , g1 , g2;
                scannf("%d %d %d",&g0,&g1,&g2);
        }
        return 0;
}








