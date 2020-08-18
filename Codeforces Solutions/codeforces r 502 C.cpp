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

int len , m , q;
int cost[ 5*N ];

struct node {
        bool endmark;
        int cnt;
        node* child[2];
        node( ) {
                endmark = false;
                cnt = 0;
                child[0] = nullptr , child[1] = nullptr;
        }
} *root;

void add( string s ) {
        node* cur = root;
        for( int i = 0; i < len; i++ ) {
                int id = s[i] - '0';
                if( cur -> child[id] == nullptr ) {
                        cur -> child[id] = new node();
                }
                cur = cur -> child[id];
                cur -> cnt++;
        }
        cur -> endmark = true;
}
int getAns( node* cur , int pos , string s , int rem ) {
        if( rem < 0 ) return 0;
        if( cur -> endmark ) return cur -> cnt;
        int ret = 0;
        int id = s[pos]-'0';
        if( cur -> child[id] != nullptr ) {
                ret += getAns( cur -> child[id] , pos+1 , s , rem-cost[pos+1] );
        }
        if( cur -> child[id^1] != nullptr ) {
                ret += getAns( cur -> child[id^1] , pos+1 , s , rem );
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        root = new node();
        cin >> len >> m >> q;
        for( int i = 1; i <= len; i++ ) cin >> cost[i];
        for( int i = 1; i <= m; i++ ) {
                string s;
                cin >> s;
                add( s );
        }
        while( q-- ) {
                int taka;
                string s;
                cin >> s >> taka;
                cout << getAns( root , 0 , s , taka ) << endl;
        }
        return 0;
}






