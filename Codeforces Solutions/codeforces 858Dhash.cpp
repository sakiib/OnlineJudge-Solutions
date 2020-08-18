#include <bits/stdc++.h>
using namespace std;

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


struct Node {
    bool Endmark;
    bool f;
    int ans;
    Node* Next[ 15 ];
    Node( ) {
        Endmark = false;
        ans = 0;
        f = false;
        for( int i = 0; i < 10; i++ ) Next[i] = NULL;
    }
};

Node *Root;

string s[ N ];

void Insert( string str , int idx ) {
    Node* cur = Root;
    int len = str.size( );
    for( int i = 0; i < len; i++ ) {
        int id = str[i]-'0';
        if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
        cur = cur -> Next[id];
    }
    //if( cur -> cnt ) cur -> cnt[idx] = 1 , cur -> ans++;
    cur -> Endmark = true;
}
int Search( string str , int idx ) {
    Node* cur = Root;
    for( int i = 0; i < str.size(); i++ ) {
        int id = str[i]-'0';
        if( cur -> Next[id] == NULL ) return 0;
        cur = cur -> Next[id];
    }
    return cur -> ans;
}

set < string > S;
map < string , int > M;

void calc( string str , int idx ) {
    string temp = str;
    S.clear();
    for( int j = 0; j < temp.size(); j++ ) {
        string res = "";
        for( int k = j; k < temp.size(); k++ ) {
            res += temp[k];
            S.insert( res );
        }
    }
    for( auto x : S ) M[x]++;
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    //Root = new Node( );
    for( int i = 1; i <= n; i++ ) {
        cin >> s[i];
        calc( s[i] , i );
    }
    string ans;
    for( int i = 1; i <= n; i++ ) {
        string str = s[i];
        ans = "";
        for( int j = 0; j < str.size(); j++ ) {
            int mnlen = inf;
            string res = "";
            for( int k = j; k < str.size(); k++ ) {
                res += str[k];
               // cout << res << endl;
                if( M[res] == 1 ) {
                    if( res.size() < mnlen ) {
                        mnlen = res.size();
                        ans = res;
                        //cout << "In  " << ans << endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

