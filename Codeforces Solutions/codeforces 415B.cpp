#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector <LL> V;

int main(int argc, char const *argv[]) {
    LL n , a , b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n ; i++) {
        LL val;
        cin >> val;
        LL rem = ((val%b*a%b)%b)/a;
        V.push_back(rem);
    }
    for(auto x: V) cout << x << " ";
    cout<<endl;
    return 0;
}
