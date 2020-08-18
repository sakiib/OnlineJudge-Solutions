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

int n;
vector <LL> A , B;
LL w , a[ 50 ];

void mnm( int l , int r , LL sum , int f ) {
        if( l > r ) {
                if( f ) B.push_back( sum );
                else A.push_back( sum );
                return;
        }
        mnm( l + 1 , r , sum , f );
        mnm( l + 1 , r , sum + a[l] , f );
}
int getcnt( LL x ) {
        int lo = 0 , hi = B.size() - 1 , ret = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( B[mid] <= x ) {
                        ret = mid + 1, lo = mid + 1;
                }
                else {
                        hi = mid - 1;
                }
        }
        return ret;
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %lld",&n,&w);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%lld",&a[i]);
                }
                A.clear();
                B.clear();
                mnm( 1 , n/2 , 0 , 0 );
                mnm( n/2 + 1 , n , 0 , 1 );
                sort( A.begin() , A.end() );
                sort( B.begin() , B.end() );
                LL ans = 0;
                for( int i = 0; i < A.size(); i++ ) {
                        LL atmost = w - A[i];
                        ans += getcnt( atmost );
                }
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}









