//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	int m, b; cin>>m>>b;
	ll Max = 0;
	for(int y = 0; y <= b; y++) {
		ll x = m * (b - y);
		Max = max(Max, y * (y+1)/2 * (x+1) + x * (x+1)/2 * (y+1));
	} cout<<Max<<endl;
}
