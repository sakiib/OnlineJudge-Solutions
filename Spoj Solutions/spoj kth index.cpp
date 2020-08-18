#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
    const char* c = strchr(na + 1, ',');
    cerr.write(na, c - na) << " : " << arg1 << " , ";
    __f(c + 1, args...);
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
typedef pair <int,int> pii;
typedef long long LL;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
const long long INF = 1e18;
const int N = 1e5 + 5;
//----------------------------------------------------------

bool ok(int num, int len) {

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    for (int i = 10; i <= 99; i++) {
        if (ok(i, 2)) cout << i << endl;
    }
    return 0;
}




