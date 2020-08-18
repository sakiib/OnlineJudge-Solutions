#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Node {
        int endMark;
        Node *Next[ 53 ];
        Node( ) {
                endMark = 0;
                for( int i = 1; i <= 52; i++ ) Next[i] = NULL;
        }
} *root;

void Delete( Node* cur ) {
        for( int i = 1; i <= 52; i++ ) {
                if( cur -> Next[i] ) Delete( cur -> Next[i] );
        }
        delete( cur );
}
int GetID( char ch ) {
        if( ch >= 'a' && ch <= 'z' ) return ch - 'a' + 1;
        return ch - 'A' + 27;
}
void Insert( string s ) {
        Node *cur = root;
        int len = s.size();
        for( int i = 0; i < len; i++ ) {
                int id = GetID( s[i] );
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
                cur = cur -> Next[id];
        }
        cur -> endMark++;
}
int Find( string s ) {
        Node *cur = root;
        int len = s.size();
        for( int i = 0; i < len; i++ ) {
                int id = GetID( s[i] );
                if( cur -> Next[id] == NULL ) return 0;
                cur = cur -> Next[id];
        }
        return cur -> endMark;
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                root = new Node( );
                int n;
                cin >> n;
                for( int i = 1; i <= n; i++ ) {
                        string s;
                        cin >> s;
                        if( s.size() > 3 ) sort( s.begin()+1 , s.end()-1);
                        Insert( s );
                }
                cout << "Case " << tc << ":" << endl;
                int q;
                cin >> q;
                cin.ignore( );
                while( q-- ) {
                        string s;
                        getline( cin , s );
                        stringstream iss( s );
                        string temp;
                        vector <string> V;
                        while( iss >> temp ) {
                                if( temp.size() > 3 ) sort( temp.begin()+1 , temp.end()-1 );
                                V.push_back( temp );
                        }
                        LL ans = 1;
                        for( auto x : V ) ans *= Find( x );
                        cout << ans << endl;
                }
                Delete( root );
        }
        return 0;
}










