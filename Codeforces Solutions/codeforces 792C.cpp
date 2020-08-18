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

int main( int argc, char const *argv[] ) {
    string str;
    cin >> str;
    string temp = str;
    for( int i = 0; i < temp.size(); i++ ) {
        int x = temp[i]-'0';
        x %= 3;
        temp[i] = x+'0';
    }
    int l = 0 , r = 0 , st = 0 , en = 0;
    int mx = 0;
    for( int i = 0; i < temp.size(); ) {
        if( str[i] == '0' ) {
            l = i;
            r = i;
            while( temp[i] == '0' ) {
                i++ , r++;
            }
            if( r-l+1 > mx ) {
                mx = r-l+1;
                st = l;
                en = r;
            }
        }
        i++;
    }
    string res = "";
    for( int i = st; i <= en; i++ ) {
        res += str[i];
    }
    --en;
    cout << res <<" "<< st << " "<<en <<endl;
    bool f = false;
    for( int i = st; i <= en; i++ ) {
        if( res[i] != '0' ) {
            cout <<"now : "<<res[i]<<endl;
            f = true;
            break;
        }
    }
    if( !f ) {
        cout <<"here"<<endl;
        cout << 0 <<endl;
        return 0;
    }
    int idx = 0;
    if( res[idx] == '0' && res.size() ) {
        while( res[++idx] == '0' ) idx++;
    }
    for( int i = idx; i < res.size(); i++ ) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}

