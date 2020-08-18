#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
LL n, l, r;
LL h;
int main(){
	cin >> n >> l >> r;
	h = __lg(n);
	LL cnt = 0;
	for(LL i = l; i <= r; i ++){
		cnt += n >> h - __lg(i&(-i)) & 1;
	}
	cout << cnt << endl;
}
