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

int cnt[ 50 ];
vector <int> pos[ 50 ];

void reset( ) {
    for( int i = 0; i < 30; i++ ) pos[i].clear();
    memset( cnt , 0 , sizeof(cnt) );
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        string str;
        cin >> str;
        reset( );
        for( int i = 0; i < str.size(); i++ ) {
            cnt[ str[i]-'a' ]++;
            pos[ str[i]-'a' ].push_back( i+1 );
        }
        int odd = 0;
        for( int i = 0; i <= 26; i++ ) {
            if( cnt[i]&1 ) odd++;
        }
        if( odd > 1 ) {
            cout << -1 << endl;
            continue;
        }
        string s = "" , ans = "";
        char ch;
        if( (int)str.size()%2 ) {
            for( int i = 0; i <= 26; i++ ) {
                if( cnt[i] >= 2 ) {
                    for( int j = 1; j <= cnt[i]/2; j++ ) s += (i+'a');
                }
                if( cnt[i]&1 ) ch = i+'a';
            }
            string k = s;
            reverse( k.begin() , k.end() );
            s += ch;
            ans = s+k;
        }
        else {
           for( int i = 0; i <= 26; i++ ) {
               if( cnt[i] >= 2 ) {
                 for( int j = 1; j <= cnt[i]/2; j++ ) s += (i+'a');
              }
           }
           string k = s;
           reverse( k.begin() , k.end() );
           ans = s+k;
        }
        for( int i = 0; i < ans.size(); i++ ) {
            int num = ans[i]-'a';
            if( i == 0 ) cout << pos[num][0];
            else cout << " " << pos[num][0];
            pos[num].erase( pos[num].begin(),pos[num].begin()+1 );
        }
        cout << endl;
    }
    return 0;
}

