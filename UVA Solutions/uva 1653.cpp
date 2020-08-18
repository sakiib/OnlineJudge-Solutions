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

int n , m;
bool bad[ 10 ];
int cost[ 10005 ];

struct data {
        string res;
        int mod;
        data () {}
        data( string res , int mod ) : res(res) , mod(mod){}
};
string bfs( ) {
        queue <data> Q;
        memset( cost , -1 , sizeof( cost ) );
        for( int i = 1; i <= 9; i++ ) {
                if( bad[i] ) continue;
                string s = "";
                s += ( i + '0' );
                cost[i%n] = 0;
                Q.push( data( s , i%n ) );
        }
        while( !Q.empty() ) {
                data f = Q.front(); Q.pop();
                string cur_ans = f.res;
                int cur_mod = f.mod;
                if( cur_mod == 0 && cur_ans.size() > 0 ) return cur_ans;
                for( int i = 0; i <= 9; i++ ) {
                        if( bad[i] ) continue;
                        int mod = ( cur_mod%n * 10%n + i%n )%n;
                        if( cost[mod] == -1 || cost[mod] > cost[cur_mod] + 1 ) {
                                cost[mod] = cost[cur_mod] + 1;
                                string temp = cur_ans; temp += ( i + '0' );
                                Q.push( data( temp , mod ) );
                        }
                }
        }
        return "-1";
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
            freopen( "output.txt" , "w" , stdout );
        #endif // LOCAL
        int tc = 0;
        while( cin >> n ) {
                if( n == 0 ) break;
                cin >> m;
                memset( bad , false , sizeof( bad ) );
                for( int i = 1; i <= m; i++ ) {
                        int x;
                        cin >> x;
                        bad[x] = true;
                }
                cout << "Case " << ++tc << ": " << bfs() << endl;
        }
        return 0;
}








