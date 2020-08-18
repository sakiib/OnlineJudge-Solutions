#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5+5;
LL ara[ N ];
map <LL,bool> used;
vector <LL> ans;

int main(int argc, char const *argv[]) {
    LL n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        used[ ara[i] ] = true;
    }
    for( LL i = 1; ; i++ ) {
       if(m < i) break;
       if(!used[i]) {
        ans.push_back(i);
        m -= i;
       }
    }
    cout << (int)ans.size() <<endl;
    for(auto x: ans) cout << x <<" ";
    return 0;
}
