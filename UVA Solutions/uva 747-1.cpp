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
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

const int stan = 1;
const int ollie = 2;

LL lim;
map <LL,int> M[5];

int ok( LL cur , int who_moved ) {
        if( cur >= lim ) return who_moved;
        int now_moving = ( who_moved == stan ? ollie : stan );
        if( M[who_moved][cur] != 0 ) return M[who_moved][cur];
        int lose = who_moved;
        for( int i = 2; i <= 9; i++ ) {
                int now = ok( cur * i , now_moving );
                if( now == now_moving ) return M[who_moved][cur] = now;
        }
        return M[who_moved][cur] = lose;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        while( cin >> lim ) {
                bool st = false;
                for( int i = 1; i <= 2; i++ ) M[i].clear();
                for( int i = 2; i <= 9; i++ ) {
                        int who = ok( i , stan );
                        st |= ( who == stan );
                }
                cout << ( st ? "Stan wins." : "Ollie wins." ) << endl;
        }
        return 0;
}








