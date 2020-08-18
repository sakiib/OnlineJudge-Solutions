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

vector<string> V[100005];
map<string,int> has;
map<int,string> pep;
map<string,bool> used;

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int id = 0;
    for( int i = 1; i <= n; i++ ) {
        string name,num;
        int k;
        cin >> name;
        if( has[name] == 0 ) {
            has[name] = ++id;
            pep[id]=name;
        }
        cin >> k;
        while( k-- ) {
            cin >> num;
            V[ has[name] ].push_back( num );
        }
    }
    for( int i = 1; i <= id; i++ ) {
        for(int j = 0; j < V[i].size(); j++ ) {
            string t = V[i][j];
            bool f = true;
            for(int k = 0; k <V[i].size() ;k++ ) {
                string n = V[i][k];
                if( n=="XXX" ) continue;
                int lent = t.size();
                int lenn = n.size();
                if(lent == lenn) continue;
                if(j == k) continue;
                if(t.size() > n.size()) continue;
                int pos = lenn-lent;
                if( n.substr(pos,lent) == t ){
                    f=false; break;
                }
            }
            if(!f) V[i][j]="XXX";
        }
    }
    cout<<id<<endl;
    for( int i = 1; i <=id; i++ ) {
        set<string> S;
        for( int j = 0; j < V[i].size(); j++ ) {
            if( V[i][j] != "XXX" ){
                S.insert( V[i][j] );
            }
        }
        cout<< pep[i] <<" "<< (int)(S.size()) <<" ";
        for(auto x : S) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}



